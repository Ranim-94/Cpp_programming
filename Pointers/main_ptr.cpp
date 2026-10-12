#include <iostream>
#include <string>

#include "ptr_basics.hpp"
#include "raw_array.hpp"
#include "dynamic_array.hpp"
#include "l_r_value.hpp"


#define NB_DEMO 4

/* choose what demo to run */
#define DEMO_CHOICE 3

int main() {
    
std::cout << " \t ======== Hello ptr concepts in modern C++! ========" << std::endl
<< std::endl;


// list all program we have
std::string program_list[NB_DEMO] = {"ptr_basics", // 0
"array_cpp", // 1
"dynamic_arr",// 2
"l_r_value"}; // 3

// choose some demo to run
std::string program_choice = program_list[DEMO_CHOICE] ;

std::cout<<"Running "<<program_choice<<" demo"<<std::endl<<std::endl;

if (program_choice == program_list[0])

    run_ptr_basics();

else if (program_choice == program_list[1])

    run_raw_array();    

else if (program_choice == program_list[2])

    run_dynamic_array();

else if (program_choice == program_list[3])

    run_l_r_value();


return 0;

} // End main()
