/*************************************************************************
    > File Name: demo10_2_3.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月03日 星期二 14时47分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}


int main() {
	vector<string> svec = {
		"the",
		"quick",
		"red",
		"fox",
		"jumps",
		"over",
		"the",
		"slow",
		"red",
		"turtle"
	};

	for(auto i : svec) {
		cout << i << " ";
	}
	cout << endl;
	elimDups(svec);
	for(auto i : svec) {
		cout << i << " ";
	}
	cout << endl;
}
