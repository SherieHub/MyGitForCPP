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
        game = new BingoGame(1); // Initialize game with 1 player
        card = new BingoCard(1); // Pass card ID to constructor
    }

    @Test
    void testCardGeneration() {
        int[][] numbers = card.getCard();
        Set<Integer> usedNumbers = new HashSet<>();

        for (int col = 0; col < 5; col++) {
            for (int row = 0; row < 5; row++) {
                int num = numbers[row][col];
                if (row == 2 && col == 2) {
                    assertEquals(0, num, "Center cell should be FREE (0)");
                } else {
                    assertTrue(num >= col * 15 + 1 && num <= (col + 1) * 15, "Number is out of range");
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
            card.markNumber(card.getCard()[2][col]); // Mark all numbers in the middle row
        }
        BingoRowChecker checker = new BingoRowChecker(card, 2, 1, game);
        checker.run();
        assertTrue(game.isBingo(), "Game should be stopped when row is completed");
    }

    @Test
    void testBingoColumnChecker() {
        for (int row = 0; row < 5; row++) {
            card.markNumber(card.getCard()[row][3]); // Mark all numbers in the fourth column
        }
        BingoColumnChecker checker = new BingoColumnChecker(card, 3, 1, game);
        checker.run();
        assertTrue(game.isBingo(), "Game should be stopped when column is completed");
    }

    @Test
    void testBingoPatternPlus() {
        for (int i = 0; i < 5; i++) {
            card.markNumber(card.getCard()[2][i]); // Mark middle row
            card.markNumber(card.getCard()[i][2]); // Mark middle column
        }
        BingoPatternPlus patternPlus = new BingoPatternPlus(card, 1, game);
        patternPlus.run();
        assertTrue(game.isBingo(), "Game should be stopped when plus pattern is completed");
    }

    @Test
    void testBingoPatternHash() {
        for (int i = 1; i < 4; i++) {
            card.markNumber(card.getCard()[1][i]); // Mark second row
            card.markNumber(card.getCard()[3][i]); // Mark fourth row
            card.markNumber(card.getCard()[i][1]); // Mark second column
            card.markNumber(card.getCard()[i][3]); // Mark fourth column
        }
        BingoPatternHash patternHash = new BingoPatternHash(card, 1, game);
        patternHash.run();
        assertTrue(game.isBingo(), "Game should be stopped when hash pattern is completed");
    }

    @Test
    void testGameOver() {
        game.declareBingo(); // Manually declare bingo
        assertTrue(game.isBingo(), "Game should be over when bingo is declared");
    }
}