

#include<iostream>
#include<string>
#include<format>
#include<print>


int main(){


	std::string my_string{"copy construct me"};

	std::string new_str{};

	std::cout<<std::format("\t -> my_string is: {}",my_string)<<std::endl;

	std::cout<<std::format("\t -> new_str is: {}",new_str)<<std::endl;

	// using std::move()

	new_str = std::move(my_string);

	// printing values after using 'std::move()'

	std::println("\t -> After using std::move()");

	std::cout<<std::format("\t\t -> my_string is: {}",my_string)<<std::endl;

	std::cout<<std::format("\t\t -> new_str is: {}",new_str)<<std::endl;

	return 0;

} // End main()
