package GenericLinkedList;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class LinkedListTest {
    private LinkedList<Integer> intList;
    private LinkedList<String> strList;

    @BeforeEach
    void setUp() {
        intList = new LinkedList<>();
        strList = new LinkedList<>();
    }

    @Test
    void testAddFirst() {
        intList.addFirst(10);
        intList.addFirst(20);
        assertEquals(2, intList.getSize());
    }

    @Test
    void testAddLast() {
        intList.addLast(30);
        intList.addLast(40);
        assertEquals(2, intList.getSize());
    }

    @Test
    void testRemoveFirst() {
        intList.addFirst(50);
        intList.addFirst(60);
        assertEquals(60, intList.removeFirst());
        assertEquals(1, intList.getSize());
    }

    @Test
    void testIsEmpty() {
        assertTrue(intList.isEmpty());
        intList.addFirst(100);
        assertFalse(intList.isEmpty());
    }

    @Test
    void testStringList() {
        strList.addFirst("A");
        strList.addLast("B");
        assertEquals(2, strList.getSize());
        assertEquals("A", strList.removeFirst());
        assertEquals(1, strList.getSize());
    }
}

