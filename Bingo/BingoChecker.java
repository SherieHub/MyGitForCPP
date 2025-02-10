import java.util.*;

abstract class BingoChecker implements Runnable {
    protected final BingoCard card;
    protected final BingoGame game;

    public BingoChecker(BingoCard card, BingoGame game) {
        this.card = card;
        this.game = game;
    }
}
