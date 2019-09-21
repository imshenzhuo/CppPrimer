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

	for (string::size_type i=0; i<s.size(); ++i) {
		s[i] = 'X';
	}
	cout << s << endl;
	
	string::size_type i = 0;
	while (i < s.size() ){
		s[i] = 'Y';
		++i;
	}
	cout << s << endl;

	for (char &c : s) {
		c = 'F';
	}
	cout << s << endl;
}
