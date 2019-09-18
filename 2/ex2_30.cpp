/*************************************************************************
    > File Name: ex2_30.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月27日 星期二 10时31分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	const int v2 = 0, v1 = v2;
//	int *p1 = &v1, &r1 = v1;
	const int *p2 = &v2, *const p3 = &v2, &r2 = v2;
	return 0;
}
