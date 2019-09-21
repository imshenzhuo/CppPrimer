/*************************************************************************
    > File Name: exer9_13.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月02日 星期一 16时06分41秒
 ************************************************************************/

#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main() {
	list<int> li = {
		1,4,2,5,6
	};

	vector<double> vecd(li.cbegin(), li.cend());

	for(auto it = vecd.cbegin(); it!=vecd.end(); ++it)
		cout << *it << endl;
}

