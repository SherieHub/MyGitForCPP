package ThreadsApplication.BingoGame;
import java.util.*;

class BingoGame {
    private List<BingoCard> cards;
    private boolean[] calledNumbers;
    private Random random;
    private boolean bingo;

    public BingoGame(int numPlayers) {
        cards = new ArrayList<>();
        for (int i = 0; i < numPlayers; i++) {
            cards.add(new BingoCard(i + 1));
        }
        calledNumbers = new boolean[76];
        calledNumbers[0] = true; // FREE space
        random = new Random();
        bingo = false;
    }

    public void play() {
        List<Thread> threads = new ArrayList<>();
        for (BingoCard card : cards) {
            threads.add(new Thread(new BingoPatternPlus(card, card.getId())));
            threads.add(new Thread(new BingoPatternHash(card, card.getId())));
        }

        for (Thread thread : threads) {
            thread.start();
        }

        while (!bingo) {
            int num;
            do {
                num = random.nextInt(75) + 1;
            } while (calledNumbers[num]);
            calledNumbers[num] = true;
            System.out.println("Number called: " + num);

            for (BingoCard card : cards) {
                card.markNumber(num);
            }

            System.out.print("Numbers called: ");
            for (int i = 1; i <= 75; i++) {
                if (calledNumbers[i]) {
                    System.out.print(i + " ");
                }
            }
            System.out.println();

            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                break;
            }
        }

        for (Thread thread : threads) {
            thread.interrupt();
        }
    }

    public boolean declareBingo() {
        return bingo = true;
    }
}


