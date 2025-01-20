#include "vectors.hpp"


Vector3::Vector3(){

    this->m_x = -1;
    this->m_y = -1;
    this->m_z = -1;
}

Vector3::Vector3(float x, float y, float z){

this->m_x = x;
this->m_y = y;
this->m_z = z;

}

void Vector3::set_x(float& x){

this->m_x = x;



}

void Vector3::set_y(float& y){

this->m_y = y;



}

void Vector3::set_z(float& z){

this->m_z = z;

}

float Vector3::get_x(void){

    return this->m_x;

}