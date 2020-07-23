#include <cmath>
#include <cassert>

// TODO: Define PI
#define PI 3.14159

// TODO: Declare abstract class VehicleModel
  // TODO: Declare virtual function Move()
class VehicleModel {
    public:
    virtual void Move(double x, double theta)  = 0;
};


// TODO: Derive class ParticleModel from VehicleModel
  // TODO: Override the Move() function
  // TODO: Define x, y, and theta
class ParticleModel : public VehicleModel{
    public:
    ParticleModel(int x = 0, int y = 0, double theta = 0) : x(x), y(y), theta(theta){}
    void Move(double x, double theta) override;
    //private:
    double x;
    double y;
    double theta;
};

// TODO: Derive class BicycleModel from ParticleModel
  // TODO: Override the Move() function
  // TODO: Define L
class BicycleModel : public ParticleModel{
    public:
    //BicycleModel(int x = 0, int y = 0, double theta = 0, int L = 5) : x(x), y(y), theta(theta), L(L){}// will lead to error
    BicycleModel(int x = 0, int y = 0, double theta = 0, int L = 5) : ParticleModel(x,y,theta), L(L){}
    void Move(double x, double theta) override;
    int L;
};

void ParticleModel::Move(double v, double phi) {
    theta += phi;
    x += v * cos(theta);
    y += v * cos(theta);
}

void BicycleModel::Move(double v, double phi) {
    /*
    theta += v / L * tan(phi)
    theta += phi
    x += v * cos(theta)
    y += v * cos(theta)
    */
   theta += v/L * tan(phi);
   x += v * cos(theta);
   y += v * cos(theta);
}

// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}