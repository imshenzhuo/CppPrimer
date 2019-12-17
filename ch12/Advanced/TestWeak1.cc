/**
 *   Weak pointers cannot be dereferenced or checked against null.
 * 
 *  这样引入了竞争机制
 */ 

#include <iostream>
#include <memory>
using namespace std;

int main()
{
	std::shared_ptr<int> sp = std::make_shared<int>(23);
	std::weak_ptr<int> wpr(sp);
	std::weak_ptr<int> wpr1{ sp };  // uniform initialization.

	std::shared_ptr<int> sp2 = std::make_shared<int>(24);
	
	// Existing weak pointer made to point to new shared pointer.
	// Not recommended, but possible.
	wpr = sp2;   
	
	// the weak pointer expired API is used to check if the weak pointer is 
	// pointing to a non dangling shared pointer
	if (!wpr.expired())  
	{
		std::cout << "Weak pointer pointing to valid shared ptr\n";
		std::shared_ptr<int> spNew{wpr};
		std::cout << *spNew << '\n';
	}
}