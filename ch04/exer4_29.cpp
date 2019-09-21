/*************************************************************************
    > File Name: exer4_29.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 10时03分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {

	int x[10];
	int *p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	return 0;
}
