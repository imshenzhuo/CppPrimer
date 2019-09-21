/*************************************************************************
    > File Name: exer4_19.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 21时58分42秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {

	int *p;
	cout << (p != 0) << endl;
//	cout << (p != 1) << endl;
	
	int a[] = {
		1,2,3
	};
	int *p2a = a;
	cout << (*p2a++) << endl;

	return 0;
}
