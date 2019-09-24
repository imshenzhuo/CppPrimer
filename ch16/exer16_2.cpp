/*************************************************************************
    > File Name: exer16_2.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月20日 星期五 15时04分39秒
 ************************************************************************/

#include<iostream>
#include<string>
#include"../7/Sales_data.hpp"
using namespace std;

template <typename T>
int compare(const T &v1, const T &v2) {
	if (v1 < v2) return -1;
	if (v1 > v2) return 1;
	return 0;
}

int main() {
	cout << compare(4, 9) << endl;
	cout << compare(string("aaaa"), string( "''''''''")) << endl ;
    // Sales_data s1;
    // Sales_data s2;
    // compare(s1, s2);
	return 0;
}
