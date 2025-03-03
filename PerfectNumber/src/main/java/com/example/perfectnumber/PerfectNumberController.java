package com.example.perfectnumber;

import javafx.application.Platform;
import javafx.concurrent.Task;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;

import java.util.ArrayList;
import java.util.List;

public class PerfectNumberController {
    @FXML private TextField numInput;
    @FXML private TextField threadInput;
    @FXML private TextArea resultArea;
    @FXML private HBox progressBox;
    @FXML private Button backButton;

    private List<ProgressIndicator> progressIndicators = new ArrayList<>();

    @FXML
    private void initialize() {
        backButton.setVisible(false);
    }

    @FXML
    private void startFindingPerfectNumbers() {
        resultArea.clear();
        progressBox.getChildren().clear();
        progressIndicators.clear();
        backButton.setVisible(false);

        try {
            int num = Integer.parseInt(numInput.getText());
            int threadCount = Integer.parseInt(threadInput.getText());

            if (num <= 0 || threadCount <= 0) {
                resultArea.setText("Error: Numbers must be positive.");
                return;
            }

            List<Task<Void>> tasks = new ArrayList<>();
            List<Thread> threads = new ArrayList<>();
            int start = 1;
            int remainingTasks = num;

            for (int i = 0; i < threadCount; i++) {
                int chunkSize = remainingTasks / (threadCount - i);
                int end = start + chunkSize - 1;
                remainingTasks -= chunkSize;

                ProgressIndicator progressIndicator = new ProgressIndicator(0);
                progressIndicators.add(progressIndicator);
                progressBox.getChildren().add(progressIndicator);

                Task<Void> task = createPerfectNumberTask(start, end, progressIndicator);
                tasks.add(task);

                Thread thread = new Thread(task);
                threads.add(thread);
                thread.start();

                start = end + 1;
            }

            for (Thread thread : threads) {
                thread.join();
            }

            int totalPerfect = 0, totalDeficient = 0, totalAbundant = 0;
            for (Task<Void> task : tasks) {
                totalPerfect += ((PerfectNumberTask)task).getPerfectCount();
                if (task.getMessage() != null && !task.getMessage().isEmpty()) {
                    String[] counts = task.getMessage().split(",");
                    if (counts.length == 2) {
                        try {
                            totalDeficient += Integer.parseInt(counts[0]);
                            totalAbundant += Integer.parseInt(counts[1]);
                        } catch (NumberFormatException e) {
                            System.err.println("Error parsing counts: " + e.getMessage());
                        }
                    }
                }
            }
            resultArea.appendText("\nTotal: " + totalPerfect + " perfect, " + totalDeficient + " deficient, " + totalAbundant + " abundant.\n");
            backButton.setVisible(true);

        } catch (NumberFormatException e) {
            resultArea.setText("Error: Invalid input. Please enter valid numbers.");
        } catch (InterruptedException e) {
            resultArea.setText("Error: Thread interrupted.");
        }
    }

    @FXML
    private void resetUI() {
        numInput.clear();
        threadInput.clear();
        resultArea.clear();
        progressBox.getChildren().clear();
        progressIndicators.clear();
        backButton.setVisible(false);
    }

    private Task<Void> createPerfectNumberTask(int start, int end, ProgressIndicator progressIndicator) {
        return new PerfectNumberTask(start, end, progressIndicator);
    }

    private int sumOfDivisors(int num) {
        if (num <= 1) {
            return 0;
        }
        int sum = 1;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }
        return sum;
    }

    private class PerfectNumberTask extends Task<Void> {
        private int perfectCount = 0;
        private final int start;
        private final int end;
        private final ProgressIndicator progressIndicator;

        public PerfectNumberTask(int start, int end, ProgressIndicator progressIndicator) {
            this.start = start;
            this.end = end;
            this.progressIndicator = progressIndicator;
        }

        @Override
        protected Void call() {
            int deficientCount = 0, abundantCount = 0;
            StringBuilder result = new StringBuilder();
            int totalNumbers = end - start + 1;
            int processedNumbers = 0;

            for (int i = start; i <= end; i++) {
                int sum = sumOfDivisors(i);
                if (sum == i) {
                    result.append(i).append(" is PERFECT\n");
                    perfectCount++;
                } else if (sum < i) {
                    deficientCount++;
                } else {
                    abundantCount++;
                }
                processedNumbers++;
                double progress = (double) processedNumbers / totalNumbers;
                updateProgress(progress, 1.0); // Update with percentage and max = 1.0
            }

            updateMessage(deficientCount + "," + abundantCount);

            int finalPerfectCount = perfectCount;
            int finalDeficientCount = deficientCount;
            int finalAbundantCount = abundantCount;
            Platform.runLater(() -> {
                resultArea.appendText(result.toString());
                resultArea.appendText("\nThread [" + start + "-" + end + "] -> "
                        + finalPerfectCount + " perfect, "
                        + finalDeficientCount + " deficient, "
                        + finalAbundantCount + " abundant.\n");
                progressIndicator.setProgress(1.0);
            });
            return null;
        }

        public int getPerfectCount() {
            return perfectCount;
        }
    }
}