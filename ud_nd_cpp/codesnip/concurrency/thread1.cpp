#include <iostream>
#include <thread>

int main(){
     //std::cout << "Hello concurrent world from main! Thread id = " << std::this_thread::get_id() << "\n";

     // number of cores available
     auto nCores = std::thread::hardware_concurrency();
     //std::cout << "Hello!" << std::endl;
     std::cout << "The hardware support concurrency with " << nCores << " cores \n";
     return 0;
}