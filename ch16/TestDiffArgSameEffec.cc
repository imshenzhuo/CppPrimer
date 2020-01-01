#include <iostream>

using namespace std;


template <typename T> 
void f1(T& t) {
    cout << "in func ";
    cout << t << endl;
    t++;
}

template <typename T> 
void f2(T&& t) {
    cout << "in func ";
    cout << t << endl;
    t++;
}

// 不管模板函数参数是T& T&&
// 进去都是T&

int main(int argc, char const *argv[])
{
    int p = 3;
    f1(p);
    cout << p << endl;
    f2(p);
    cout << p << endl;
    return 0;
}
