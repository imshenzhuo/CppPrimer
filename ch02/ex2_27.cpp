/*************************************************************************
    > File Name: ex2_27.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月27日 星期二 09时44分21秒
 ************************************************************************/

#include<iostream>
using namespace std;


void ex2_28(){
	// 	int i, *const cp;
	//	int *p1, *const p2;
	const int ic = 90, &r = ic;
	const int *const p3 = &ic;
	const int *p;
}


int main(){
	// error 不能对常量引用
	// int i = -1, &r = 0;
	int i2 = 12;
	// pass
	int *const p2 = &i2;
	// error same
	const int i = -1, &r = 0;
	
	// pass
	const int *const p3 = &i2;
	
	const int *p1 = &i2;
	
    // const int &const r2;
	const int k = i2, &rk = k;
	


	const int &ques = 0;
	// int &q = 0;
	

	return 0;
}
