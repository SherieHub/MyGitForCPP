package GenericLinkedList;

import ArrayList.InvalidPositionException;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.NoSuchElementException;
import java.util.Random;

import static org.junit.jupiter.api.Assertions.*;

class DoublyLinkedListTest {

    private DoublyLinkedList<Integer> list;

    @BeforeEach
    void setUp() {
        list = new DoublyLinkedList<>();
    }

    @Test
    void testIsEmptyInitially() {
        // Newly constructed list should be empty.
        assertTrue(list.isEmpty(), "List should be empty initially");
    }

    @Test
    void testAddHead() {
        list.addHead(10);
        list.addHead(20);
        // After adding 20 at head then 10 becomes second.
        assertEquals(2, list.getSize(), "List size should be 2 after two addHead calls");
        assertEquals(20, list.get(1), "First element should be the last added (20)");
        assertEquals(10, list.get(2), "Second element should be 10");
    }

    @Test
    void testAddLast() {
        list.addLast(30);
        list.addLast(40);
        // List should preserve insertion order.
        assertEquals(2, list.getSize(), "List size should be 2 after two addLast calls");
        assertEquals(30, list.get(1), "First element should be 30");
        assertEquals(40, list.get(2), "Second element should be 40");
    }

    @Test
    void testAddAt() throws InvalidPositionException {
        // Build initial list: addHead and addLast
        list.addHead(10);  // list: 10
        list.addLast(30);  // list: 10, 30
        // Insert in the middle
        list.addAt(20, 2); // list should become: 10, 20, 30

        assertEquals(3, list.getSize(), "List size should be 3 after addAt in the middle");
        assertEquals(10, list.get(1));
        assertEquals(20, list.get(2));
        assertEquals(30, list.get(3));

        // Insert at the beginning using addAt
        list.addAt(5, 1); // list: 5, 10, 20, 30
        assertEquals(5, list.get(1), "New element 5 should be at position 1");

        // Attempting to add at an invalid position should throw an exception.
        assertThrows(InvalidPositionException.class, () -> list.addAt(100, 0),
                "Adding at position 0 should throw an InvalidPositionException");
        // Valid positions for a list of size 4 are 1 to 5.
        assertThrows(InvalidPositionException.class, () -> list.addAt(100, 6),
                "Adding beyond size+1 should throw an InvalidPositionException");
    }

    @Test
    void testRemoveFirst() {
        // Create a list and remove the first element repeatedly.
        list.addLast(100);
        list.addLast(200);
        list.addLast(300);

        int removed = list.removeFirst();
        assertEquals(100, removed, "removeFirst should return the first element (100)");
        assertEquals(2, list.getSize(), "List size should be reduced after removeFirst");

        // Remove remaining elements.
        list.removeFirst();
        list.removeFirst();
        assertTrue(list.isEmpty(), "List should be empty after removing all elements");

        // Removing from an empty list should throw an exception.
        assertThrows(NoSuchElementException.class, () -> list.removeFirst(),
                "removeFirst on an empty list should throw NoSuchElementException");
    }

    @Test
    void testRemoveLast() {
        // Create a list and remove the last element repeatedly.
        list.addHead(400);
        list.addHead(500);
        list.addHead(600);  // List now: 600, 500, 400

        int removed = list.removeLast();
        assertEquals(400, removed, "removeLast should return the last element (400)");
        assertEquals(2, list.getSize(), "List size should be reduced after removeLast");

        // Remove remaining elements.
        list.removeLast();
        list.removeLast();
        assertTrue(list.isEmpty(), "List should be empty after removing all elements");

        // Removing from an empty list should throw an exception.
        assertThrows(NoSuchElementException.class, () -> list.removeLast(),
                "removeLast on an empty list should throw NoSuchElementException");
    }

    @Test
    void testMixedOperations() throws InvalidPositionException {
        // Start with an empty list and perform a mixture of operations.
        list.addLast(1);     // list: 1
        list.addHead(0);     // list: 0, 1
        list.addAt(5, 3);    // list: 0, 1, 5
        list.addAt(2, 2);    // list: 0, 2, 1, 5
        list.addLast(10);    // list: 0, 2, 1, 5, 10
        list.addHead(-1);    // list: -1, 0, 2, 1, 5, 10

        assertEquals(6, list.getSize(), "List size should be 6 after a series of mixed operations");

        // Verify the order.
        assertEquals(-1, list.get(1));
        assertEquals(0, list.get(2));
        assertEquals(2, list.get(3));
        assertEquals(1, list.get(4));
        assertEquals(5, list.get(5));
        assertEquals(10, list.get(6));

        // Now remove from both ends.
        int firstRemoved = list.removeFirst(); // should remove -1
        int lastRemoved = list.removeLast();   // should remove 10
        assertEquals(-1, firstRemoved, "First element removed should be -1");
        assertEquals(10, lastRemoved, "Last element removed should be 10");
        assertEquals(4, list.getSize(), "List size should be 4 after two removals");

        // Verify the remaining order.
        assertEquals(0, list.get(1));
        assertEquals(2, list.get(2));
        assertEquals(1, list.get(3));
        assertEquals(5, list.get(4));
    }

    @Test
    void testGenericTypeWithStrings() throws InvalidPositionException {
        // Create a list of strings to verify that the generic works correctly.
        DoublyLinkedList<String> stringList = new DoublyLinkedList<>();
        stringList.addHead("apple");
        stringList.addLast("banana");
        stringList.addAt("cherry", 2);  // list should be: apple, cherry, banana

        assertEquals(3, stringList.getSize(), "String list size should be 3");
        assertEquals("apple", stringList.get(1));
        assertEquals("cherry", stringList.get(2));
        assertEquals("banana", stringList.get(3));
    }

    // ===================== Additional Harder Tests =====================

    @Test
    void testGetInvalidPosition() {
        list.addLast(1);
        list.addLast(2);
        // Attempt to get elements at invalid positions.
        // Assuming that get() throws an InvalidPositionException on invalid indices.
        assertThrows(InvalidPositionException.class, () -> list.get(0), "Position 0 is invalid");
        assertThrows(InvalidPositionException.class, () -> list.get(-1), "Negative position is invalid");
        assertThrows(InvalidPositionException.class, () -> list.get(3), "Position beyond list size is invalid");
    }

    @Test
    void testRemoveSingleElement() {
        // Add and then remove a single element from both ends.
        list.addHead(99);
        assertEquals(99, list.removeFirst(), "Single element removed from head should be 99");
        assertTrue(list.isEmpty(), "List should be empty after removal");

        list.addLast(77);
        assertEquals(77, list.removeLast(), "Single element removed from tail should be 77");
        assertTrue(list.isEmpty(), "List should be empty after removal");
    }

    @Test
    void testDuplicates() throws InvalidPositionException {
        // Add duplicate elements and remove one of them.
        list.addLast(42);
        list.addLast(42);
        list.addLast(42);
        assertEquals(3, list.getSize(), "List should contain three elements");
        assertEquals(42, list.get(1));
        assertEquals(42, list.get(2));
        assertEquals(42, list.get(3));

        // Remove one element and verify that duplicates remain.
        list.removeFirst();
        assertEquals(2, list.getSize(), "List should contain two elements after removal");
        assertEquals(42, list.get(1));
        assertEquals(42, list.get(2));
    }

    @Test
    void testAddAtBoundary() throws InvalidPositionException {
        // When the list is empty, adding at position 1 should work.
        list.addAt(100, 1);
        assertEquals(1, list.getSize(), "List size should be 1 after adding at position 1");
        assertEquals(100, list.get(1));

        // When the list has one element, adding at position 2 (append) should work.
        list.addAt(200, 2);
        assertEquals(2, list.getSize(), "List size should be 2 after appending at position 2");
        assertEquals(200, list.get(2));
    }

    @Test
    void testStressOperations() throws InvalidPositionException {
        // Test the list with a large number of operations.
        int count = 1000;
        for (int i = 1; i <= count; i++) {
            list.addLast(i);
        }
        assertEquals(count, list.getSize(), "List size should match number of added elements");

        // Verify the order.
        for (int i = 1; i <= count; i++) {
            assertEquals(i, list.get(i), "Element at position " + i + " should be " + i);
        }

        // Remove half the elements from the front.
        for (int i = 1; i <= count / 2; i++) {
            list.removeFirst();
        }
        assertEquals(count - count / 2, list.getSize(), "List size should be halved after removals");

        // Remove remaining elements from the back.
        while (!list.isEmpty()) {
            list.removeLast();
        }
        assertTrue(list.isEmpty(), "List should be empty after all removals");
    }

    @Test
    void testAlternateAddRemove() throws InvalidPositionException {
        // Alternate adding and removing from head and tail.
        for (int i = 0; i < 50; i++) {
            list.addHead(i);
            if (i % 2 == 0) {
                list.removeLast();
            } else {
                list.removeFirst();
            }
        }
        // Since the operations are alternating, we don't know the exact contents,
        // but we can remove the remaining elements to ensure consistency.
        int remaining = list.getSize();
        for (int i = 0; i < remaining; i++) {
            list.removeFirst();
        }
        assertTrue(list.isEmpty(), "List should be empty after alternating operations and removals");
    }

    @Test
    void testRandomOperations() throws InvalidPositionException {
        // Perform a series of random operations to simulate unpredictable usage.
        Random rand = new Random();
        int operations = 500;
        int currentSize = 0;

        for (int i = 0; i < operations; i++) {
            int op = rand.nextInt(4);
            switch (op) {
                case 0:
                    // addHead
                    list.addHead(i);
                    currentSize++;
                    break;
                case 1:
                    // addLast
                    list.addLast(i);
                    currentSize++;
                    break;
                case 2:
                    // removeFirst
                    if (!list.isEmpty()) {
                        list.removeFirst();
                        currentSize--;
                    } else {
                        assertThrows(NoSuchElementException.class, () -> list.removeFirst());
                    }
                    break;
                case 3:
                    // removeLast
                    if (!list.isEmpty()) {
                        list.removeLast();
                        currentSize--;
                    } else {
                        assertThrows(NoSuchElementException.class, () -> list.removeLast());
                    }
                    break;
            }
            assertEquals(currentSize, list.getSize(), "List size should be consistent with operations count");
        }
    }
}
