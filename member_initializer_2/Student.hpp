
#pragma once

#include "Major.hpp"

#include <string>

class Student{

private:

    std::string m_name;
    int m_start_year;
    std::string m_id;
    Major m_major; /* Major class*/

    /*
        Now in this part, the Student class
        has as member the Major class also
    */


public:

    Student(std::string name, int start_year, std::string major_name);

    void log_info(void);


};