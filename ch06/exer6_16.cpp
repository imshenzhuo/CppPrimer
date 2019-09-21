/*************************************************************************
    > File Name: exer6_16.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 15时22分04秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

bool containUpper(const string &s) {
	for(auto c : s){
		if (isupper(c)) 
			return true;
	}
	return false;
}

int main() {
	
	string s;
	do {
		getline(cin, s);
		cout << s << endl;
	}while(containUpper(s));
	
	return 0;
}
