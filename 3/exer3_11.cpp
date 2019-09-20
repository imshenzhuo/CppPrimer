/*************************************************************************
    > File Name: exer3_10.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 09时12分26秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {
	const string s = "Keep out!";
	for (auto &c : s){
		c += 1;
	}
	return 0;
}
