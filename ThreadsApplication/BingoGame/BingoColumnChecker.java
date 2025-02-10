package ThreadsApplication.BingoGame;

class BingoColumnChecker implements Runnable {
    private BingoCard card;
    private int col;
    private int cardId;
    private BingoGame game;

    public BingoColumnChecker(BingoCard card, int col, int cardId, BingoGame game) {
        this.card = card;
        this.col = col;
        this.cardId = cardId;
        this.game = game;
    }

    public void run() {
        for (int row = 0; row < 5; row++) {
            if (!card.isMarked(row, col)) return;
        }

        // Declare bingo if the pattern is completed
        if (!game.isBingo()) {
            game.declareBingo();
            System.out.println("Card " + cardId + " completes pattern on column " + col + "!");
            System.out.println(card);
        }
    }
}