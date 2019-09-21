/*************************************************************************
    > File Name: exer3_16.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 10时36分06秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	
	vector<int> v1;
	cout << v1.size() << endl;
	for(auto v : v1) {
		cout << v << endl;
	}

	vector<int> v2(10);
	cout << v2.size() << endl;
	for(auto v : v2) {
		cout << v << endl;
	}
	
	vector<int> v3(10, 42);
	cout << v3.size() << endl;
	for(auto v : v3) {
		cout << v << endl;
	}
	vector<int> v4{
		10
	};
	cout << v4.size() << endl;
	for(auto v : v4) {
		cout << v << endl;
	}
	vector<int> v5{
		10, 42
	};
	cout << v5.size() << endl;
	for(auto v : v5) {
		cout << v << endl;
	}

	vector<string> v6{
		10
	};
	cout << v6.size() << endl;
	for(auto v : v6) {
		cout << v << endl;
	}
	vector<string> v7{
		10, "hi"
	};
	cout << v7.size() << endl;
	for(auto v : v7) {
		cout << v << endl;
	}

	return 0;
}
