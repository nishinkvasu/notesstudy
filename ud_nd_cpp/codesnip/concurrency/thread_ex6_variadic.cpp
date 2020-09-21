#include <iostream>
#include <string>
#include <thread>

void printID(int id){
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "ID = " << id << std::endl;
}

void printIDAndName(int id, std::string name){
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "ID = "<< id <<", name = "<< name << std::endl;
}

int main(){
    int id = 0;

    // starting threads using variadic templates
    std::thread t1(printID, id);

    std::string name = "thread with id and string";

    id++;

    std::thread t2(printIDAndName, id, name);

    //std::thread t3(printIDAndName, id); // compiler error

    //std::thread t4(printID, id, name);

    id++;

    std::cout << "Main thread id = "<< id << std::endl;

    t1.join();
    t2.join();

    return 0;

}