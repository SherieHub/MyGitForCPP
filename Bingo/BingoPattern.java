import java.util.*;

abstract class BingoPattern implements Runnable {
    protected final BingoCard card;
    protected final List<Thread> checkers = new ArrayList<>();
    protected final BingoGame game;

    public BingoPattern(BingoCard card, BingoGame game) {
        this.card = card;
        this.game = game;
    }

    public void run() {
        for (Thread checker : checkers) {
            checker.start();
        }

        for (Thread checker : checkers) {
            try {
                checker.join();
            } catch (InterruptedException e) {
                System.out.println("Card " + card.getId() + " interrupted");
                return;
            }
        }

        if (!game.isBingo()) {
            game.setBingo(true);
            System.out.println("Card " + card.getId() + " completes pattern!\n" + card);
        }
    }
}
