/*************************************************************************
    > File Name: exer10_1.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月03日 星期二 09时42分55秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	vector<int> ivec = {
		1,2,3,2,1,2,3,4,3,9,2,2
	};
	int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	cout << sum << endl;
	
}
