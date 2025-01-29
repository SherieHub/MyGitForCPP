//
// Created by austi on 29/01/2025.
//

#ifndef QUEUE_HPP
#define QUEUE_HPP



class Queue{
private:
    int front;
    int rear;
    int arr[5];
public:
    Queue(){
        front = -1;
        rear = -1;
        for(int i = 0; i < 5; i++){
            arr[i] = 0;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if(rear == 4){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int val){
        if(isFull()){
            cout << "Queue is Full!" <<endl;
            return;
        }else if(isEmpty()){
            rear = front = 0;
        }else{
            rear++;
        }
        arr[rear] = val;
    }

    int dequeue(){
        int x = 0;
        if(isEmpty()){
            cout << "Queue is Empty!" <<endl;
            return 0;
        }else if(front == rear){
            x = arr[front];
            arr[front] = 0;
            front = rear = -1;
        }else{
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }

    int count(){
        return rear - front + 1;
    }

    void display(){
        cout << "All values in the Queue are: " <<endl;
        for(int i = 0; i < 5; i++){
            cout << arr[i] << " ";
        }
        cout <<"\n";
    }
};



#endif //QUEUE_HPP
