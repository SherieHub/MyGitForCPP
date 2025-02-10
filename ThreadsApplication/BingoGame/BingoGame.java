package ThreadsApplication.BingoGame;
import java.util.*;

class BingoGame {
    private List<BingoCard> cards;
    private Set<Integer> calledNumbers;
    private Random random;
    private boolean gameOver;

    public BingoGame(int numPlayers) {
        cards = new ArrayList<>();
        for (int i = 0; i < numPlayers; i++) {
            cards.add(new BingoCard());
        }
        calledNumbers = new HashSet<>();
        random = new Random();
        gameOver = false;
    }

    public synchronized void stopGame() {
        gameOver = true;
    }

    public void play() {
        while (!gameOver) {
            int num;
            do {
                num = random.nextInt(75) + 1;
            } while (calledNumbers.contains(num));
            calledNumbers.add(num);
            System.out.println("Number called: " + num);

            for (int i = 0; i < cards.size(); i++) {
                cards.get(i).markNumber(num);
            }

            checkBingo();
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                break;
            }
        }
    }

    private void checkBingo() {
        for (int i = 0; i < cards.size(); i++) {
            BingoCard card = cards.get(i);
            for (int j = 0; j < 5; j++) {
                new Thread(new BingoRowChecker(card, j, i + 1, this)).start();
                new Thread(new BingoColumnChecker(card, j, i + 1, this)).start();
            }
        }
    }
}

