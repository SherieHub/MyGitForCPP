import java.util.*;

class BingoRowChecker extends BingoChecker {
    private final int row;

    public BingoRowChecker(BingoCard card, int row, BingoGame game) {
        super(card, game);
        this.row = row;
    }

    public void run() {
        for (int num : card.getCard()[row]) {
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
