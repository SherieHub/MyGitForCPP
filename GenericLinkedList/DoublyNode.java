package GenericLinkedList;

public class DoublyNode <T>{
    T data;
    DoublyNode<T> next, prev;

    DoublyNode(T data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
