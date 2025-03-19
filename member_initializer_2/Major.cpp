#include "Major.hpp"


Major::Major(std::string major_name):
m_major_name(major_name){};

std::string Major::get_major(void){

    return this->m_major_name;
    
}/* End log_major() */