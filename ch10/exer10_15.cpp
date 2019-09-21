/*************************************************************************
    > File Name: exer10_14.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月04日 星期三 09时26分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
	auto f = [argc](int a, int b){
		return a + b + argc;
	};
	cout << f(1,2) << endl;
}
