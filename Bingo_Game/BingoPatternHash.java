package Bingo_Game;
import java.util.*;

class BingoPatternHash extends BingoPattern {
    public BingoPatternHash(BingoCard card, BingoGame game) {
        super(game, card);
        checkers.add(new Thread(new BingoRowChecker(card, game, 2)));
        checkers.add(new Thread(new BingoColumnChecker(card, game, 2)));
    }
}
