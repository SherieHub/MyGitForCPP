package Bingo_Game;
import java.util.*;

public class BingoCard {
    private final int[][] numbers;
    private final int id;
    static int ID;

    BingoCard(){
        id = ++ID;
        numbers = new int[5][5];
        int[] ranges = {1, 16, 31, 46, 61};
        for (int col = 0; col < 5; col++) {
            List<Integer> num = new ArrayList<>();
            for (int i = ranges[col]; i < ranges[col] + 15; i++) {
                num.add(i);
            }
            Collections.shuffle(num);
            for (int row = 0; row < 5; row++) {
                if (col == 2 && row == 2) {
                    numbers[row][col] = 0;
                } else {
                    numbers[row][col] = num.remove(0);
                }
            }
        }
    }

    @Override
    public String toString(){
        char[] bingo = {'B', 'I', 'N', 'G', 'O'};
        StringBuilder sb = new StringBuilder("Card " + id + "\n");
        for (char c : bingo) {
            sb.append(" ").append(c).append(" ");
        }
        sb.append("\n");
        for (int[] n : numbers) {
            for (int num : n) {
                sb.append(num == 0 ? "00" : String.format("%2d", num)).append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }

    public int getId() {
        return id;
    }

    public int[][] getCard() {
        return numbers;
    }
}
