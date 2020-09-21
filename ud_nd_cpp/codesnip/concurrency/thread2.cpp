#include <iostream>
#include <thread>

// need to compile with -pthread option

void threadBody(){
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 1 in thread \n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in thread \n";
}


int main(){
    std::thread t(threadBody);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<< "Finished work 1 in main \n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<< "Finished work 2 in main \n";
    // wait for thread to finish
    t.join();
    /* if above line is commented
    terminate called without an active exception
    Aborted (core dumped)
    */
    return 0;
}