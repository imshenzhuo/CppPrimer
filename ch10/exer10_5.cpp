/*************************************************************************
    > File Name: exer10_1.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月03日 星期二 09时42分55秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<double> ivec = {
		0.1,0.2,0.3,0.2,0.1,0.2,0.3,0.4,0.3,0.9,0.2,0.2
	};
	double sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	cout << sum << endl;

	char *s = "Hello world";
	string str("Hello world");
	cout << (str==s) << endl;
	
}
