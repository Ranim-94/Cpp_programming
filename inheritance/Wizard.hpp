

#pragma once

#include<iostream>
#include<string>

/* base class header file*/
#include"Character.hpp" 

class Wizard:public Character{

private:

    std::string m_name_wizard;


public:

Wizard(std::string name,float strength,float speed,float points);

void do_some_magic(void);

// common method between derived classes: the Hero and the Wizard
void defend(void);



}; /* End class Wizard*/