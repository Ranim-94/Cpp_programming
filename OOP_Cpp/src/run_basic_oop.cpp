
#include "run_basic_oop.hpp"

#include "Character.hpp"

void run_basic_oop(void){

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



} /* End run_basic_oop() */