/*************************************************************************
    > File Name: exer3_17.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 10时43分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

int main() {
	vector<string> svec;
	string s;
	while (cin >> s) {
		svec.push_back(s);
	}
	for (auto s : svec) {
		for(auto &c : s){
			c = toupper(c);
		}
	}
	int i = 0;
	for (auto s : svec) {
		cout << s << " ";
		++i;
		if (i%8 == 0)
			cout << endl;
	}
	return 0;
}
