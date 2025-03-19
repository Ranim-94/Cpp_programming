
#include "Student.hpp"

#include<iostream>
#include <string>


Student::Student(std::string name, int start_year):
    m_name(name),
    m_start_year(start_year),
    m_id(name.append("_"+std::to_string(start_year))){


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

    std::cout<<" \t - Hi, I am student (the base class) !! "<<std::endl;
    
    std::cout<<" \t - name is :"<<this->m_name<<std::endl;

    std::cout<<"\t - start year = :"<<this->m_start_year<<std::endl;

    std::cout<<"\t - id = "<<this->m_id<<std::endl;

    std::cout<<std::endl;

} /* End log_info */


 Student::~Student(){

 std::cout << "Destructor is called for student object \n ";

 }/*End ~Student() */

Medical_Student::Medical_Student(std::string name, 
int start_year,std::string specialty):
Student(name, start_year), /* calling the base constructor */
m_specialty(specialty){ 

}

void Medical_Student::log_info(void){

/*
    - in the Student hpp file, 
    we used the virtual keyword in the base class
    - the compiler will know at run time
     which function to call    



*/
    std::cout<<" \t - Hi, I am a future Dr to be !! "<<std::endl;

    std::cout<<" \t - name is :"<<this->m_name<<std::endl;

    std::cout<<"\t - start year = :"<<this->m_start_year<<std::endl;

    std::cout<<"\t - id = "<<this->m_id<<std::endl;

    std::cout<<"\t - specialty = "<<this->m_specialty<<std::endl;

    std::cout<<std::endl;


} /* End log_info() */

Medical_Student::~Medical_Student(){

    std::cout << "Destructor is called for Med Student object \n ";

} /* End ~Medical_Student() */
