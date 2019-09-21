/*************************************************************************
    > File Name: exer4_21.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 09时28分59秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	vector<int> v = {
		1,3,2,4,5,7,8
	};
	for(auto iter = v.begin(); iter != v.end(); ++iter) {
		*iter = *iter%2==1 ? (*iter)*2 : (*iter);
	}
	for(auto iter = v.begin(); iter != v.end(); ++iter) {
		cout << *iter << endl;
	}


	return 0;
}

