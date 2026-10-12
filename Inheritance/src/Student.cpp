

#include "Student.hpp"

#include<iostream>



Student::Student(std::string name, int start_year):
    m_name{name},
    m_id{name.append("_"+std::to_string(start_year))},
    m_start_year{start_year}{


    }; /* End constructor*/



void Student::log_info(void){

    std::cout<<"\t\t - Hello my name is "<<this->m_name<<std::endl;
    std::cout<<"\t\t - start year = "<<this->m_start_year<<std::endl;
    std::cout<<"\t\t - id = "<<this->m_id<<std::endl;

    std::cout<<std::endl;

} /* End log_info */


 Student::~Student(){

 std::cout << "Destructor is called for student object \n ";

 }/*End ~Student() */

Medical_Student::Medical_Student(std::string name, 
int start_year,std::string specialty):
Student{name, start_year}, /* calling the base constructor */
m_specialty{specialty}{ 

}



Medical_Student::~Medical_Student(){

    std::cout << "Destructor is called for Med Student object \n ";

} /* End ~Medical_Student() */


void Medical_Student::log_med_specialty(void){


std::cout<<"\t\t\t - My specialty in medicin is "<<this->m_specialty<<std::endl; 


} // End 