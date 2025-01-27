package ArrayList;

public class Main {
    public static void main(String[] args) throws ArrayFullException {
        MyArrayList myArrayList = new MyArrayList();
        myArrayList.add(10);
        myArrayList.addAt(9,9);
        myArrayList.add(8);
        myArrayList.add(7);
        myArrayList.add(10);
        myArrayList.print();


    }
}
