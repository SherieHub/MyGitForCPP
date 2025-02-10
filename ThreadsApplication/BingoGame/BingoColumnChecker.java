package ThreadsApplication.BingoGame;

class BingoColumnChecker extends BingoChecker {
    private int col;
    public BingoColumnChecker(BingoCard card, int col, int cardId, BingoGame game) {
        super(card, cardId, game);
        this.col = col;
    }
    public void run() {
        for (int row = 0; row < 5; row++) {
            if (!card.isMarked(row, col)) return;
        }
        System.out.println("Player " + cardId + " wins with a Bingo on column " + col + "!");
        game.stopGame();
    }
}
