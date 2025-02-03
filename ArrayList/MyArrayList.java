package ArrayList;

public class MyArrayList<E> {
    private static final int capacity = 5;
    private int _size = 0;
    private E[] array = (E[]) new Object[capacity];

    public void add(E num) throws ArrayFullException {
        try {
            array[_size++] = num;
        } catch (ArrayIndexOutOfBoundsException e) {
            _size--;
            throw new ArrayFullException("The array is full and " + num + " cannot be inserted.");
        }
    }

    public void addAt(E num, int pos) throws InvalidPositionException, ArrayFullException {
        if (pos < 1 || pos > _size+1) throw new InvalidPositionException("Position must be between 1 and " + capacity);
        if (_size >= capacity) throw new ArrayFullException("The array is full and " + num + " cannot be inserted.");
        for(int i = _size; i > pos-1; i--){
            array[i] = array[i-1];
        }
        array[pos-1] = num;
        _size++;
    }

    public boolean remove(E num) {
        for(int i = 0 ;i < _size; i++){
            if(array[i] == num){
                for(int j = i; j < _size-1; j++){
                    array[j] = array[j+1];
                }
                _size--;
                return true;
            }
        }
        return false;
    }

    public E removeAt(int pos) throws InvalidPositionException {
        if (pos < 1 || pos > _size) throw new InvalidPositionException("Position must be between 1 and " + _size);
        E val = array[pos-1];
        for (int i = pos-1; i < _size-1; i++) {
            array[i] = array[i+1];
        }
        _size--;
        return val;
    }

    public int size() {
        return _size;
    }

    public boolean contains(E num) {
        for (int i = 0; i < _size; i++) {
            if (array[i] == num) return true;
        }
        return false;
    }
    public boolean isEmpty() {
        return _size == 0;
    }

    public E get(int pos) throws InvalidPositionException {
        if (pos < 1 || pos > _size) throw new InvalidPositionException("Position must be between 1 and " + _size);
        return array[pos-1];
    }

    public E set(int pos, E num) throws InvalidPositionException {
        if (pos < 1 || pos > _size) throw new InvalidPositionException("Position must be between 1 and " + _size);
        E val = array[pos-1];
        array[pos-1] = num;
        return val;
    }

    public E print(){
        System.out.println("ARRAYLIST: ");
        for(int i = 0; i < _size; i++){
            System.out.print(array[i]+" ");
        }
        System.out.println();
        System.out.println("SIZE: " + _size +"/ "+capacity);
        return null;
    }

}