package PracticeArrayList;

public class MyArrayList <E>{
    private static final int capacity = 5;
    private int size = 0;
    private E[] array;

    public MyArrayList() {
        array = (E[]) new Object[capacity];
    }

    public void add(E num) throws ArrayIndexOutOfBounds, InvalidPosition, ArrayFull{
        try{
            array[size++] = num;
        }catch(ArrayIndexOutOfBounds e){
            throw new ArrayFull("Array is full");
        }
    }

    public void addAt(int pos, E num)throws ArrayIndexOutOfBounds, InvalidPosition, ArrayFull{
        if(pos < 1 || pos > size +1) throw new InvalidPosition("Your position isnt valid");
        try{
            for(int i = pos-1; i < size; i++){
                array[i] = array[i+1];
            }
            array[pos-1] = num;
            size++;
        }catch(ArrayFull e){
            throw new ArrayFull("Array is full");
        }
    }

    public E removeAt(int pos) throws ArrayIndexOutOfBounds, InvalidPosition, ArrayFull{
        if(pos < 1 || pos > size +1) throw new InvalidPosition("Your position isnt valid");
        E ret = array[pos-1];
        for(int i = pos-1; i < size; i++){
            array[i] = array[i+1];
        }
        size--;
        return ret;
    }

    public boolean remove(E num) throws ArrayIndexOutOfBounds, InvalidPosition, ArrayFull{
        for(int i = 0; i < size; i++){
            if(array[i] == num){
                removeAt(i+1);
                return true;
            }
        }
        return false;
    }

    public E get(int pos) throws ArrayIndexOutOfBounds, InvalidPosition, ArrayFull{
        return array[pos-1];
    }

    public E set(int pos, E num) throws ArrayIndexOutOfBounds, InvalidPosition, ArrayFull{
        return array[pos-1] = num;
    }

    public boolean contains(E num){
        for(int i = 0; i < size; i++){
            if(array[i] == num) return true;
        }
        return false;
    }
}
