

#include"src/vectors.hpp"

#include <iostream>

int main(){

    // Setting some initial coordinates
    float x{5}, y{10};

    // Instantiating objects using different constructors

    Vector2 v1{x,y,"v1"}; // normal constructor
    //giving v1 some coordinate and a name

    v1.log_vec(); // for v1

    Vector2 v2; // default constructor
    /* Notice that no {} are used */

    v2.log_vec(); // for v2    
    
  
    // Some heap allocated object v3
    Vector2* v3 = new Vector2{15,20,"v3"}; // normal constructor

    std::cout << " \t -> Heap allocated vectors" << std::endl;

    v3->log_vec();// note that for heap objects, we use -> operator

    delete v3; // Don't forget to free the allocated memory
    // because destructor is not called automatically for heap allocated objects

    return 0;

} /* End main() */

