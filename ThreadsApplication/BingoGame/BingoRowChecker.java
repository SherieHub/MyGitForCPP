package ThreadsApplication.BingoGame;

class BingoRowChecker implements Runnable {
    private BingoCard card;
    private int row;
    private int cardId;
    private BingoGame game;

    public BingoRowChecker(BingoCard card, int row, int cardId, BingoGame game) {
        this.card = card;
        this.row = row;
        this.cardId = cardId;
        this.game = game;
    }

    public void run() {
        for (int col = 0; col < 5; col++) {
            if (!card.isMarked(row, col)) return;
        }

        // Declare bingo if the pattern is completed
        if (!game.isBingo()) {
            game.declareBingo();
            System.out.println("Card " + cardId + " completes pattern on row " + row + "!");
            System.out.println(card);
        }
    }
}
