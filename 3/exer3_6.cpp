/*************************************************************************
    > File Name: exer3_6.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 09时05分37秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s("you deserve it!");
	cout << s << endl;
	for (auto &c : s) {
		c = 'X';
	}
	cout << s << endl;
}
