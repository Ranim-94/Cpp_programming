

#include"src/vectors.hpp"

#include<iostream>

int main(){

// setting up parameters    
float x = 1.5f, y = 2.5f, z = 3.5f;

// create an instance of some vector
Vector3 my_vec_1{x,y,z};

Vector3 my_vec_2; // this with a default constructor
/*
    Notice that since we are creating this instance
    with a defautl constructor, no need to ()
*/

std::cout<<"\n \t 1-Copy Assignment Operator \n \n";

std::cout<<"x coordinate for my_vec_2 (default constructor) before copy = "
<<my_vec_2.get_x()<<std::endl;

// apply an assignemnt
my_vec_2 = my_vec_1;
// In fact, this is known as copy assignment operator
// It copy the content of my_vec_1 to my_vec_2
// But important: the copy assignment operator
// doesn't create new object 
// In other words, copy assignment operator
// is for objects already constructed

std::cout<<"x coordinate for my_vec_2 (default constructor) after copy = "
<<my_vec_2.get_x()<<std::endl;

// ============== Copy constructor ==============

/*
    Copy constructor indeed (unlike copy assignment operator)
    create new object

*/

std::cout<<"\n \t 2- Copy constructor section \n\n";

// Here we have use the copy constructor
Vector3 my_3rd_vec = my_vec_1;

/*
    Note that in copy constructor,
    a new object is created and initialized (my_3rd_vec)
    with the values from the original object my_vec_1.

*/

std::cout<<"x coordinate for my_3rd_vec using a copy constructor = "
<<my_3rd_vec.get_x()<<std::endl;

// let's change some element of my_vec_1

std::cout<<"-> Changing the x value of my_vec_1"<<std::endl;

float new_x = 5;
my_vec_1.set_x(new_x);

std::cout<<"\t - new x coordinate for my_vec_1  = "
<<my_vec_1.get_x()<<std::endl;

std::cout<<"\t - x coordinate for my_3rd_vec  = "
<<my_3rd_vec.get_x()<<std::endl;



    return 0;


} /* End main()*/


/*
    Notes: 
    
    Copy constructor:
        used to initialize member of objects using another
        objects

      - syntax of copy constructor: we pass a const reference to the 
        object we want to copy

      Vector3(const Vector3& other):
      m_x(other.m_x), m_y(other.m_y), m_z(other.m_z) {
        // Copy constructor body (if needed)
      }

      - it is different the pure assignment operator
        because it creates a new object and initializes it
        with the values from the original object.


    Usage:
        used when we have some members created dynamically

        1- we dynamically allocate a space but using a different
        memory addresse

        2- then we can assign the values we need 


   By this way when the program ends, the destructors for both objects will be called,
   and the dynamically allocated memory will be properly released.
   because each object has a different memory address, and we 
   won't call delete operator twice on the same memory address.

*/