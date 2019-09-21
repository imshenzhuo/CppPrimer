/*************************************************************************
    > File Name: exer3_4.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月27日 星期二 22时04分39秒
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	if (s1 != s2) {
		cout << "the strings do not have the same lenght" << endl;
		if (s1.size() > s2.size())
			cout << s1 << " is longer." << endl;
		else
			cout << s2 << "is longer." << endl;
		/*
		 * if (s1 > s2) 
			cout << s1 << " is greater then " << s2 << endl;
		else
			cout << s2 << " is greater then " << s1 << endl;
		*/
	}
	else
		cout << "the strings have the same length" <<endl;

	return 0;
}
