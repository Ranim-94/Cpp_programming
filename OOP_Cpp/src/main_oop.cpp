#include <iostream>
#include "run_basic_oop.hpp"
#include "run_objects_copy.hpp"

#define NB_DEMO 2
#define DEMO_CHOICE 1 // choose what demo to run

int main() {
    


// list all program we have
std::string program_list[NB_DEMO] = {"basic_oop", // 0
"copy_objects"}; // 1,


// choose some demo to run
std::string program_choice = program_list[DEMO_CHOICE] ;

std::cout<<"Running "<<program_choice<<" demo"<<std::endl<<std::endl;


    if (program_choice == program_list[0])

        run_basic_oop();

    else if (program_choice == program_list[1])

        run_objects_copy();

    
    return 0;

} // End main()

/*
    Main points to remember:

1- In Cpp, we are provided by a default a
constructor and a desctructor;
    - defautl constructor takes no parameter
    - it is not ncessary to have a definition of the consturctor in
        .cpp implementation files 

2- Each time a constructor is called, behind the
seens the constructor will allocate memory
for the variables (the attributes)
    - but it won't initialize them

3- Usually we override the default constructor
because we want a series of actions or algorithm
when calling the constructor, and initilizaing 
our attributes



*/
