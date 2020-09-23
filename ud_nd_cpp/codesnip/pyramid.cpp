#include <cassert>
#include <stdexcept>
#include <iostream>

// TODO: Define class Pyramid
class Pyramid
{
// public class members
    public:
// constructor
    Pyramid(int l, int w, int h);
// accessors
    int Length() const;
    int Width() const;
    int Height() const;
// mutators
    void Length(int l);
    void Width(int w);
    void Height(int h);
// public Volume() function
    int Volume() const;
    float SurfaceArea() const;
// private class members
    int length_;
    int width_;
    int height_;
};

void Pyramid::Length(int l){
    if(l<0){
        //std::cout << l <<"\n";
        throw -1;
    }

    Pyramid::length_ = l;
}
void Pyramid::Width(int w){
    if(w<0)
        throw "Negative width invalid";
    Pyramid::width_ = w;
}
void Pyramid::Height(int h){
    if(h<0)
        throw "Negative height invalid";
    Pyramid::height_ = h;
}

int Pyramid::Height() const{
    return Pyramid::height_;
}
int Pyramid::Width() const{
    return Pyramid::width_;
}
int Pyramid::Length() const{
    return Pyramid::length_;
}
int Pyramid::Volume() const{
    return (Pyramid::height_ * Pyramid::width_ * Pyramid::length_)/3;
}
float Pyramid::SurfaceArea() const{
    return ((Pyramid::width_ * Pyramid::length_) * (Pyramid::height_ * Pyramid::width_) * (Pyramid::height_ * Pyramid::length_));
}

Pyramid::Pyramid(int l, int w, int h){
    Pyramid::Length(l);
    Pyramid::Width(w);
    Pyramid::Height(h);
}
// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}