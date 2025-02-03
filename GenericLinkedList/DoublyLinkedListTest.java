package GenericLinkedList;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import java.util.NoSuchElementException;
import java.util.Optional;

public class DoublyLinkedListTest {
    private DoublyLinkedList<Integer> list;

    @Before
    public void setUp() {
        list = new DoublyLinkedList<>();
    }

    @Test
    public void testInitialState() {
        assertTrue("New list should be empty", list.isEmpty());
        assertEquals("Initial size should be 0", 0, list.getSize());
    }

    @Test(expected = NoSuchElementException.class)
    public void testRemoveFirstEmptyList() {
        list.removeFirst();
    }

    @Test(expected = NoSuchElementException.class)
    public void testRemoveLastEmptyList() {
        list.removeLast();
    }

    @Test
    public void testAddHeadToEmptyList() {
        list.addHead(5);
        assertFalse("List shouldn't be empty", list.isEmpty());
        assertEquals("Size should be 1", 1, list.getSize());
        assertEquals("Remove first should return added item",
                Integer.valueOf(5), list.removeFirst());
    }

    @Test
    public void testAddLastToEmptyList() {
        list.addLast(7);
        assertEquals("Size should be 1", 1, list.getSize());
        assertEquals("Remove last should return added item",
                Integer.valueOf(7), list.removeLast());
    }

    @Test
    public void testMultipleAddHeadOperations() {
        list.addHead(1);
        list.addHead(2);
        list.addHead(3);
        assertEquals("Size should be 3", 3, list.getSize());
        assertEquals("First remove should get last added head",
                Integer.valueOf(3), list.removeFirst());
        assertEquals("Second remove should get middle item",
                Integer.valueOf(2), list.removeFirst());
        assertEquals("Last remove should get first added item",
                Integer.valueOf(1), list.removeFirst());
    }

    @Test
    public void testMultipleAddLastOperations() {
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        assertEquals("Size should be 3", 3, list.getSize());
        assertEquals("First removeLast should get 30",
                Integer.valueOf(30), list.removeLast());
        assertEquals("Second removeLast should get 20",
                Integer.valueOf(20), list.removeLast());
        assertEquals("Last removeLast should get 10",
                Integer.valueOf(10), list.removeLast());
    }

    @Test
    public void testSimultaneousHeadAndTailOperations() {
        list.addHead(100);
        list.addLast(200);
        list.addHead(300);
        list.addLast(400);

        assertEquals("Size should be 4", 4, list.getSize());
        assertEquals("First removeFirst should return 300",
                Integer.valueOf(300), list.removeFirst());
        assertEquals("First removeLast should return 400",
                Integer.valueOf(400), list.removeLast());
        assertEquals("Second removeFirst should return 100",
                Integer.valueOf(100), list.removeFirst());
        assertEquals("Second removeLast should return 200",
                Integer.valueOf(200), list.removeLast());
    }

    @Test
    public void testStructuralIntegrityAfterRemoval() {
        list.addHead(1);
        list.addLast(2);
        list.addLast(3);

        // Remove middle element via removeFirst
        assertEquals(Integer.valueOf(1), list.removeFirst());
        assertEquals("Size should be 2", 2, list.getSize());
        assertEquals("Next removeFirst should return 2",
                Integer.valueOf(2), list.removeFirst());
        assertEquals("Final removeLast should return 3",
                Integer.valueOf(3), list.removeLast());
    }

    @Test
    public void testAlternatingAddRemoveOperations() {
        list.addHead(5);
        list.removeLast();
        assertTrue("List should be empty", list.isEmpty());

        list.addLast(10);
        list.addHead(20);
        assertEquals("Size should be 2", 2, list.getSize());
        assertEquals(Integer.valueOf(20), list.removeFirst());
        assertEquals(Integer.valueOf(10), list.removeLast());
    }

    @Test
    public void testLargeNumberOfElements() {
        int testSize = 10000;
        for (int i = 0; i < testSize; i++) {
            if (i % 2 == 0) list.addHead(i);
            else list.addLast(i);
        }

        assertEquals("Size should match number of added elements",
                testSize, list.getSize());

        for (int i = testSize - 1; i >= 0; i--) {
            if (i % 2 != 0) assertEquals(Integer.valueOf(i), list.removeLast());
            else assertEquals(Integer.valueOf(i), list.removeFirst());
        }

        assertTrue("List should be empty after all removals", list.isEmpty());
    }

    @Test
    public void testNullHandling() {
        list.addHead(null);
        list.addLast(null);
        assertEquals("Size should be 2", 2, list.getSize());
        assertNull("First null should be removed", list.removeFirst());
        assertNull("Last null should be removed", list.removeLast());
    }

    @Test
    public void testAddAt(){
        list.addHead(1);
        list.addAt(3,1);
        assertEquals(Integer.valueOf(3), list.get(1));
    }

    @Test
    public void testAddAtException(){
        list.addHead(1);
        list.addAt(3,1);
        assertEquals(Integer.valueOf(3), list.get(1));
    }

    @Test
    public void testStringTypeHandling() {
        DoublyLinkedList<String> stringList = new DoublyLinkedList<>();
        stringList.addHead("World");
        stringList.addLast("Hello");
        assertEquals("First removal should be 'World'",
                "World", stringList.removeFirst());
        assertEquals("Last removal should be 'Hello'",
                "Hello", stringList.removeLast());
    }

    @Test
    public void testConsecutiveRemovals() {
        list.addHead(1);
        list.addLast(2);
        list.addHead(0);

        assertEquals(Integer.valueOf(0), list.removeFirst());
        assertEquals(Integer.valueOf(2), list.removeLast());
        assertEquals(Integer.valueOf(1), list.removeFirst());

        assertTrue("List should be empty", list.isEmpty());
        assertEquals("Size should be 0", 0, list.getSize());
    }

    @Test
    public void testSingleElementBehavior() {
        list.addHead(42);
        assertEquals("Single element removeLast",
                Integer.valueOf(42), list.removeLast());
        assertTrue("List should be empty", list.isEmpty());

        list.addLast(37);
        assertEquals("Single element removeFirst",
                Integer.valueOf(37), list.removeFirst());
        assertTrue("List should be empty", list.isEmpty());
    }

    @Test
    public void testBidirectionalTraversal() {
        list.addHead(1);
        list.addLast(2);
        list.addLast(3);
        list.addHead(0);

        assertEquals("RemoveFirst(0)", Integer.valueOf(0), list.removeFirst());
        assertEquals("RemoveLast(3)", Integer.valueOf(3), list.removeLast());
        assertEquals("RemoveFirst(1)", Integer.valueOf(1), list.removeFirst());
        assertEquals("RemoveLast(2)", Integer.valueOf(2), list.removeLast());
    }

    @Test
    public void testSizeConsistency() {
        for (int i = 0; i < 100; i++) {
            if (i % 3 == 0) {
                list.addHead(i);
            } else {
                list.addLast(i);
            }
            assertEquals("Size should increment correctly", i + 1, list.getSize());
        }

        for (int i = 99; i >= 0; i--) {
            if (i % 2 == 0) {
                list.removeFirst();
            } else {
                list.removeLast();
            }
            assertEquals("Size should decrement correctly", i, list.getSize());
        }
    }
}
