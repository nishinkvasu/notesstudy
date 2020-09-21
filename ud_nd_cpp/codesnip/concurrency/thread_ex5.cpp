#include <iostream>
#include <thread>

int main(){
    int id = 0;

    // pass by reference 
    auto f0 = [&id](){
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "a) Value of ID in thread t1 = " << id << std::endl;
    };

    std::thread t1(f0);

    // pass by value
    auto f1 = [id]()mutable{
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "b) Value of ID in thread t2 = " << id << std::endl;      
    };

    std::thread t2(f1);

    ++id;
    std::cout << "c) Value of ID in main " << id << std::endl;

    t1.join();
    t2.join();

    return 0;

}