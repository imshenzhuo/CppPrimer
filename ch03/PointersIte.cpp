/*************************************************************************
    > File Name: PointersIte.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 14时57分38秒
 ************************************************************************/
#include<iostream>
using namespace std;

int main() {
	int arr[] = {
		0,1,2,3,4,5,6,7,8,9
	};
	cout << *(end(arr)) << endl;
	cout << *(begin(arr)) << endl;
	auto n = end(arr) - begin(arr);
	cout << n << endl;

	int *p1 = arr;
	int *p2 = p1 + 5;
	cout << p1 - p2 << endl;
	return 0;
}
