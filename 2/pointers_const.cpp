/*************************************************************************
    > File Name: pointers_const.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 22时11分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	const double pi = 3.14;
	//	double *ptr = &pi;
	//	error
	//	pi 是指向const double类型的指针，并非被const修饰不能改变
	const double *cptr = &pi;
	//	*cptr = 42;
	//	指针指向的类型const不能变
	//	error
	
	//  const 指针指向一个非const类型 可以强转
	double dval = 3.14;
	cptr = &dval;
	
	int ival = 4;
	// cptr = &ival;
	
	int errNum = 0;
	int *const constP = &errNum;
	//  只能指向 errNum
	//  Error
	//  constP = &ival;

	return 0;
}
