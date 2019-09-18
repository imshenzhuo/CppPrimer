/*************************************************************************
    > File Name: ex2_15.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 13时20分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int ival = 1.1;
	int i = {
		1.1
	};
//	int rval1 = 1.01;
	int &rval2 = ival;
	cout << rval2 << endl;
}
