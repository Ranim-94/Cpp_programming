#include <iostream>
#include <string>
#include "function_demo.hpp"
#include "run_func_demo.hpp"
#include "ampersand_operator.hpp"

#define NB_DEMO 2
#define DEMO_CHOICE 0 // choose what demo to run

int main() {
    
std::cout << " \t ======== Hello functions concepts in modern C++! ========" << std::endl
<< std::endl;


// list all program we have
std::string program_list[NB_DEMO] = {"function", // 0
"& operator"}; // 1,

// choose some demo to run
std::string program_choice = program_list[DEMO_CHOICE] ;

std::cout<<"Running "<<program_choice<<" demo"<<std::endl<<std::endl;

if (program_choice == program_list[0])

    run_function_demo();

else if (program_choice == program_list[1])

    run_ampersand_operator_demo();


return 0;

} // End main()
