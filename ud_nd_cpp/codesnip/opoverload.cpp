#include <assert.h>

// TODO: Define Point class
class Point{
    public:
  // TODO: Define public constructor
  Point(int x = 0, int y = 0) : x(x), y(y){}
  // TODO: Define + operator overload
  Point operator+(const Point &a){ // const reference was taken from the solution in the course
    Point c;//(a.x + x, a.y + y); // since default values are assigned to 0, passing no parameter is fine
    c.x = a.x + x;
    c.y = a.y + y;
    return c;
  }
  // TODO: Declare attributes x and y 
  int x;
  int y;   
};


// Test in main()
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}