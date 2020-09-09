#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> shared1(new int(5));

    std::cout<< "Reference counter value = " << shared1.use_count() <<"\n";
    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout<< "Reference counter value = " << shared2.use_count() <<"\n";
    }

    std::cout<< "Reference counter value = " << shared1.use_count() <<"\n";

    return 0;

}
