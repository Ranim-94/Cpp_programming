#include <iostream>
#include"Character.hpp"

int main() {
    
    std::cout << "Hello OOP concepts in modern C++!" << std::endl;

    // Create a instance from Character
    Character knight("John");
    // in this type of instantiation, the object is created at the stack
    // the destructor will called automatically


    // Create an instance dynamically
    Character* dynamic_knight = new Character("Sam");
    // in dynamic creation of object, destructor is not called automatically
    // we need to call it explicitly via the detele function
    delete dynamic_knight;

    // Order of deleting of constructor: the 1st object created
    // will be lastly deleted
    
    return 0;

} // End main()
