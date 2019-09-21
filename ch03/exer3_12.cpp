/*************************************************************************
    > File Name: exer3_12.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 09时56分27秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	vector<vector<int>> ivec;
	// 类型不匹配
	// vector<string> svec = ivec;
	// 10 个 null
	vector<string> svecc(10, "null");
	vector<string> sveccc{0, "null"};



	return 0;
}

