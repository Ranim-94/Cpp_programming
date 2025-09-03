
#pragma once

#include <string>


/* base class for all type of students*/
class Student{

protected:

    std::string m_name;
    int m_start_year;
    std::string m_id;


public:

    Student(std::string name, int start_year);

    virtual ~Student();

   virtual void log_info(void);


};

/* 1st derived class */
class Medical_Student:public Student{

private:

std::string m_specialty;

public:

 /* Constructor */   
 Medical_Student(std::string name, int start_year,
                std::string specialty);

 virtual ~Medical_Student(); /* Destructor */

/*
    Always recall that in the constructor of a derived class;
    we should input the attributes of the base class (that we inherited)

    but we don't need to declare these attributes again in the private
    section, where we declare the members (attributes of the class)
*/


void log_info (void) override;

/*
   the override keyword meaninig:
   overriding implies that we are not creating a new function log_info()
   instead, we are modifying the behavior of the base class function and
   redefining it for the derived class
*/


}; /* End class Medical_Student */