/*************************************************************************
    > File Name: exer4_4.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月28日 星期三 20时41分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
	int a = 12 / 3 * 4 + 5 * 15 +24 % 4 / 2;
	int b = (12/3*4) + (5*15) + ((24 % 4) / 2);
	cout << (a == b) << endl;
	return 0;
}
