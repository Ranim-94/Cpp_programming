
#pragma once

class Vector3{

    private:

    float m_x,m_y,m_z ;


    public:

    Vector3();// default constructor

    Vector3(float x, float y, float z);

    void set_x(float& x);
    void set_y(float& y);
    void set_z(float& z);

    float get_x(void);


};