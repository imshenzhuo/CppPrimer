/*************************************************************************
    > File Name: DemoConstCast.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 10时39分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {

	int i = 99;

	const int *p = &i;

	// error
	// *p = -99;
	
	int *newp = const_cast<int *>(p);

	*newp = -99;

	cout << i << endl;
	return 0;
}
