import java.util.*;

class BingoCard {
    private final int[][] card;
    private final int id;
    private static final Random rand = new Random();

    public BingoCard(int id) {
        this.id = id;
        this.card = new int[5][5];
        generateCard();
    }

    private void generateCard() {
        int[] ranges = {1, 16, 31, 46, 61};
        for (int col = 0; col < 5; col++) {
            List<Integer> numbers = new ArrayList<>();
            for (int i = ranges[col]; i < ranges[col] + 15; i++) {
                numbers.add(i);
            }
            Collections.shuffle(numbers);
            for (int row = 0; row < 5; row++) {
                if (col == 2 && row == 2) {
                    card[row][col] = 0; // FREE SPACE
                } else {
                    card[row][col] = numbers.remove(0);
                }
            }
        }
    }

    public int getId() {
        return id;
    }

    public int[][] getCard() {
        return card;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("Card " + id + "\n");
        for (int[] row : card) {
            for (int num : row) {
                sb.append(num == 0 ? "FREE" : String.format("%2d", num)).append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}