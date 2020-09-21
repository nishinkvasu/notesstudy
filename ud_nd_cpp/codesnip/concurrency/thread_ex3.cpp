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

    // The destructor of a detached thread does nothing: 
    // It neither blocks nor does it terminate the thread.
    t.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<< "Finished work 1 in main \n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<< "Finished work 2 in main \n";

    return 0;
}
