#include <iostream>
#include <memory>
#include <string>

class MyClass{
    private:
    //std::string _text; //Actually here moved to public to test on the string

    public:
    std::string _text;
    MyClass(){}
    MyClass(std::string text) { _text = text; }
    ~MyClass(){ std::cout <<_text << " destroyed \n"; }
    void setText(std::string text) { _text = text; }
};

int main(){
    int a;
    int* b = new int(5);

    std::cout << "stack address = " <<&a << " heap address = " << b <<"\n";
    std::unique_ptr<MyClass> myClass1(new MyClass());
    std::unique_ptr<MyClass> myClass2(new MyClass("String 2")); 

    myClass1->setText("String 1");

    *myClass1 = *myClass2;

    std::cout<< "Objects have address " << &myClass1<< " and " << &myClass2 << std::endl;
    std::cout<< "Objects have raw address " << myClass1.get() << " and " << myClass2.get() << std::endl;
    
    // std::string::iterator it = myClass1->_text.begin();
    // char* _ptr = &(*it);
    // int* pttr = (int *)&_ptr[0];
    // std::cout << "beginning of class1 string - " << (char *)pttr << " is here "<<pttr<< "\n";

    // it = myClass2->_text.begin();
    // pttr = (int *) &(*it);
    // std::cout << "beginning of class2 string - " << (char *)pttr << " is here "<<pttr<< "\n";

    delete b;
    return 0;
}
