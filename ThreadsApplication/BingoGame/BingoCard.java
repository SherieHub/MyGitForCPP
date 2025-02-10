package ThreadsApplication.BingoGame;

import java.util.*;

import java.util.*;

class BingoCard {
    private int[][] card;
    private boolean[][] marked;
    private static final int SIZE = 5;

    public BingoCard() {
        generateCard();
    }

    private void generateCard() {
        card = new int[SIZE][SIZE];
        marked = new boolean[SIZE][SIZE];
        Random rand = new Random();

        for (int col = 0; col < SIZE; col++) {
            Set<Integer> usedNumbers = new HashSet<>();
            int min = col * 15 + 1;
            int max = min + 14;
            for (int row = 0; row < SIZE; row++) {
                if (row == 2 && col == 2) {
                    card[row][col] = 0; // Free space
                    marked[row][col] = true;
                } else {
                    int num;
                    do {
                        num = rand.nextInt(max - min + 1) + min;
                    } while (usedNumbers.contains(num));
                    usedNumbers.add(num);
                    card[row][col] = num;
                }
            }
        }
    }

    public void markNumber(int number) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (card[row][col] == number) {
                    marked[row][col] = true;
                }
            }
        }
    }

    public boolean isMarked(int row, int col) {
        return marked[row][col];
    }

    public int[][] getCard() {
        return card;
    }
}

