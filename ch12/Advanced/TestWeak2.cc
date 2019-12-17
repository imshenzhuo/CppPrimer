/***
 * Hence there was a necessity of creating a mechanism which performs the check and create a new shared_ptr atomically. 
 * In fact there are two mechanisms for it -
 * 1. Using the lock API
 *   shared_ptr<int> sp2 = wpr.lock();
 * 
 * This API creates a new shared_ptr, sp2,  if wpr is still valid.Otherwise sp2 is set to null.
 * 
 * 2. Using shared_pointer constructor
 *    shared_ptr<int> sp2(wpr);
 * 
 * 
 */ 

#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // Mechanism 1.
    // Using the lock API
    std::shared_ptr<int> sp1 = std::make_shared<int>(23);
    std::weak_ptr<int> wpr1(sp1);

    auto sp2 = wpr1.lock();
    std::cout << *sp2 << '\n';

    sp1 = nullptr;  // freeing the shared pointer
    sp2 = nullptr;  // freeing the shared pointer

    sp2 = wpr1.lock();
    if (sp2 == nullptr)
    {
        std::cout << "Weak pointer no longer pointing to valid shared memory location\n";
    }


    // Mechanism 2.
    // Using the shared pointer constructor
    std::shared_ptr<int> sp3 = std::make_shared<int>(23);
    std::weak_ptr<int> wpr3{ sp3 };

    // auto sp4{ wpr3 };  auto creates new weak pointer from existing weak pointer
    std::shared_ptr<int> sp4{ wpr3 };
    if (sp4 != nullptr)
    {
        cout << "Shared ptr still valid\n";
    }
    
    sp3 = nullptr; // freeing the shared pointer
    sp4 = nullptr; // freeing the shared pointer

    try 
    {
        std::shared_ptr<int> sp5{ wpr3 };
    }
    catch (std::bad_weak_ptr& e)
    {	
        std::cout << "Weak pointer no longer pointing to valid shared memory location\n";
        std::cout << e.what() << '\n';
    }   
}