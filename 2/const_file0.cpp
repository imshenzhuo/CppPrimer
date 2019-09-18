/*************************************************************************
    > File Name: const_file0.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 14时14分28秒
 ************************************************************************/

#include<iostream>
using namespace std;


double getNum(){
	return 3.141;
}

extern double pi = getNum();
