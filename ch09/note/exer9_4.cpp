/*************************************************************************
  > File Name: exer9_4.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月02日 星期一 15时12分18秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool func(vector<int>::iterator begin, vector<int>::iterator end, int i) {
	while(begin!=end) {
		if ( (*begin)==i)	return true;
		begin++;
	}
	return false;
}

int main() {
	vector<int> ivec = {
		1,4,2,3,4,7,8,4,9
	};
	cout << func(ivec.begin(), ivec.end(), 4) << endl;
}
