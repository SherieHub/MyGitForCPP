package Bingo_Game;
import java.util.*;

public class BingoRowChecker extends BingoChecker {
    private final int row;

    public BingoRowChecker(BingoCard card, BingoGame game, int row) {
        super(card, game);
        this.row = row;
    }

    @Override
    public void run() {
        try {
            for (int num : card.getCard()[row]) {
                if (num != 0) {
                    synchronized (game) {
                        while (!game.isNumberChosen(num) && !game.isBingo()) {
                            try {
                                game.wait();
                            } catch (InterruptedException e) {
                                System.out.println("Interrupted while waiting for number: " + num);
                                return;
                            }
                        }
                    }
                }
            }
        } catch (Exception e) {
            System.err.println("Unexpected error in BingoRowChecker: " + e.getMessage());
        }
    }
}
