package Bingo_Game;

abstract class BingoChecker implements Runnable{
    final BingoCard card;
    final BingoGame game;
    public BingoChecker(BingoCard card, BingoGame game){
        this.card = card;
        this.game = game;
    }
}
