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
	string s;
	while (getline(cin, s)) {
		for(auto c : s){
			if (!ispunct(c))
				cout << c;
		}
		cout << endl;
	}
	return 0;
}
