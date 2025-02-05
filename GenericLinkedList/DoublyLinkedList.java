package GenericLinkedList;

import ArrayList.InvalidPositionException;

import java.util.NoSuchElementException;

public class DoublyLinkedList <T>{
    private DoublyNode<T>head, tail;
    private int size;
    
    
    private void addBetween(T data, DoublyNode<T> pred, DoublyNode<T> succ) {
        DoublyNode<T> n = new DoublyNode<>(data);
        n.prev = pred;
        n.next = succ;
        pred.next = n;
        succ.prev = n;
        size++;
    }

    private void removeBetween(DoublyNode<T> n){
        DoublyNode<T> pred = n.prev;
        DoublyNode<T> succ = n.next;
        pred.next = succ;
        succ.prev = pred;
        size--;
    }
    public DoublyLinkedList() {
        head = new DoublyNode<>(null);
        tail = new DoublyNode<>(null);
        size = 0;
    }

    public void addHead(T data) {
        DoublyNode<T> n = new DoublyNode<>(data);
        if(size == 0) {
            head.next = n;
            tail.prev = n;
            n.prev = head;
            n.next = tail;
            size++;
        }
        else{
            addBetween(data, head, head.next);
        }
    }

    public void addAt(T data, int pos) throws InvalidPositionException{
        if(pos < 1 || pos > size+1){ throw new InvalidPositionException("Invalid position"); }
        DoublyNode<T> curr = head.next;
        if(pos == 1){
            addHead(data);
            return;
        }
        for(int i = 1; i < pos; i++){
            curr = curr.next;
        }
        addBetween(data,curr.prev, curr);
    }

    public void addLast(T data) {
        DoublyNode<T> n = new DoublyNode<>(data);
        if(size == 0) {
            head.next = n;
            tail.prev = n;
            n.prev = head;
            n.next = tail;
            size++;
        }
        else{
            addBetween(data, tail.prev, tail);
        }

    }

    public T removeFirst() throws NoSuchElementException{
        if(size == 0){throw new NoSuchElementException("Empty List");
        }
        T data = head.next.data;
        removeBetween(head.next);
        return data;
    }

    public T removeLast()throws NoSuchElementException{
        if(size == 0){throw new NoSuchElementException("Empty List");
        }
        T data = tail.prev.data;
        removeBetween(tail.prev);
        return data;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int getSize() {
        return size;
    }

    public T get(int pos) throws InvalidPositionException{
        if(pos < 1 || pos > size)throw new InvalidPositionException("Invalid position");
        DoublyNode<T> curr = head.next;
        for(int i = 1; i < pos; i++){
            curr = curr.next;
        }
        return curr.data;
    }

}
