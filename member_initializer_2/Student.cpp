
#include "Student.hpp"

#include<iostream>
#include <string>


Student::Student(std::string name, int start_year, std::string major_name):
    m_name(name),
    m_start_year(start_year),
    m_id(name.append("_"+std::to_string(start_year))),
    m_major(Major(major_name)){

        /*
            Note that m_major instance
            we call inside the member initializer the constructor
            Major(std::string major_name)
        */


    }; /* End constructor*/

/*
    - In this method, we used what we call member intializer
    to initilialize the attributs of the class Student.
    after the :, the member variable m_name will be initialized
    by the value of the name

    - note that in the member initializer list [in m_id attribute], 
    we can: 
        - call functions
        - use also other attributes
        - m_id is not initialized by the constructor argument
        

*/

void Student::log_info(void){

    std::cout<<" \t - name is :"<<this->m_name<<std::endl;

    std::cout<<"\t - start year = :"<<this->m_start_year<<std::endl;

    std::cout<<"\t - id = "<<this->m_id<<std::endl;

    std::cout<<"\t - major = "<<this->m_major.get_major()<<std::endl;

} /* End log_info */

