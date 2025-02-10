import java.util.*;

class BingoGame implements Runnable {
    private final boolean[] result = new boolean[76];
    private volatile boolean bingo = false; // Use `volatile` for thread visibility
    private final List<BingoCard> cards = new ArrayList<>();
    private final List<Thread> patternThreads = new ArrayList<>();
    private final Random rand = new Random();

    public BingoGame() {
        Arrays.fill(result, false);
        result[0] = true; // FREE SPACE
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of players/cards: ");
        int numPlayers = scanner.nextInt();
        scanner.close();

        for (int i = 1; i <= numPlayers; i++) {
            cards.add(new BingoCard(i));
        }

        for (BingoCard card : cards) {
            Thread t = new Thread(new BingoPatternPlus(card, this));
            patternThreads.add(t);
            t.start();
        }

        while (!bingo) {
            int num;
            do {
                num = rand.nextInt(75) + 1;
            } while (result[num]);
            result[num] = true;
            System.out.println("Number drawn: " + num);

            synchronized (this) {
                notifyAll(); // Notify all checker threads
            }

            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }

        for (Thread t : patternThreads) {
            t.interrupt(); // Interrupt all threads when bingo is found
        }

        System.out.println("Bingo! Final numbers drawn: ");
        for (int i = 1; i < result.length; i++) {
            if (result[i]) System.out.print(i + " ");
        }
        System.out.println();
    }

    public boolean isNumberDrawn(int num) {
        return result[num];
    }

    public synchronized boolean isBingo() {
        return bingo;
    }

    public synchronized void setBingo(boolean bingo) {
        this.bingo = bingo;
    }
}
