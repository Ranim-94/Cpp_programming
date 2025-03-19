#pragma once

#include <iostream> 
#include <string>

/* Major class

    to be used with Student class 
    as an attribute
*/

class Major{

private:
 std::string m_major_name;

public:
 Major(std::string major_name);

 std::string get_major(void);

}; /**/