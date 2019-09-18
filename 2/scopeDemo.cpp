/*************************************************************************
    > File Name: scopeDemo.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 17时35分43秒
 ************************************************************************/

#include<iostream>
using namespace std;


int g = 42;

int main(){
	int i = 100, sum = 0;
	for(int i=0; i!=10; ++i){
		sum += i;
	}

	int g = 100;
	int j = g;
	cout<< j << endl;
	cout << ::g << endl;


	cout << i << " " << sum << endl;
	return 0;
}
