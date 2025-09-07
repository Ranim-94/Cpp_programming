
#pragma once

class Vector2{

    private:

    float m_x,m_y ;


    public:

    Vector2();// default constructor

    // overloaded constructor
    Vector2(const float& x, const float& y);

    // Copy constructor
    Vector2(const Vector2& vec2);


    float get_x(void) const;
    float get_y(void) const;

    void set_x(float& x);
    void set_y(float& y);
    



};