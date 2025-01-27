package ArrayList;

public abstract class List {
    public abstract void increaseCapacity();
    public abstract void decreaseCapacity();
    public abstract void addFirst(int num);
    public abstract void addLast(int num);
    public abstract void addAt(int num, int pos);
    public abstract int removeFirst();
    public abstract int removeLast();
    public abstract int removeAt(int pos);
    public abstract int get(int pos);
    public abstract void print();
}
