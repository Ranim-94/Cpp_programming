

/*

    Read README_heap_copy_vec.md to see 
    analysis, some points about the code

*/

#include <iostream>

#include "src/heap_vec.hpp"

int main(){

    
    heap_vec2 v1{"v_1",5,10}; // normal constructor

    v1.log_vec_info();


    // Creating object vector v2 and initialize it to v1
    heap_vec2 v2 = v1; // copy constructor
    
    /*
     Note that in this case, it is not the normal constructor of
     v2 will be called, it is the copy constructor using v1
     will be called, and it will take heap_vec2 v1 as argument
    
    */
        

    v2.set_name("v_2");

    std::cout<<"\t Logging v_2 info before changing x value"<<std::endl<<std::endl;
    v2.log_vec_info();


    // Changing v2 now: setting a new x coordinate
    std::cout<<"\t -> Changing v_2 x value"<<std::endl;
    v2.set_x(15);

    std::cout<<"\t Logging v_2 info after changing x value"<<std::endl<<std::endl;
    v2.log_vec_info();

    std::cout<<"\t Logging v_1 info to check "<<std::endl<<std::endl;
    v1.log_vec_info();

   
    /*
        
        !! NOTE !!

        if a custome proper copy constructor is implemented
        v1 won't be affected by the change in v2

        If no copy constructor is implemented
        v1 will be affected by the change in v2

    */

    // =========== Custome Copy Assignment Operator =============

    std::cout<<std::endl; // skip a line
    
    std::cout << "\t =========== Custome Copy Assignment Operator =============" 
    << std::endl<< std::endl;

    heap_vec2 v3; // default constructor
    // v3 is (-1,-1)

    v3.set_name("v_3");

    std::cout << "\t -> v3 info (before assignment): " << std::endl<< std::endl;

    v3.log_vec_info();

    // create some 4th vector
    heap_vec2 v4{"v_4",20,30}; // normal constructor

    v3 = v4; // custom copy assignment operator
    // we are assigning v4 to v3 -> result should be x = 21 and y = 31

    std::cout << "\t -> v3 info (after assignment): " << std::endl<< std::endl;
    
    v3.log_vec_info();


    std::cout << "\t ============ END Program ============ "<<std::endl<<std::endl;


    return 0;


} // End main()


/*
    Notes:

    In this example, we demonstrated the use of a copy constructor for a class that manages its own dynamic memory. The copy constructor ensures that when we create a new object as a copy of an existing one, the new object gets its own separate copy of the dynamically allocated memory. This prevents issues like double deletion and ensures that each object manages 
    its own resources properly.

    The members of the class are pointers, and the constructor
    initializes them dynamically using new keyword.

    When creating object v2 (line 18) and initilize them by v1,
    we need to have copy constructor defined in the class, which
    allocate different memory space, then we can assign the values we need

    By this way when the program ends and destructor called, memory will
    be clean correctly, and no deletion issues will arise by calling delete operator twice on the same memory address.
    twice on the same memory location.

*/