
#pragma once
#include<tuple>

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

    std::tuple<float,float> get_coordinates() const;

    void set_x(float x);

}; /* End class heap_vec2 */
