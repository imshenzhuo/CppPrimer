/*************************************************************************
    > File Name: exer13_14.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月11日 星期三 14时10分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

class UUid{
	public:
		UUid(){	
			static int base = 0;
			id = ++base;
		}
		UUid(const UUid &ori) {
			id = ori.id + 1;
		}
		long id;
};

void f(UUid &s){
	cout << s.id << endl;
}

int main(){
	UUid a,b=a, c=b;
	// 拷贝初始化 调用的是拷贝构造函数
	f(a);
	f(b);
	f(c);
}

