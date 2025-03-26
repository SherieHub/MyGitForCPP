package ThreadsApplication.BingoGame;

class BingoPatternPlus extends BingoPattern {
    public BingoPatternPlus(BingoCard card, int cardId, BingoGame game) {
        super(card, cardId, game);
        for (int i = 0; i < 5; i++) {
            checkers.add(new Thread(new BingoRowChecker(card, 2, cardId, game)));
            checkers.add(new Thread(new BingoColumnChecker(card, 2, cardId, game)));
        }
    }
}


