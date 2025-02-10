package ThreadsApplication.BingoGame;

abstract class BingoChecker implements Runnable {
    protected BingoCard card;
    protected int cardId;
    protected BingoGame game;

    public BingoChecker(BingoCard card, int cardId, BingoGame game) {
        this.card = card;
        this.cardId = cardId;
        this.game = game;
    }
}
