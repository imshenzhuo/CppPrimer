/*************************************************************************
    > File Name: exer4_28.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 09时58分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
	cout << "guess sizeof char  should be 1" << "actually is " << sizeof(char) << endl;
	cout << "guess sizeof int  should be 4" << "actually is " << sizeof(int) << endl;
	cout << "guess sizeof long should be 4" << "actually is " << sizeof(long) << endl;
	cout << "guess sizeof long long  should be 8" << "actually is " << sizeof(long long) << endl;
	cout << "guess sizeof float should be 4" << "actually is " << sizeof(float) << endl;
	cout << "guess sizeof double  should be 8" << "actually is " << sizeof(double) << endl;
	cout << "guess sizeof long double should be 16" << "actually is " << sizeof(long double) << endl;

	return 0;
}
