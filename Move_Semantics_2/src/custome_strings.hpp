

#pragma once
#include <cstdint>


class MyString{

private:

char* m_data;

uint32_t m_size;


public:

    // Constructor
    MyString(const char* string);

    ~MyString();

    void print_str();


}; /* End Mystring */ 

class Str_Entity{

/* This class consumes the MyString class  */

private:

MyString m_name;
// Member variable is an object of type MyString

public:

    Str_Entity(const MyString& name);

    void print_name();



};/* End Str_Entity */

