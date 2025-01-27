#include <math.h>

struct Point {
    int x;
    int y; 

    // This method added as reference.    
    double distance(Point* other) {
        int diff_x = this->x - other->x;
        int diff_y = this->y - other->y;
        int sq_x = diff_x * diff_x;
        int sq_y = pow(diff_y, 2);
        int sum = sq_x + sq_y;
        double answer = sqrt(sum);
        return answer;
    }

    // TODO create slope method here
    double slope(Point* other){
        return ((double)other->y - (double)y)/((double)other->x - (double)x);
    }

};

typedef Point point;