/*************************************************************************
    > File Name: ex2_16.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 13时21分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	
	r1 = 3.14;
	r2 = 4.13;

	r1 = r2;

	return 0;
}
