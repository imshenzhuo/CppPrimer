/**
 * the size of weak_ptr is the same as that of shared_ptr. 
 * 
 * Note that when shared_ptr becomes dangling ( i.e the raw pointer is freed), 
 * but if weak pointer count is more than one, the control block will NOT get freed. 
 */ 


#include <iostream>
#include <memory>
using namespace std;

int main()
{
    std::shared_ptr<int> sp1 = std::make_shared<int>(23);
    std::weak_ptr<int> wpr1(sp1);
    std::cout << "*sp1 = " << *sp1 << '\n';
    std::cout << "Size of shared pointer is " << sizeof(sp1) << '\n';
    std::cout << "Size of weak pointer is" << sizeof(wpr1) << '\n';
}
