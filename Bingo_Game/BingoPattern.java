package Bingo_Game;
import java.util.*;

abstract class BingoPattern implements Runnable {
    final List<Thread> checkers = new ArrayList<>();
    final BingoGame game;
    final BingoCard card;

    public BingoPattern(BingoGame game, BingoCard card){
        this.game = game;
        this.card = card;
    }

    public void run() {
        boolean printedResult = false;

        try {
            for (int i = 0; i < 5; i++) {
                Thread rowChecker = new Thread(new BingoRowChecker(card, game, i));
                Thread colChecker = new Thread(new BingoColumnChecker(card, game, i));

                checkers.add(rowChecker);
                checkers.add(colChecker);

                rowChecker.start();
                colChecker.start();
            }

            for (Thread checker : checkers) {
                try {
                    checker.join();
                } catch (InterruptedException e) {
                    if (!printedResult) {
                        System.out.println("Card " + card.getId() + " loses");
                        printedResult = true;
                    }
                    return;
                }
            }

            synchronized (game) {
                if (!game.isBingo()) {
                    game.setBingo(true);
                    System.out.println("Card " + card.getId() + " completes pattern!\n" + card);
                    printedResult = true;
                }
            }
        } finally {
            if (!printedResult) {
                System.out.println("Card " + card.getId() + " loses");
            }
        }
    }
}

