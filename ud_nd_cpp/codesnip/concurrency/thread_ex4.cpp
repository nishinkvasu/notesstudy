#include <iostream>
#include <thread>

class Vehicle{
    public:
    Vehicle(int id):_id(id){
        std::cout << "Vehicle constructor \n";
    }
    void operator()(){
        std::cout<<"Vehicle object with id " << _id <<" has been created \n";
    }
    private:
    int _id;
};

int main(){
    // three ways of passing function object to thread

    //std::thread t0 (Vehicle()); // wont work; vexing syntax

    std::thread t1((Vehicle(1))); // Add extra braces
  //  std::thread t2 = std::thread(Vehicle(2)); // Copy Initialization

  //  std::thread t3{ Vehicle(3)}; // uniform initialization

    std::cout<< "Work in main finished \n";

    /*
        Whichever option we use, the idea is the same: 
        the function object is copied into internal storage accessible
         to the new thread, and the new thread invokes the operator ()
    */

    t1.join();
   // t2.join();
   //  t3.join();

    return 0;
}