
#pragma once

#include<string>

class Vector2{

    private:
    
    float m_x,m_y; // cartesian coordinate

    std::string m_vec_name , m_vec_id;

    public:

    // default constructor <-> No arguments required when creating 
    // an instance of the class
    Vector2();

    // parameterized constructor <-> Arguments required when creating
    // an instance of the class
    Vector2(float x, float y, std::string vec_name);

    // Getter or Accessor methods    
    float get_x(void);
    float get_y(void);

    // Setter or Mutator methods
    void set_x(float& x);
    void set_y(float& y);

    // Some logging method
    void log_vec(void);

    


}; /* End of class Vector2 */