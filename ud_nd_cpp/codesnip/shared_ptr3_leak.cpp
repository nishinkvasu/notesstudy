#include <iostream>
#include <memory>

class MyClass{
    public:
    std::shared_ptr<MyClass> _member;
    ~MyClass() { std::cout << "Destructor of myClass called : \n";}
};

int main(){
    std::shared_ptr<MyClass> myClass1(new MyClass);
    std::shared_ptr<MyClass> myClass2(new MyClass);
    // With the two below lines of code the destructor will not be called
    // since there is a circular reference of the shared pointers and 
    /*
    When myClass1 goes out of scope at the end of main, its destructor 
    can’t clean up memory as there is still a reference count of 1 in 
    the smart pointer, which is caused by the shared pointer _member in myClass2.
    */
    myClass1->_member = myClass2;
    myClass2->_member = myClass1;
    return 0;
}

