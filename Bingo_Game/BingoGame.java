package Bingo_Game;

import java.util.*;
public class BingoGame implements Runnable{
    private final boolean[] result = new boolean[76];
    private volatile boolean isBingo = false;
    private final List<BingoCard> cards = new ArrayList<>();
    public BingoGame(){
        Arrays.fill(result, false);
        result[0] = true;
    }

    public void run() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of players/cards: ");
        int numPlayers = sc.nextInt();

        for (int i = 0; i < numPlayers; i++) {
            cards.add(new BingoCard());
        }

        List<Thread> threads = new ArrayList<>();
        for (BingoCard card : cards) {
            threads.add(new Thread(new BingoPatternPlus(card, this)));
        }

        for (BingoCard card : cards) {
            threads.add(new Thread(new BingoPatternHash(card, this)));
        }

        for (Thread t : threads) {
            t.start();
        }

        Random rand = new Random();
        List<Integer> drawnNumbers = new ArrayList<>();

        while (!isBingo) {
            int num;
            do {
                num = rand.nextInt(75) + 1;
            } while (result[num]);

            result[num] = true;
            drawnNumbers.add(num);
            Collections.sort(drawnNumbers);

            System.out.print("Chosen: " + num + " | All numbers: ");
            for (int n : drawnNumbers) {
                System.out.print(n + " ");
            }
            System.out.println();

            synchronized (this) {
                notifyAll();
            }

            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
                System.out.println("Game interrupted.");
                return;
            }
        }

        System.out.print("Bingo! All numbers drawn: ");
        for (int n : drawnNumbers) {
            System.out.print(n + " ");
        }
        System.out.println();

        for (Thread t : threads) {
            t.interrupt();
        }
    }

    public synchronized boolean isNumberChosen(int num) {
        return result[num];
    }

    public synchronized boolean isBingo() {
        return isBingo;
    }

    public synchronized void setBingo(boolean isBingo) {
        this.isBingo = isBingo;
    }
}
