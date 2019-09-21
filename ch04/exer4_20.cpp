/*************************************************************************
    > File Name: exer4_20.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 09时08分46秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main() {
	vector<string> svec;
	svec.push_back("GF1");
	svec.push_back("GF2");
	svec.push_back("GF3");
	svec.push_back("GF4");

	for(auto iter = svec.begin(); iter != svec.end(); ++iter) {
		cout << *iter << endl;
	}

	for(auto iter = svec.begin(); iter != svec.end(); ){
		cout << *iter++ << endl;
	}
	return 0;
}
