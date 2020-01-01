/**
 * 可变参数函数模板
 *  1. 通常是递归的 
 *  2. 需要一个普通函数模板结束递归
 * 
 *  包扩展 rest...
 * 
 */ 

#include <iostream>
#include <string>
using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t) {
    return os << t << endl;
}

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest...);
}


int main(int argc, char const *argv[])
{
    print(cout, 1);
    print(cout, 1, 1.333);
    print(cout, 1, 1.004, "string", 1, 1);
    
    return 0;
}
