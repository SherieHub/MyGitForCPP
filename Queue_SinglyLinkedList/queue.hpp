
class Queue{
    public:
    
    virtual void enqueue(int num) = 0;
    virtual int dequeue() = 0;
    virtual int first() = 0;
    virtual int _size() = 0;
    virtual bool isEmpty() = 0;

};