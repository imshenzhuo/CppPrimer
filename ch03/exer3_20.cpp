/*************************************************************************
    > File Name: exer3_20.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 10时54分58秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<int> ivec;
	int i;
	while (cin >> i){
		ivec.push_back(i);
	}
	for(auto i=ivec.size()-1; i>ivec.size()/2; --i){
		cout << ivec[i] + ivec[ivec.size()-1-i] << endl;
	}

	return 0;
}
