
#pragma once


#include <string>

/*
    Class with pointers member variables
*/

class heap_vec2{

private:
    
    
    std::string m_vec_name;

    // coordinates of the vector
    float *m_x , *m_y;

    /* 
        Note that this class uses pointers as member variables
        So in the .cpp file, we use dynamic memory when initializing the variables
    
    */

    
public:
    
    // Default Constructor
    heap_vec2(); 
    
    // Normal Constructor
    heap_vec2(std::string vec_name,float x,float y); 
    
    heap_vec2(const heap_vec2& some_vec2); // Copy constructor

    // destructor
    ~heap_vec2();

    // custom copy assignment operator
    heap_vec2& operator=(const heap_vec2& rhs_vec2);
    // We use the keyword "operator" with "=" to overload the assignment operator
    

    void set_x(float x);
    void set_y(float y);

    void set_name(std::string vec_name);

    float get_x(void);
    float get_y(void);

    void log_vec_info(void);

}; /* End class heap_vec2 */
