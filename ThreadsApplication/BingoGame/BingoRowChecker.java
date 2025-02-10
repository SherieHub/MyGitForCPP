package ThreadsApplication.BingoGame;

class BingoRowChecker extends BingoChecker {
    private int row;
    public BingoRowChecker(BingoCard card, int row, int cardId, BingoGame game) {
        super(card, cardId, game);
        this.row = row;
    }
    public void run() {
        for (int col = 0; col < 5; col++) {
            if (!card.isMarked(row, col)) return;
        }
        System.out.println("Player " + cardId + " wins with a Bingo on row " + row + "!");
        game.stopGame();
    }
}
