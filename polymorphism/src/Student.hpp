
#pragma once

#include <string>

class Student{

protected:

    std::string m_name;
    int m_start_year;
    std::string m_id;


public:

    Student(std::string name, int start_year);

    virtual ~Student();

   // virtual void log_info(void);

   virtual void log_info(void);


};


class Medical_Student:public Student{

private:

std::string m_specialty;

public:

 /* Constructor */   
 Medical_Student(std::string name, int start_year,std::string specialty);

 virtual ~Medical_Student(); /* Destructor */

/*
    Always recall that in the constructor of a derived class;
    we should input the attributes of the base class (that we inherited)

    but we don't need to declare these attributes again in the private
    section

*/


void log_info (void) override;

}; /* End class Medical_Student */