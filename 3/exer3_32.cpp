/*************************************************************************
    > File Name: exer3_31.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 14时46分55秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int a[10];
	for(int &i : a){
		i = 11;
	}
	for (int i=0; i<10; ++i) {
		cout << a[i] << endl;
	}
	return 0;
}
