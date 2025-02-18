package Bingo_Game;
import java.util.*;

public class BingoColumnChecker extends BingoChecker{
    private final int col;

    public BingoColumnChecker(BingoCard card, BingoGame game, int col) {
        super(card, game);
        this.col = col;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 5; i++) {
                int num = card.getCard()[i][col];
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
            System.err.println("Unexpected error in BingoColumnChecker: " + e.getMessage());
        }
    }
}
