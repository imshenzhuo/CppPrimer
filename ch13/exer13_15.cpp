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

void f(UUid s){
	cout << s.id << endl;
}

int main(){
	UUid a,b=a, c=b;
	f(a);
	f(b);
	f(c);
}

