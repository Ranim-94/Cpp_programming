#pragma once


#include<string>

class Student{

protected:
    std::string m_name;


public:
    Student(std::string name);


/* this is a pure virtual function */
virtual void log(void) = 0;

}; /* End Student */

/*

    1) Some intuitive introduction about abstract classes:

        -Suppose we have base class named Vehicle, and it has some method called
        Run()
        - the vehicle concept by self is so abstract: if we ask a person how did 
        you come at work, and it tell use he comes by a vehicle, we can assume
        that the vehicle is a car, but vehicle is an abstract concept
            - a car, a train, a tank,... all of them are vehicles

        - that's why some classes can be used as some template or blue print,
        and the their method such as the Run() , is useless to implement inside the
        base class (as we did as before)

        - it is more useful to impelemnt the Run() method inside the derived class,
        the more concrete one


    Some notes:

    - a pure virutual function is a type of virtual 
    function encountered in polymorphism before

    the pure virtual function is assigned to 0
    this tells the compiler that 
    it must redefined (implemented) in the derived classe

    - a class that contains at least 1 pure virtual
    functions is called an abstract class
     <-> in other words, when we see some some_func()=0; inside a class,
     that class is abstract

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



class Med_Student:public Student{


public:

    Med_Student(std::string m_name);

    /* the redefined function we need to redefine*/
    void log(void) override ;


}; /* End Med_Student */