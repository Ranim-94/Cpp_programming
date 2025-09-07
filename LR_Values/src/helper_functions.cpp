
#include"helper_functions.hpp"


int double_data(int input){

    int res = 2*input;

    return res;

} /* End double_data() */

int double_data_by_reference(int& input){

    int res = 2*input;

    return res;

} /* End double_data() */

int double_data_by_reference_const(const int& input){

    int res = 2*input;

    return res;


}/* End double_data() */

int double_data_by_reference_rvalue(int&& input){

    int res = 2*input;

    return res;

}/* End double_data() */