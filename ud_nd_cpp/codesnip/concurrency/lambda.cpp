#include <iostream>

int main(){
    int id = 0;

    //create lambdas

    //capture list[], parameter list {body}
    //auto f0 = [](){ std::cout << "ID = "<< id << std::endl;};// id cannot be accessed

    id++;
    auto f1 = [id](){ std::cout << "ID = "<< id << std::endl;}; //pass by value

    id++;
    auto f2 = [&id](){std::cout << "ID = "<< id << std::endl;}; // pass by reference

    // auto f3 = [id](){ std::cout << "ID = "<< ++id << std::endl;} ;  // id cannot be updated

    auto f3 = [id]()mutable{ std::cout << "mutated ID = "<< ++id << std::endl; };


    auto f4 = [&id]()mutable{std::cout << "ID = "<< ++id << std::endl;};

    //passing parameter
    auto f5 = [](const int id){std::cout << "ID = "<< id << std::endl;};

    // if you run as above nothing happens, since there is no closure on lambda
    // will need to do as below

    f1();
    f2();

    f3();
    std::cout << "outside ID = "<< id << std::endl;
    
    f4();
    std::cout << "outside ID = "<< id << std::endl;

    f5(id);


    return 0;


}
