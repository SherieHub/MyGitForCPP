import java.util.*;

class BingoPatternPlus extends BingoPattern {
    public BingoPatternPlus(BingoCard card, BingoGame game) {
        super(card, game);
        checkers.add(new Thread(new BingoRowChecker(card, 2, game)));
        checkers.add(new Thread(new BingoColumnChecker(card, 2, game)));
    }
}
