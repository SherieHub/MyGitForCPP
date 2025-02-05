package GenericLinkedList;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import java.util.NoSuchElementException;

public class SinglyLinkedListTest {
    private SinglyLinkedList<Integer> list;

    @Before
    public void setUp() {
        list = new SinglyLinkedList<>();
    }

    @Test(expected = NoSuchElementException.class)
    public void testRemoveFirstFromEmpty() {
        list.removeFirst();
    }

    @Test(expected = NoSuchElementException.class)
    public void testRemoveLastFromEmpty() {
        list.removeLast();
    }

    @Test
    public void testAddRemoveCombinations() {
        // Test alternating add/remove operations
        list.addFirst(1);
        list.addLast(2);
        assertEquals(Integer.valueOf(1), list.removeFirst());
        list.addFirst(3);
        assertEquals(Integer.valueOf(2), list.removeLast());
        list.addLast(4);
        assertEquals(2, list.getSize());
        assertEquals(Integer.valueOf(3), list.removeFirst());
        assertEquals(Integer.valueOf(4), list.removeLast());
        assertTrue(list.isEmpty());
    }

    @Test
    public void testStructuralIntegrity() {
        // Add/remove operations that test head/tail pointers
        list.addFirst(1);
        list.addLast(2);
        list.addLast(3);
        list.removeFirst();
        list.removeLast();
        assertEquals("Tail should be updated correctly", Integer.valueOf(2), list.removeLast());
        assertTrue(list.isEmpty());

        list.addFirst(4);
        list.removeLast();
        assertTrue("Head should be null after removing last element", list.isEmpty());
    }

    @Test
    public void testLargeDataset() {
        // Stress test with 10000 elements
        int count = 10000;
        for (int i = 0; i < count; i++) {
            list.addLast(i);
        }
        assertEquals(count, list.getSize());
        for (int i = 0; i < count; i++) {
            assertEquals(Integer.valueOf(i), list.removeFirst());
        }
        assertEquals(0, list.getSize());
        assertTrue(list.isEmpty());
    }

    @Test
    public void testConcurrentEndOperations() {
        // Simultaneous addFirst/addLast followed by removes
        list.addFirst(1);
        list.addLast(2);
        list.addFirst(0);
        list.addLast(3);
        assertEquals(4, list.getSize());
        assertEquals(Integer.valueOf(0), list.removeFirst());
        assertEquals(Integer.valueOf(3), list.removeLast());
        assertEquals(Integer.valueOf(1), list.removeFirst());
        assertEquals(Integer.valueOf(2), list.removeLast());
        assertTrue(list.isEmpty());
    }

    @Test
    public void testNullSupport() {
        // Test null element handling
        list.addFirst(null);
        list.addLast(2);
        assertNull(list.removeFirst());
        assertEquals(Integer.valueOf(2), list.removeLast());
        assertTrue(list.isEmpty());
    }

    @Test
    public void testStringTypeHandling() {
        // Test with different generic type
        SinglyLinkedList<String> stringList = new SinglyLinkedList<>();
        stringList.addLast("World");
        stringList.addFirst("Hello");
        assertEquals("Hello", stringList.removeFirst());
        assertEquals("World", stringList.removeLast());
        assertTrue(stringList.isEmpty());
    }

    @Test
    public void testCircularReferenceCheck() {
        // Verify no circular references after operations
        list.addFirst(1);
        list.addLast(2);
        list.addLast(3);
        list.removeLast();
        assertEquals(Integer.valueOf(1), list.removeFirst());
        assertEquals(Integer.valueOf(2), list.removeLast());
        assertTrue(list.isEmpty());
    }

    @Test
    public void testIteratorBehavior() {
        // Verify sequence using remove methods
        list.addLast(1);
        list.addLast(2);
        list.addLast(3);
        assertEquals(Integer.valueOf(1), list.removeFirst());
        assertEquals(Integer.valueOf(3), list.removeLast());
        assertEquals(Integer.valueOf(2), list.removeFirst());
        assertTrue(list.isEmpty());
    }

    @Test
    public void testEdgeCaseSingleElement() {
        // Single element edge cases
        list.addFirst(5);
        assertEquals(Integer.valueOf(5), list.removeLast());
        assertTrue(list.isEmpty());

        list.addLast(6);
        assertEquals(Integer.valueOf(6), list.removeLast());
        assertTrue(list.isEmpty());
    }

    @Test
    public void testSizeConsistency() {
        // Verify size remains consistent through operations
        list.addFirst(1);
        list.addFirst(2);
        list.removeFirst();
        assertEquals(1, list.getSize());
        list.removeLast();
        assertEquals(0, list.getSize());
        list.addLast(3);
        assertEquals(1, list.getSize());
    }

    @Test
    public void testAlternatingEndOperations() {
        // Complex alternating pattern
        for (int i = 0; i < 5; i++) {
            list.addFirst(i);
            list.addLast(i * 10);
        }
        assertEquals(10, list.getSize());
        for (int i = 4; i >= 0; i--) {
            assertEquals(Integer.valueOf(i), list.removeFirst());
            assertEquals(Integer.valueOf(i * 10), list.removeLast());
        }
        assertTrue(list.isEmpty());
    }

    @Test
    public void testBulkAddRemove() {
        // Bulk operations with verification
        for (int i = 0; i < 100; i++) {
            if (i % 2 == 0) list.addFirst(i);
            else list.addLast(i);
        }
        assertEquals(100, list.getSize());
        for (int i = 99; i >= 0; i--) {
            if (i % 2 == 0) assertEquals(Integer.valueOf(i), list.removeFirst());
            else assertEquals(Integer.valueOf(i), list.removeLast());
        }
        assertTrue(list.isEmpty());
    }
}