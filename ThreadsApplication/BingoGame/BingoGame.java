package ThreadsApplication.BingoGame;
import java.util.*;

class BingoGame {
    private List<BingoCard> cards;
    private boolean[] calledNumbers;
    private Random random;
    private boolean bingo;
    private List<Thread> threads;

    public BingoGame(int numPlayers) {
        cards = new ArrayList<>();
        for (int i = 0; i < numPlayers; i++) {
            cards.add(new BingoCard(i + 1));
        }
        calledNumbers = new boolean[76];
        calledNumbers[0] = true; // FREE space
        random = new Random();
        bingo = false;
        threads = new ArrayList<>();
    }

    public void play() {
        // Create threads for pattern checkers
        for (BingoCard card : cards) {
            threads.add(new Thread(new BingoPatternPlus(card, card.getId(), this)));
            threads.add(new Thread(new BingoPatternHash(card, card.getId(), this)));
        }

        // Start all threads
        for (Thread thread : threads) {
            thread.start();
        }

        // Main game loop
        while (!bingo) {
            int num;
            do {
                num = random.nextInt(75) + 1;
            } while (calledNumbers[num]);
            calledNumbers[num] = true;
            System.out.println("Number called: " + num);

            // Mark the number on all cards
            for (BingoCard card : cards) {
                card.markNumber(num);
            }

            // Print all called numbers
            System.out.print("Numbers called: ");
            for (int i = 1; i <= 75; i++) {
                if (calledNumbers[i]) {
                    System.out.print(i + " ");
                }
            }
            System.out.println();

            // Sleep for 0.3 seconds
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                break;
            }
        }

        // Interrupt all threads when bingo is declared
        for (Thread thread : threads) {
            thread.interrupt();
        }
    }

    public synchronized void declareBingo() {
        bingo = true;
        System.out.println("BINGO! Game over.");
    }

    public boolean isBingo() {
        return bingo;
    }
}

