/*************************************************************************
    > File Name: exer3_21.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 13时45分06秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> v{
		1,2,3,4,5,6,7,8,9
	};
	for(auto it=v.begin(); it != v.end(); ++it){
		*it *= *it;
	}

	for(auto it = v.begin(); it != v.end(); ++it){
		cout << *it << endl;
	}
	return 0;
}


