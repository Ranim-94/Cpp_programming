
#pragma once

#include <string>


/* base class for all type of students*/
class Student{

protected:
// these attributed are only accessed by subclasses (= derived classes = child classes)

    std::string m_name,m_id;
    
    int m_start_year;
    
public:

    Student(std::string name, int start_year);

    ~Student();

   void log_info(void);


}; // End class Student

// ========================== Medical_Student ==========================

/* 1st derived class */
class Medical_Student : public Student{

/*

The syntax "class Medical_Student:public Student":
means class "Medical_Student" inherit public member from base class "Student"

*/

private:

std::string m_specialty;

public:

 /* Constructor */   
 Medical_Student(std::string name, int start_year,
                std::string specialty);

 /*
    Always recall that in the constructor of a derived class;
    we should input the attributes of the base class (that we inherited)

    but we don't need to declare these attributes again in the private
    section, where we declare the members (attributes of the class)
*/
 
 ~Medical_Student(); /* Destructor */


void log_med_specialty(void);

}; /* End class Medical_Student */