#include <iostream>
#include <string>
#include"address_op_demo.hpp"


#define NB_DEMO 1
#define DEMO_CHOICE 0 // choose what demo to run

int main() {
    
std::cout << " \t ======== Hello pointers concepts in modern C++! ========" << std::endl;


// list all program we have
std::string program_list[NB_DEMO] = {"address_operator"}; // 0,

// choose some demo to run
std::string program_choice = program_list[DEMO_CHOICE] ;

if (program_choice == program_list[0])

    run_add_op_demo();


return 0;

} // End main()
