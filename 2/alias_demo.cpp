/*************************************************************************
    > File Name: alias_demo.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月27日 星期二 11时00分27秒
 ************************************************************************/

#include<iostream>
using namespace std;


typedef double wages;
using minee = wages;

int main(){
	wages my = 100.0;
	minee my_later = 1000000.0;
	cout << my << endl;
	cout << my_later << endl;
	return 0;
}
