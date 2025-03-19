#pragma once


#include<string>

class Student{

protected:
    std::string m_name;


public:
    Student(std::string name);


/* this is a pure virtual function */
virtual void log(void) = 0;

/*
    Some notes:

    - a pure virutual function is a type of virtual 
    function encountered in polymorphism before

    the pure virtual function is assigned to 0
    this tells the compiler that 
    it must redefined (implemented) in the derived classe

    - a class that contains at least 1 pure virtual
    functions is called an abstract class

    An abstract base class can't be instantiate
    it is only meant to derived from
        - this is because the pure virtual functions
        of this abstract are not implemented
        - they are acting as some template
        and the derived class will have the spec for the implementation

    - In other languages, this feature of pure virtual function
    are also known as interface
    

    - So the difference between pure virtual function
    and virtual function that in the base class,
     -we are no longer has this type of default implementation
      in the base class as in the case of normal virtual function
     
    
    

*/

}; /* End Student */

class Med_Student:public Student{


public:

    Med_Student(std::string m_name);

    /* the redefined function we need to redefine*/
    void log(void) override ;


}; /* End Med_Student */