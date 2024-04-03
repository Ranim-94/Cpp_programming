#include <iostream>
#include <string>
#include"function_demo.hpp"
#include "run_func_demo.hpp"

#define NB_DEMO 1
#define DEMO_CHOICE 0 // choose what demo to run

int main() {
    
std::cout << " \t ======== Hello functions concepts in modern C++! ========" << std::endl;


// list all program we have
std::string program_list[NB_DEMO] = {"function_demo"}; // 0,

// choose some demo to run
std::string program_choice = program_list[DEMO_CHOICE] ;

if (program_choice == program_list[0])

    run_function_demo();


return 0;

} // End main()
