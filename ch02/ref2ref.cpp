/*************************************************************************
    > File Name: ref2ref.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 18时51分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int ival = 1024;
	int &refVal = ival;
	int &refVal2 = refVal;
	
	int jval = 10;
	cout<< refVal2 << endl;
	
	double dval = 3.14;
	const int &ri = dval;
	int &ri2 = dval;
	cout  << ri << endl;
	
	return 0;
}
