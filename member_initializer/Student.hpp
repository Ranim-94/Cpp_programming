
#pragma once

#include <string>

class Student{

private:

    std::string m_name;
    int m_start_year;
    std::string m_id;


public:

    Student(std::string name, int start_year);

    void log_info(void);


};