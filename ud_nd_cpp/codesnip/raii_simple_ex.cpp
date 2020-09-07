#include <iostream>

class MyInt{ // RAII class
public:
    int* _p;

    MyInt(int* p = NULL){
        _p = p;
    }

    ~MyInt(){
        std::cout << "resource " << *_p << " deallocated" << std::endl;
        delete _p;
    }

    int &operator *() { return *_p;}
};

int main(){
    double den[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    for (size_t i = 0; i < 5; i++){

#if 0
        double* d = new double(i);

        std::cout << *d << " / " << den[i] << " = " << *d / den[i] << "\n";

        delete d;
#else
        MyInt en(new int(i));
        /*
        The part new int(i) creates a new block of memory on the heap and initializes
         it with the value of i. The returned result is the address of the block of memory.
        The part MyInt en(…)calls the constructor of class MyInt, passing the address
         of a valid memory block as a parameter.
        */
        std::cout << *en << " / " << den[i] << " = " << *en / den[i] << "\n";

        // no need to worry about delete here as it will taken care by the RAII class
        // MyInt will object will be deleted once out of scope and hence the int on heap
#endif
    }

    return 0;
}