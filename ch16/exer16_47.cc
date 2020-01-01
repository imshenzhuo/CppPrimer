#include <utility>
#include <iostream>
using namespace std;

void f(int v1, int &v2) {
    cout << v1 << " " << ++v2 << endl;
}

void g(int &&i, int& j) {
    cout << i << " " << j << endl;
}

template <typename F, typename T1, typename T2>
void filp1(F f, T1 t1, T2 t2) {
	f(t2, t1);
}

// 通过将一个函数参数定义成指向模板类型参数的右值引用
// 可以保持其对用实参的所有信息

// 1. 引用参数保持const属性(const在引用中都是底层的)
// 2. 通过引用折叠实现翻转实参是左右值属性

// T1 int & 
// T1 && => int& && => int&
template <typename F, typename T1, typename T2>
void filp2(F f, T1 &&t1, T2 &&t2) {
	f(t2, t1);
}


template <typename F, typename T1, typename T2>
void filp3(F f, T1 &&t1, T2 &&t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}


int main(int argc, char const *argv[])
{
    int j = 100;
    filp1(f, j, 42);
    cout << j << endl;
    filp2(f, j, 42);
    cout << j << endl;

    // filp2(g, j, 42); // error

    filp3(g, j, 22);
    return 0;
}
