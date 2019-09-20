/*************************************************************************
    > File Name: exer3_14.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 10时14分03秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> ivec;
	int i;
	while(cin>>i) {
		ivec.push_back(i);
	}
	cout << ivec.size() << endl;
	return 0;
}
