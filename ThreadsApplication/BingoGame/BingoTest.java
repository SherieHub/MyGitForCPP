package ThreadsApplication.BingoGame;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.Set;
import java.util.HashSet;

class BingoTest {
    private BingoCard card;
    private BingoGame game;

    @BeforeEach
    void setUp() {
        game = new BingoGame(1);
        card = new BingoCard();
    }

    @Test
    void testCardGeneration() {
        int[][] numbers = card.getCard();
        Set<Integer> usedNumbers = new HashSet<>();

        for (int col = 0; col < 5; col++) {
            for (int row = 0; row < 5; row++) {
                int num = numbers[row][col];
                assertTrue(num == 0 || (num >= col * 15 + 1 && num <= (col + 1) * 15), "Number is out of range");
                if (!(row == 2 && col == 2)) {
                    usedNumbers.add(num);
                }
            }
        }
        assertEquals(24, usedNumbers.size(), "Incorrect number of unique numbers in the card");
    }

    @Test
    void testMarkNumber() {
        int[][] numbers = card.getCard();
        int testNumber = numbers[0][0];
        card.markNumber(testNumber);
        assertTrue(card.isMarked(0, 0), "Number should be marked");
    }

    @Test
    void testBingoRowChecker() {
        for (int col = 0; col < 5; col++) {
            card.markNumber(card.getCard()[2][col]);
        }
        BingoRowChecker checker = new BingoRowChecker(card, 2, 1, game);
        checker.run();
        assertTrue(gameOver(game), "Game should be stopped when row is completed");
    }

    @Test
    void testBingoColumnChecker() {
        for (int row = 0; row < 5; row++) {
            card.markNumber(card.getCard()[row][3]);
        }
        BingoColumnChecker checker = new BingoColumnChecker(card, 3, 1, game);
        checker.run();
        assertTrue(gameOver(game), "Game should be stopped when column is completed");
    }

    private boolean gameOver(BingoGame game) {
        try {
            java.lang.reflect.Field field = BingoGame.class.getDeclaredField("gameOver");
            field.setAccessible(true);
            return field.getBoolean(game);
        } catch (Exception e) {
            fail("Failed to access gameOver field");
            return false;
        }
    }
}
