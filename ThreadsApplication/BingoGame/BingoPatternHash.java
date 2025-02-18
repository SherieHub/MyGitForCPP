package ThreadsApplication.BingoGame;

class BingoPatternHash extends BingoPattern {
    public BingoPatternHash(BingoCard card, int cardId, BingoGame game) {
        super(card, cardId, game);
        for (int i = 1; i < 4; i++) {
            checkers.add(new Thread(new BingoRowChecker(card, 1, cardId, game)));
            checkers.add(new Thread(new BingoRowChecker(card, 3, cardId, game)));
            checkers.add(new Thread(new BingoColumnChecker(card, 1, cardId, game)));
            checkers.add(new Thread(new BingoColumnChecker(card, 3, cardId, game)));
        }
    }
}
