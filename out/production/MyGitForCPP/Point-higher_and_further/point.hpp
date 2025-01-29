#include <math.h>

struct Point {
    int x;
    int y;

    // TODO create methods here
    Point* higher(Point* other){
        if(y > other->y){
            return this;
        }else{
            return other;
        }
    }
    
    Point* further(Point* other){
        if(abs(x) > abs(other->x)){
            return this;
        }else{
            return other;
        }
    }

};

typedef Point point;