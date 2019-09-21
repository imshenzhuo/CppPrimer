/*************************************************************************
    > File Name: DemoCapacity.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月02日 星期一 17时00分10秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> v(100, -1);
	v.push_back(100);
	cout << v.capacity() << endl;

	v.reserve(300);

	cout << v.capacity() << endl;
}


