package ThreadsApplication.BingoGame;

class BingoColumnChecker implements Runnable {
    private BingoCard card;
    private int col;
    private int cardId;

    public BingoColumnChecker(BingoCard card, int col, int cardId) {
        this.card = card;
        this.col = col;
        this.cardId = cardId;
    }

    public void run() {
        for (int row = 0; row < 5; row++) {
            if (!card.isMarked(row, col)) return;
        }
        System.out.println("Card " + cardId + " completes pattern on column " + col + "!");
        System.out.println(card);
        Thread.currentThread().interrupt();
    }
}