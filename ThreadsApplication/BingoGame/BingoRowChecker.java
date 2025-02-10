package ThreadsApplication.BingoGame;

class BingoRowChecker implements Runnable {
    private BingoCard card;
    private int row;
    private int cardId;

    public BingoRowChecker(BingoCard card, int row, int cardId) {
        this.card = card;
        this.row = row;
        this.cardId = cardId;
    }

    public void run() {
        for (int col = 0; col < 5; col++) {
            if (!card.isMarked(row, col)) return;
        }
        System.out.println("Card " + cardId + " completes pattern on row " + row + "!");
        System.out.println(card);
        Thread.currentThread().interrupt();
    }
}
