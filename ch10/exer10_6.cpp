/*************************************************************************
    > File Name: exer10_6.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月03日 星期二 14时20分40秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> vec(20);
	fill_n(vec.begin(), 10, -1);

	for(int i : vec) {
		cout << i << " ";
	}
	cout << endl;
}


