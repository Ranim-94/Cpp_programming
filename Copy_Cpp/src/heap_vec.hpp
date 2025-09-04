
#pragma once
#include<tuple>


/* Note that this class uses dynamic memory allocation 
   since the member variables are pointers
*/

class heap_vec2{

private:
    
    // coordinates of the vector
    float *m_x , *m_y; 

public:
    
    heap_vec2(); // Default Constructor
    
    heap_vec2(float x,float y); // Normal Constructor
    
    heap_vec2(const heap_vec2& some_vec2); // Copy constructor

    // destructor
    ~heap_vec2();

    // custom copy assignment operator
    heap_vec2& operator=(const heap_vec2& rhs_vec2);
    // We use the keyword operator with = to overload the assignment operator
    

    std::tuple<float,float> get_coordinates() const;

    void set_x(float x);

}; /* End class heap_vec2 */
