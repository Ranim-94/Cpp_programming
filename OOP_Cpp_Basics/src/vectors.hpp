
#pragma once

class Vector2{

    private:

    float m_x,m_y;


    public:

    // default constructor <-> No arguments required when creating 
    // an instance of the class
    Vector2();

    // parameterized constructor <-> Arguments required when creating
    // an instance of the class
    Vector2(float x, float y);

    // Getter or Accessor methods    
    float get_x(void);
    float get_y(void);

    // Setter or Mutator methods
    void set_x(float& x);
    void set_y(float& y);

    


}; /* End of class Vector2 */