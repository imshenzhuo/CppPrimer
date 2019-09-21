/*************************************************************************
    > File Name: exer6_7.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月30日 星期五 10时32分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

int f() {

	static int i = 0;
	if (i == 0) return i++;
	return i;
}

int main() {
	for(int i = 0; i != 10; ++i) {
		cout << f() << endl;
	}
}
