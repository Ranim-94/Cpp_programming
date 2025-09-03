

#include <iostream>
#include <memory> // to use smart pointers

int main(){



 int var = 5; /* initializing some variable */    

 
 /* assgning memory usign pointer */

 std::unique_ptr<int> var_ptr = std::make_unique<int> (var);
 
std::cout<<"Unique pointer logs"<<std::endl;

 std::cout<<"\t -> var value = "<<*var_ptr<<std::endl;

 std::cout<<"\t -> var address = "<<var_ptr.get()<<std::endl;


 std::cout<<std::endl;

 // shared pointer
int var_2 = 6;

std::shared_ptr<int> var2_ptr = std::make_shared<int>(var_2);

// shared pointer allow copy and assignment
std::shared_ptr<int> var3_ptr = var2_ptr;

std::cout<<"shared pointer logs"<<std::endl;

 std::cout<<"\t -> var_2 value = "<<*var2_ptr<<std::endl;

 std::cout<<"\t -> var_2 address = "<<var2_ptr.get()<<std::endl;

 std::cout<<"\t -> assgning std::shared_ptr<int> var3_ptr = var2_ptr"<<std::endl;

 std::cout<<"\t\t -> var3_ptr address = "<<var3_ptr.get()<<"| value = "<<*var3_ptr<<std::endl;

 std::cout<<std::endl;


} /* End main() */


/* Main Notes for smart pointers:
    - smart pointers handle delete for us
       once out of scope, it will free the memory for us

    - it can't be assigned like regular raw pointers
    I can't make some_smart_ptr_2 = some_smart_ptr_1
    I can use std::move -> some_smart_ptr_2 = std::move(some_smart_ptr_1) 
    and this will make the some_smart_ptr_1 = nullptr
*/

/* Main Notes for shared pointers:
 
    - Unlike unique pointers, shared pointers allow sharing 
        - we can say std::share_ptr some_ptr = var2_ptr; // var2_ptr already created above

    - As application, shared pointer used allot
        - For example, in games, texture and assets are supposed to be shared between
        objects -> so sharing here is good idea

    - shared pointer are also managed automatically -> free automatically for us

    - As for deleteion, if we have we some shared pointer among different variable, objects,...
    the memory 

*/

/* Main Notes: Weak pointers

    - weak pointers are created only from other existig type

        - example: std::weak_ptr<int> ptr_weak = var2_ptr
            where var2_ptr is the shared created pointer early on

        - there is no std::weak_ptr<int> ptr_weak = std::make_weakptr<>()
            it doesn't exist

    - weak pointers doesn't increment the ref count as in shared pointer case

    - to access value: we need to use lock() method, and it will create another shared
    pointer from this weak_ptr
        - -> std::shared_ptr<int> ptr_shared_from_weak = ptr_weak.lock()


    TODO: some use cases maybe for weak_ptr later


*/
