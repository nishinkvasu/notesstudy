#include <iostream>
#include <memory>

int main(){
    std::shared_ptr<int> mySharedPtr(new int);
    std::cout<< "shared pointer count =" << mySharedPtr.use_count() <<"\n";

    std::weak_ptr<int> weakptr1(mySharedPtr);
    std::weak_ptr<int> weakptr2(weakptr1);
    std::cout << "shared pointer count =" << mySharedPtr.use_count() <<"\n";

    // Below will lead to an error as the weakptr cannot be created directly
    // it can be created only from another weakptr or another shared ptr
    //std::weak_ptr<int> weakptr3(new int); 

    return 0;
}