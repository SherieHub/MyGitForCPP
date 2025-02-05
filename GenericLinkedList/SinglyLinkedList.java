package GenericLinkedList;

import java.util.NoSuchElementException;

class SinglyLinkedList<T> {
    private SinglyNode<T> head, tail;
    private int size;

    public SinglyLinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public void addFirst(T data) {
        SinglyNode<T> newNode = new SinglyNode<>(data);
        if(head == null) {
            head = newNode;
            tail = newNode;
            head.next = tail;
        }
        else{
            newNode.next = head;
            head = newNode;
        }
        size++;
    }

    public void addLast(T data) {
        SinglyNode<T> newNode = new SinglyNode<>(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
            head.next = tail;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    public T removeFirst() throws NoSuchElementException {
        if(size == 0){throw new NoSuchElementException("Empty List");
        }
        if (head == null) {
            return null;
        }
        T data = head.data;
        head = head.next;
        size--;
        return data;
    }

    public T removeLast() throws NoSuchElementException{
        if(size == 0){throw new NoSuchElementException("Empty List");
        }
        if (head == null) {
            return null;
        }
        T data = tail.data;
        SinglyNode<T> curr = head;
        while(curr.next != null) {
            if(curr.next == tail) {
                break;
            }
            curr = curr.next;
        }
        tail = curr;
        size--;
        return data;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int getSize() {
        return size;
    }

    public void printList() {
        SinglyNode<T> temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }
}