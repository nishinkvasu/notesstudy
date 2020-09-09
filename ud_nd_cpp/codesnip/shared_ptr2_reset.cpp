#include <iostream>
#include <memory>

class myClass{
    public:
    ~myClass() { std::cout << "Destructor of myClass called \n"; }
};
int main(){
    std::shared_ptr<myClass> shared(new myClass);
    std::cout << "shared pointer count = "<< shared.use_count() << "\n";

    shared.reset(new myClass);
    std::cout<< "shared pointer count = "<< shared.use_count() << "\n";
    return 0;
}