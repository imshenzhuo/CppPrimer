/*************************************************************************
    > File Name: autoDemo.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月27日 星期二 11时31分09秒
 ************************************************************************/

#include<iostream>

using namespace std;

int main(){
	
	int i = 0, &r = i;
	const int ci = i, &cr = ci;
	auto b = ci;  // b is an int (top-level const in ci is dropped)
	auto c = cr;  // c is an int (cr is an alias for ci whose const is top-level)
	auto d = &i;  // d is an int*(& of an int object is int*)
	auto e = &ci; // e is const int*(& of a const object is low-level const)
	
	const auto f = ci; // deduced type of ci is int; f has type const int
	
	auto k = ci, &l = i;    // k is int; l is int&
	auto &m = ci, *p = &ci; // m is a const int&;p is a pointer to const int
	// error: type deduced from i is int; type deduced from &ci is const int
	// same line 要一致！
	auto &n = i, *p2 = &ci;

	return 0;
}
