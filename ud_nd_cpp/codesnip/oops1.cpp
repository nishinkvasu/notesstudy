#include<iostream>
#include<vector>

class Wheel{
    public:
    Wheel() : diameter(50){}
    int diameter;
};

class Car{
    public:
    Car() : wheels(4, Wheel()), rims(5,5){}
    std::vector<Wheel> wheels;
  
    std::vector<int> rims;
};

int main(){
    Car car;
    std::cout<< car.wheels.size() <<"\n";
    std::cout<< car.rims[2];
}