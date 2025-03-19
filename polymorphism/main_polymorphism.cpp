
#include "src/Student.hpp"
#include "src/helper_function.hpp"

#include <iostream>

int main(void){

std::cout<<"Polymorphism demo  "<<std::endl;

/* instantiating some base class */    
Student stud_1("John",2014);

/* instantiating some derived class */    
Medical_Student med_1("king",2014,"Radiology");

/* Polymorphism starts here */

/* Declaring a base class pointer*/
Student* stud_ptr;

/* 1- Assigning ptr base class to a derived class*/
stud_ptr = &med_1;

std::cout<<"\t 1- Logging info via Student* stud_ptr = &med_1 \n";

stud_ptr->log_info();

/* 2- assignigng the base ptr to the base class now*/
    
stud_ptr = &stud_1;

std::cout<<"\t 2- Logging info via Student* stud_ptr = &stud_1 \n";

stud_ptr->log_info();


/* 3- doing the same thing but via a local function
    Just to see different ways to run polymorphism
*/

std::cout<<"\n \t -> Running polymorphism via local function \n ";

somefunction(med_1);


/* notice that in the implemetation
we have Square& sqr = med1;

 -> the somefunction(Student& std)
   - the Medical_Student is indeed is a Student
   - that' why we can use it and pass it to the function
   - but we need to include the virtual keyword to know
   what version of the log_info() method will be called



*/


/* 4- Polymorphism and array of pointers */


/* Note that the array type is always 
    belong to the base class
*/
Student* stud_ptr_arr[] = {new Student("Tom1",2016), 
                        new Medical_Student("Jack",2018,"Skin dr")};


for (Student* std_ptr:stud_ptr_arr){

std_ptr->log_info();

} /* End for loop */


/* Deleting allocated objects from the heap */
for (Student* std_ptr:stud_ptr_arr){

 delete std_ptr;

} /* End for loop */


} /* End main() */


/*

Main idea of polymorphism:


- let's start by some formal definition

 -it allows object references or object pointers
    - to reference object of different types
    - to call different member functions depending on the type of
        object being reference

    - in other words, we can assign differnt type of objects
        to the same reference or the same pointer

- in other words also, we can see polymorphism as
as form of treating a child as a parent
    - this is a form of generic code
    - it help us to treat all the childs as some sort of parent
      - and help to group them inside 1 container
      - the example of using array is an example of this

- 3rd meaning for the polymorphism:
    - concerning the functions, take as an example a game
    - the game has many type of machines [this is the base class]
        - such as: ship, tank,...
        - all the machines can attack() [this is the method]
        - we can treat all the subclasses as a parent,
        an use the correct version of attack() method
        - the polymorphism can help us treat the childs
        as generic as possible, having similar logic
        and conserving the specialty of each attack() method



also, we can group many child in 1 base class ptr,
loop over all of them and make each one of them
do its unique thing
 
 
- virtual void log_info(void);
    - the keyword virtual generate a V-table for this function
    - it tells the compiler to make a match between the correct
    version of the function

*/
