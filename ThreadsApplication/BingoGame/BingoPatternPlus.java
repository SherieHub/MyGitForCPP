package ThreadsApplication.BingoGame;

class BingoPatternPlus extends BingoPattern {
    public BingoPatternPlus(BingoCard card, int cardId) {
        super(card, cardId);
        for (int i = 0; i < 5; i++) {
            checkers.add(new Thread(new BingoRowChecker(card, 2, cardId)));
            checkers.add(new Thread(new BingoColumnChecker(card, 2, cardId)));
        }
    }
}


