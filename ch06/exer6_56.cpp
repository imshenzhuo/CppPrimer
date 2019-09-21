/*************************************************************************
    > File Name: exer6_56.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月30日 星期五 09时58分03秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b){
	return  a - b;
}

int mult(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}

int main() {
	int a = 90, b=2;
	vector<int (*)(int, int)> v;
	v.push_back(add);
	v.push_back(sub);
	v.push_back(mult);
	v.push_back(divide);
	for (auto iter = v.begin(); iter != v.end(); ++iter){
		cout << (*iter)(a, b) << endl;
	}
}
