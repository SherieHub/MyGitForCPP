package ThreadsApplication.BingoGame;
import java.util.*;

abstract class BingoPattern implements Runnable {
    protected BingoCard card;
    protected int cardId;
    protected BingoGame game;
    protected List<Thread> checkers;

    public BingoPattern(BingoCard card, int cardId, BingoGame game) {
        this.card = card;
        this.cardId = cardId;
        this.game = game;
        this.checkers = new ArrayList<>();
    }

    public void run() {
        for (Thread checker : checkers) {
            checker.start();
        }

        for (Thread checker : checkers) {
            try {
                checker.join();
            } catch (InterruptedException e) {
                System.out.println("Card " + cardId + " loses.");
                return;
            }
        }

        // Declare bingo if the pattern is completed
        if (!game.isBingo()) {
            game.declareBingo();
            System.out.println("Card " + cardId + " completes pattern!");
            System.out.println(card);
        }
    }
}

