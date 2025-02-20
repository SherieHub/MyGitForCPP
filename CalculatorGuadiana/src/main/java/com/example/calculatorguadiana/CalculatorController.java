package com.example.calculatorguadiana;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class CalculatorController {
    @FXML private Pane btnPoint, btnBack;
    @FXML private Pane titlePane;
    @FXML private ImageView btnMinimize, btnClose;
    @FXML private Label lblResult;

    private StringBuilder expression = new StringBuilder();
    private boolean isResultDisplayed = false;
    private double lastResult = 0;

    public void init(Stage stage) {
        titlePane.setOnMousePressed(mouseEvent -> {
            double x = mouseEvent.getSceneX();
            double y = mouseEvent.getSceneY();
            titlePane.setOnMouseDragged(dragEvent -> {
                stage.setX(dragEvent.getScreenX() - x);
                stage.setY(dragEvent.getScreenY() - y);
            });
        });

        btnClose.setOnMouseClicked(mouseEvent -> stage.close());
        btnMinimize.setOnMouseClicked(mouseEvent -> stage.setIconified(true));
    }

    @FXML
    void onNumberClicked(MouseEvent event) {
        String value = ((Pane) event.getSource()).getId().replace("btn", "");

        if (isResultDisplayed) {
            expression.setLength(0);
            isResultDisplayed = false;
        }

        if (expression.length() == 1 && expression.charAt(0) == '0') {
            expression.setLength(0);
        }

        expression.append(value);
        lblResult.setText(expression.toString());
    }

    @FXML
    void onSymbolClicked(MouseEvent event) {
        String symbol = ((Pane) event.getSource()).getId().replace("btn", "");

        if (symbol.equals("Equals")) {
            try {
                lastResult = evaluateExpression(expression.toString());
                String formattedResult = formatResult(lastResult);
                lblResult.setText(formattedResult);

                expression.setLength(0);
                expression.append(formattedResult);

                isResultDisplayed = true;
            } catch (Exception e) {
                lblResult.setText("Error");
                expression.setLength(0);
            }
        } else if (symbol.equals("Clear")) {
            expression.setLength(0);
            lblResult.setText("0");
            lastResult = 0;
            isResultDisplayed = false;
        } else {
            if (isResultDisplayed) {
                isResultDisplayed = false;
                expression.setLength(0);
                expression.append(formatResult(lastResult));
            }

            switch (symbol) {
                case "Plus" -> expression.append(" + ");
                case "Minus" -> expression.append(" - ");
                case "Multiply" -> expression.append(" * ");
                case "Divide" -> expression.append(" / ");
            }

            lblResult.setText(expression.toString());
        }
    }

    private double evaluateExpression(String expr) {
        String[] tokens = expr.split(" ");
        double result = Double.parseDouble(tokens[0]);

        for (int i = 1; i < tokens.length; i += 2) {
            String op = tokens[i];
            double num = Double.parseDouble(tokens[i + 1]);

            switch (op) {
                case "+" -> result += num;
                case "-" -> result -= num;
                case "*" -> result *= num;
                case "/" -> result /= num;
            }
        }

        return result;
    }

    private String formatResult(double number) {
        return (number % 1 == 0) ? String.valueOf((int) number) : String.valueOf(number);
    }
}
