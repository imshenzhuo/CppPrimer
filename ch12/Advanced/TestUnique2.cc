/** 除了不能拷贝不能复制外, unique_ptr和raw指针没有什么不同
 * 
 * 
 */ 


#include <iostream>
#include <memory>
using namespace std;

void funcA (std::unique_ptr<int> param)
{
    cout << *param << '\n' ;
}

int main()
{
  // ways to pass std::unique_ptr to funcA
  funcA(std::unique_ptr<int>(new int(21)));
  funcA(std::make_unique<int>(22));     // C++14
  
  std::unique_ptr<int> uPtr(new int(23));
  funcA(move(uPtr));  
  
  std::unique_ptr<int> uPtr2(new int(24));
  // funcA(uPtr2);  // fails compilation because copy method is deleted.
} 