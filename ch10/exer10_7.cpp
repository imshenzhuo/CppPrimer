/*************************************************************************
    > File Name: exer10_7.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月03日 星期二 14时28分11秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<list>
#include<vector>

using namespace std;

int main() {

	/* a * 
	vector<int> vec;
	list<int> lis;
	int i;
	while(cin>>i) {
		lis.push_back(i);
	}

	for(auto i : lis)
		cout << i << " ";
	cout << endl;
	vec.reserve(lis.size());
	copy(lis.cbegin(), lis.cend(), vec.begin());

	
	for(auto i : vec)
		cout << i << " ";
	cout << endl;

	* b */

	vector<int> vecb;
//	vecb.reserve(10);
	vecb.assign(10, 0);
	fill_n(vecb.begin(), 10, 111);
	cout << vecb.size() << endl;
	for(auto i : vecb)
		cout << i << " ";
	cout << endl;
}
