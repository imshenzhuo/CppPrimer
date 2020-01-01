/**
 *  可变参数模板
 *  
 *  getSize
 *      sizeof...(Args)
 * 
 */ 

#include <iostream>
#include <string>
using namespace std;

template<typename T, typename... Args>
void foo(const T &t, const Args& ... rest) {
    cout << sizeof...(Args) << "\t" ;
    cout << sizeof...(rest) << endl;
}


int main(int argc, char const *argv[])
{
    int i = 0; double d = 3.14; string s = "how now brown cow";

    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
    
    return 0;
}
