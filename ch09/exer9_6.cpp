/*************************************************************************
    > File Name: exer9_6.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月02日 星期一 15时28分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include<list>

int main() {
	list<int> lst1 = {
		1,2,3,4,56
	};
	list<int>::iterator iter1 = lst1.begin(),
		iter2 = lst1.end();
/*
	while(iter1 < iter2) {
		cout << *iter1++ << endl;
	}
*/
	while(iter1 != iter2) {
		cout << *iter1++ << endl;
	}
}
