/*************************************************************************
    > File Name: exer6_36.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 16时34分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
using arrT = int[5];

int odd[] = {
	1,3,5,7,9
};
int even[] = {
	2,3,4,8,10
};

arrT *func0(int i) {
	return (i % 2) ? &odd : &even;
}

int (*func(int i))[5] {
	return (i % 2) ? &odd : &even;
}

auto func1(int i) -> int (*)[5] {
	return ((i % 2) ? &odd : &even);
}

decltype(odd) *func2(int i) {
	return ((i % 2) ? &odd : &even);
}

int main() {
	arrT *a = func0(0);
	for(int i=0; i<5; ++i) {
		cout << (*a)[i] << endl;
	}


	int (*p)[5] = func(1);
//	cout << (*p)[4] << endl;
	for(int i=0; i<5; ++i) {
		cout << (*p)[i] << endl;
	}
	int (*p1)[5] = func1(2);
	for(int i=0; i<5; ++i) {
		cout << (*p1)[i] << endl;
	}
	int (*p2)[5] = func2(2);
	for(int i=0; i<5; ++i) {
		cout << (*p2)[i] << endl;
	}
}

