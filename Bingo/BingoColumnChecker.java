import java.util.*;

class BingoColumnChecker extends BingoChecker {
    private final int col;

    public BingoColumnChecker(BingoCard card, int col, BingoGame game) {
        super(card, game);
        this.col = col;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            int num = card.getCard()[i][col];
            if (num != 0) {
                synchronized (game) {
                    while (!game.isNumberDrawn(num) && !game.isBingo()) {
                        try {
                            game.wait();
                        } catch (InterruptedException e) {
                            return;
                        }
                    }
                }
            }
        }
    }
}
