// Warning: DO NOT MODIFY THIS FILE.
// Except for the commented out section.

#include <iostream>
#include "point.hpp"
using namespace std;

int main() {
    Point point1, point2;
    cout << "Enter x of point 1: ";
    cin >> point1.x;
    cout << "Enter y of point 1: ";
    cin >> point1.y;
    cout << "Enter x of point 2: ";
    cin >> point2.x;
    cout << "Enter y of point 2: ";
    cin >> point2.y;
    
    double slopeRes = point1.slope(&point2);
    cout << endl << "The slope of the line connected by the two points is " << slopeRes /** call the slope method here using either points passing the other **/ << endl;
    return 0;
}