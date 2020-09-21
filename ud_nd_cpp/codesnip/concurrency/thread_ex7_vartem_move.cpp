#include <iostream>
#include <string>
#include <thread>


void printName(std::string name, int waitTime){
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Name (from Thread) = " << name << std::endl;
}
//passing as reference

void printName2(std::string &name, int waitTime){
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    name += " (from thread)" ;
    std::cout << name << std::endl;
}

int main(){
    std::string name1 = "MyThread1";
    std::string name2 = "MyThread2";


    // starting threads using value copy and move semantics
    std::thread t1(printName, name1, 50);
    std::thread t2(printName, std::move(name2), 100);

    // print name from main
    std::cout << "Name (from main b4 join) = " << name1 << std::endl;
    std::cout << "Name (from main b4 join) = " << name2 << std::endl; // name2 no longer available here

    t1.join();
    t2.join();

    // print name from main
    std::cout << "Name (from main) = " << name1 << std::endl;
    std::cout << "Name (from main) = " << name2 << std::endl;

    std::string name3 = "MyThread3";

    std::thread t3(printName2, std::ref(name3), 50); 
    // need to explicitly mention as reference else compile error
    t3.join();

    name3 += " (from main) ";

    std::cout << name3 << std::endl;

    return 0;
}
