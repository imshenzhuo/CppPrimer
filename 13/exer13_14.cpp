/*************************************************************************
    > File Name: exer13_14.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月11日 星期三 14时10分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

class numbered{
	public:
		numbered(){	
			static int base = 0;
			id = ++base;
		}
		long id;
};

void f(numbered s){
	cout << s.id << endl;
}

int main(){
	numbered a, b=a, c=b;
	// 拷贝初始化 调用的是拷贝构造函数
	f(a);
	f(b);
	f(c);
}

