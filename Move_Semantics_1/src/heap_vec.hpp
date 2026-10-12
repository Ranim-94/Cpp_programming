
#pragma once
#include<string>
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
    
    heap_vec2(const float x,const float y); // Normal Constructor
    
    heap_vec2(const heap_vec2& some_vec2); // Copy constructor

    heap_vec2(heap_vec2&& some_vec2) noexcept; // Move constructor

    // destructor
    ~heap_vec2();

    // custom copy assignment operator
    heap_vec2& operator=(const heap_vec2& rhs_vec2);
    // We use the keyword operator with = to overload the assignment operator
    

    std::tuple<float,float> get_coordinates() const;


    float get_x() const;
    float get_y() const;

    void set_x(float x);

}; /* End class heap_vec2 */

// ==========================================


class Vec_Entity{

 private:
    heap_vec2 m_vec2; 
    // the member variable here is an object
    
    

public:

    Vec_Entity(const float& x,const float& y);

    // Move constructor: takes an argument of rvalue reference type
    Vec_Entity(Vec_Entity&& other);

   

    void printVec_info(const std::string& vec_name);




}; /* End Class VecInfo */



