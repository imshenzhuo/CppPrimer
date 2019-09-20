/*************************************************************************
    > File Name: exer3_1.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月27日 星期二 20时49分31秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int sum = 0, val = 1;
	while(val<=10){
		sum += val;
		++val;
	}
	cout << "sum of 1 to 10 inclusive is " << sum << endl;
}
