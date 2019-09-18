/*************************************************************************
    > File Name: const_demo.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 19时07分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){

	int i = 1024;
	int &ri = i;
	const int &ri2 = i;
	ri = 0;
//	ri2 = -1;
	cout << ri << endl;
	cout << ri2 << endl;


	// Error
	// const int k;
	return 0;
}
