// TODO create struct Rectangle here, with the methods area() and perimeter()
#include "point.hpp"
#include <cmath>
#include <iostream>
struct Rectangle{
    Point p1, p2;
    
    int area(){
        return (abs(p2.x - p1.x)) * (abs(p2.y - p1.y));
    }
    
    int perimeter(){
        return 2 * (abs(p2.x - p1.x) + abs(p2.y - p1.y));
    }
};