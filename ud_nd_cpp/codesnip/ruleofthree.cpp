#include <stdlib.h>
#include <iostream>

class myMovableClass{
    private:
    int _size;
    int *_data;

    public:
    myMovableClass(size_t size){
        _size = size;
        _data = new int[_size];
        std::cout <<  "CREATING instance of MyMovableClass at " << this << 
            " allocated with size = " << _size*sizeof(int) << " bytes \n";
    }

    ~myMovableClass() { //1: destrcutor
        std::cout << "DELETING instance of myMovableClass at " << this << "\n";
        delete[] _data;
    }

    myMovableClass(const myMovableClass &source){ // 2: Copy Constructor
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout<< "COPYING instance of myMovable at " << &source 
                    <<" to instance " << this << "\n";
    }

    myMovableClass &operator = (const myMovableClass &source){ // 3 : Copy Assignment
        std::cout << "ASSIGNING content of instance at " << &source <<" to instance "<< this <<"\n";
        if(this == &source){
            return *this; // this check is to avoid self-assignment and standard boilerplate code for user 
            // defined assignement operator
        }
        delete[] _data; //deleting as this would be created previously
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }

    myMovableClass(myMovableClass &&source){ // 4: Move constructor
        std::cout<<"MOVING (assign) content of instance at "<< &source << "to instsance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr; // invaldiating the source
        source._size = 0;
    }

    myMovableClass &operator= (myMovableClass &&source){ // 5: MOVE ASSIGNMENT 
        std::cout << "MOVING (c'tor) content of instance at "<<&source <<" to instance "<< this << "\n";
        if(this == &source)
            return *this;
        
        delete[] _data;
        // no need to create new data again as we are moving
        // and then invalidating the previous instance
        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }
};

myMovableClass createObject(int size){
    myMovableClass obj(size);
    std::cout << " Test \n";
    return obj;
}

// int main()
// {
//     myMovableClass obj1(10);
//     myMovableClass obj2(obj1); // copy constructor
//     myMovableClass obj3 = obj1; // copy constructor
//     obj2 = obj1; //copy assignment

//     myMovableClass obj4 = createObject(10); 
//     /* while creating obj4, the data is dynamically allocated on the stack,
//      which is then copied from the temporary object to its target destination. 
//      This means that two expensive memory operations are performed with the 
//      first occurring during the creation of the temporary rvalue and 
//      the second during the execution of the copy constructor. 
//      The copy constructor will not be called if elison occurs */
//     obj4 = createObject(10); // same scenario as above

// }
// int main()
// {
//     myMovableClass obj1(100), obj2(200); // constructor

//     myMovableClass obj3(obj1); // copy constructor

//     myMovableClass obj4 = obj1; // copy constructor

//     obj4 = obj2; // copy assignment operator

//     return 0;
// }
int main(){
    //std::cout << __cplusplus << std::endl; // will return the CPP version supported
    // https://stackoverflow.com/questions/46980383/how-to-determine-what-c-standard-is-the-default-for-a-c-compiler/46980534
    myMovableClass obj1(100); // constructor
    obj1 = myMovableClass(200); // move assignment
    /*
        The advantage from a performance perspective in this case is that no deep-copy of the rvalue object needs to be made,
        we are simply redirecting the internal resource handle thus making an efficient shallow copy.
    */
    myMovableClass obj2 = myMovableClass(300); // move constructor
    // the last one is equivalent of calling myMovableClass obj2(myMovableClass(300))
    return 0;
}

// need to compile this program with g++ -fno-elide-constructors .\ruleofthree.cpp while using cpp11/cpp14
// then the move constructor part will not be optimized