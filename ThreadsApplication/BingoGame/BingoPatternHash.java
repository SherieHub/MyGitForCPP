package ThreadsApplication.BingoGame;

class BingoPatternHash extends BingoPattern {
    public BingoPatternHash(BingoCard card, int cardId) {
        super(card, cardId);
        for (int i = 1; i < 4; i++) {
            checkers.add(new Thread(new BingoRowChecker(card, 1, cardId)));
            checkers.add(new Thread(new BingoRowChecker(card, 3, cardId)));
            checkers.add(new Thread(new BingoColumnChecker(card, 1, cardId)));
            checkers.add(new Thread(new BingoColumnChecker(card, 3, cardId)));
        }
    }
}
