/*************************************************************************
    > File Name: exer9_14.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月02日 星期一 16时17分16秒
 ************************************************************************/

#include<iostream>
#include<list>
#include<vector>
#include<string>

using namespace std;

int main() {
	list<char *> list_char = {
		"hello", "computer", "world"
	};

	vector<string> svec;
	svec.assign(list_char.begin(), list_char.end());

	for(auto it=svec.begin(); it!=svec.end(); ++it)
		cout << *it << endl;
}


