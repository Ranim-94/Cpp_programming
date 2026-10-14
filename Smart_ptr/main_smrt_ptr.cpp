

#include <iostream>
#include <string>
#include <print>
#include <format>

#include <memory> // use smart pointers


// user defined type
class UDT{

public:
	UDT(){

		std::println("Default Constructor called");
	}

	~UDT(){

			std::println("Destructor called");
		}

}; // End UDT



int main(){



 std::unique_ptr<UDT> x = std::make_unique<UDT>();

 /*
  *  x --> UDT in memory <-> x is pointing to UDT in memory
  *
  *  In unique ptr, copy (pointing to same data) is not allowed
  *  but moving is allowed
  *  	- Example:
  *  		std::unique_ptr<UDT> y = std::move(x);
  *
  *
  * 2) unique pointers are scoped pointers
  * 	their liftime end with the scope of {}, or the block
  * 	of code
  *
  *
  * */

 // create an array of objects
 std::unique_ptr<UDT[]> x_arr = std::make_unique<UDT[]>(3);
 

std::shared_ptr<UDT> ptr_sh_udt = std::make_shared<UDT>();

// shared pointers allows sharing

/*
    shared pointers allow sharing
        so both pointers pointing to same resources

    Also shared pointers are scoped pointers, as the unique pointers

    shared pointer keep track of the object by having a reference count
        that is , how many pointers are pointing to the same resources

*/

{

    std::shared_ptr<UDT> ptr_sh_udt_2 = ptr_sh_udt;

    std::string count_obj_udt = 
    std::format("UDT count using shared pointers (ptr 1) before scope = {}",
    		ptr_sh_udt.use_count());

    std::string count_obj_udt_2 =
        std::format("UDT count using shared pointers (ptr 2) before scope = {}",
        		ptr_sh_udt_2.use_count());

    /*
     *  Both for 'ptr_sh_udt_2' and 'ptr_sh_udt'
     *  we should see use_count() gives 2
     *
     *
     * */



    std::println("{}",count_obj_udt);

    std::println("{}",count_obj_udt_2);


} // End scope for 'ptr_sh_udt_2'

    std::string count_obj_udt_after =
    std::format("UDT count using shared pointers after scope = {}",
    ptr_sh_udt.use_count());

    std::println("{}",count_obj_udt_after);



    


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
