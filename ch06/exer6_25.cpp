/*************************************************************************
    > File Name: exer6_25.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 15时54分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
	string s;
	for(int i=1 ; i!=argc; ++i){
		s += argv[i];
	}
	cout << s << endl;
	return 0;
}
