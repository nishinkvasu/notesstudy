#include <iostream>
#include <cmath>
#include <assert.h>
/*
Create a class LineSegment.
Declare an attribute length in class LineSegment.
Define pi (3.14159) with a macro.
Create a class Circle, composed of a LineSegment that represent's the circle's radius. Use this radius to calculate the area of the circle (area of a circle = pi*r*r ).
Verify the behavior of Circle in main().
*/
// Define pi
const float pi = 3.14159;
// Define Line Class
class LineSegment{
    // Define protected attribute length
    public:
    float length;
};
    
// Define Circle subclass
class Circle{
    // Define public setRadius() and getArea()
    
    public:
    Circle(LineSegment& radius);
    void setRadius(LineSegment& radius);
    double Area() const;
    private:
    LineSegment& radius_;

};
Circle::Circle(LineSegment& radius) : radius_(radius){
    //setRadius(radius); //if a reference is used it should be initialized as part of initializer list
}
void Circle::setRadius(LineSegment& radius){
    radius_ = radius;
}

double Circle::Area() const{
    return (pi * radius_.length * Circle::radius_.length);
}
// Test in main()
int main() 
{
    LineSegment radius {3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}