#include <iostream>

//the function takes rvalue as a parameter
void myFunc(int &&val){
    std::cout << "val = "<< val <<"\n";
}

int main(){
    myFunc(42); // rvalue is being passed here

    int i = 23;
    //myFunc(i); //error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
    myFunc(std::move(i)); // now converting lvalue into rvalue using move semantics
    return 0;
}
/*
Passing values like this improves performance as no temporary copy
needs to be made anymore

ownership changes - object the reference binds to has been abandoned
by caller, now binds to handle available only to receiver
Not possible through lvalue references
*/