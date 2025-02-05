package GenericLinkedList;

class SinglyNode<T> {
    T data;
    SinglyNode<T> next;

    SinglyNode(T data) {
        this.data = data;
        this.next = null;
    }
}