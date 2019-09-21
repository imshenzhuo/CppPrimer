/*************************************************************************
    > File Name: IterDemo.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月02日 星期一 15时05分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<vector>

int main() {
	vector<int> vi(7);
	cout << vi.size() << endl;

	auto it = vi.begin();
	++it;
	++it;

	auto end = vi.end();
	end = it - 1;
}
