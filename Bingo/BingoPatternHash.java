import java.util.*;

class BingoPatternHash extends BingoPattern {
    public BingoPatternHash(BingoCard card, BingoGame game) {
        super(card, game);
        checkers.add(new Thread(new BingoRowChecker(card, 1, game)));
        checkers.add(new Thread(new BingoRowChecker(card, 3, game)));
        checkers.add(new Thread(new BingoColumnChecker(card, 1, game)));
        checkers.add(new Thread(new BingoColumnChecker(card, 3, game)));
    }
}
