// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>

// TODO: Define pi
#define pi  3.141759

// TODO: Define the abstract class Shape
class Shape{
  // TODO: Define public virtual functions Area() and Perimeter()
  public:
  virtual float Area() const = 0;
  virtual float Perimeter() const = 0;
  // TODO: Append the declarations with = 0 to specify pure virtual functions
};

// TODO: Define Rectangle to inherit publicly from Shape
class Rectangle : Shape{
  // TODO: Declare public constructor
  public:
  Rectangle(int width, int height) : width_(width), height_(height){ }
  
  // TODO: Override virtual base class functions Area() and Perimeter()
  float Area() const override{ //adding override is a good practice to let programmers and compilers know
      return width_ * height_;
  }
  float Perimeter() const;
  // TODO: Declare private attributes width and height
  private:
  int width_;
  int height_;
};
// TODO: Define Circle to inherit from Shape
class Circle : Shape{
  // TODO: Declare public constructor
  // TODO: Override virtual base class functions Area() and Perimeter()
  // TODO: Declare private member variable radius
    public:
    Circle(float radius) : radius_(radius){}
    float Area() const{
        return (pi * radius_ * radius_);
    }
    float Perimeter() const;
    private:
    float radius_;
};

float Rectangle::Perimeter() const{
    return (2 * (width_ + height_));
}

float Circle::Perimeter() const{
    return (2 * pi * radius_);
}


// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
  
  }