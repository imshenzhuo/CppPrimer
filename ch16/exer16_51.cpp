/*************************************************************************
    > File Name: exer16_51.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月26日 星期四 09时40分28秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

template <typename T, typename... Args>
void foo(const T&t, const Args& ... rest) {
	cout << sizeof...(Args) << endl;
	cout << sizeof...(rest) << endl;
}

int main() {
	int i = 0;
	double d = 3.14;
	string s = "how now brown cow";
	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
}
