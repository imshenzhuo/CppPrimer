/*************************************************************************
    > File Name: exer6_21.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月30日 星期五 11时10分14秒
 ************************************************************************/

#include<iostream>
using namespace std;

int getGreater(int a, inb *b) {
	return a > *b ? a : *b;
}

void swap_point(int *p1, int *p2) {
	int *p = p1;
	p1 = p2;
	p2 = p;
}
