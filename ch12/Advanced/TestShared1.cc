/**
 * important features of std::shared_ptr -
 * 		1. They are twice the size of raw pointer (or unique_ptr), because we need another pointer pointing to the control block which consists of the reference count object.
 * 		2. Increments and decrements on the reference count should be atomic, since shared_ptrs can be spread out in different threads. If two threads decrement the reference count, they should be ordered using atomic variables or mutex ( one after the other), otherwise we might lose one decrement. 
 * 
 * move 不改变信息
 * 
 * deleters is not a part of the shared_ptr itself.
 * This is because the captured variables is not part of shared_ptr, but is allocated in the free space within the control block.
 * ref this code
 * 
 * It should also be noted that we cannot use make_shared when supplying custom deleter.
 * 
 * The smart pointers namely the std::unique_ptr and std::shared_ptr are realizations of RAII ( Resource Allocation Is Initialization ) concept.
 * RAII is a technique where the programmer does not have to explicitly do and undo a action or set of actions on a resource
 * ( for example, creating and freeing memory, opening /closing database connections, locking and unlocking of the mutex etc). 
 * 
 * 
 * 
 * Effective Modern C++ by Scott Meyers.
 */ 

#include <iostream>
#include <memory>
using namespace std;

int main() {
	float ft = 9.8f;
	auto deleterFunc = [ft](int* xp)
	{
		cout << ft << '\n';
		cout << "Deleting " << *xp << '\n';
		delete xp;
	};

	std::shared_ptr<int> sPtr1(new int(10));
	std::shared_ptr<int> sPtr2(new int(11), deleterFunc);
	std::unique_ptr<int> uPtr1(new int(12));
	std::unique_ptr<int, decltype(deleterFunc)> uPtr2(new int(13), deleterFunc);

	cout << "*sPtr1 = " << *sPtr1 << ". Size =  " << sizeof(sPtr1) << '\n';
	cout << "*sPtr2 = " << *sPtr2 << ". Size =  " << sizeof(sPtr2) << "\n\n";

	cout << "*uPtr1 = " << *uPtr1 << ". Size =  " << sizeof(uPtr1) << '\n';
	cout << "*uPtr2 = " << *uPtr2 << ". Size =  " << sizeof(uPtr2) << '\n';

	return 0;
}


/* Output in gcc 6.3
*sPtr1 = 10. Size =  16
*sPtr2 = 11. Size =  16
*uPtr1 = 12. Size =  8
*uPtr1 = 13. Size =  16
9.8
Deleting 13
9.8
Deleting 11
*/