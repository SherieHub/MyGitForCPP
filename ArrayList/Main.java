package ArrayList;

public class Main {
    public static void main(String[] args) throws ArrayFullException {
        MyArrayList myArrayList = new MyArrayList();
        myArrayList.add(10);
        myArrayList.add(8);
        myArrayList.add(7);
        myArrayList.add(10);
        myArrayList.removeAt(4);
        myArrayList.remove(8);
        myArrayList.print();


    }
}
