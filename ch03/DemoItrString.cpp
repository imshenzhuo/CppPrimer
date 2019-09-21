/*************************************************************************
    > File Name: DemoItrString.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 08时42分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {

	string str("Go for it!");

	for (char s: str){
		cout << s << endl;
	}

	for (auto s : str) {
		cout << s << endl;
	}
	
	for (auto &s : str) {
		s = toupper(s);
	}
	cout << str << endl;
	return 0;
}

