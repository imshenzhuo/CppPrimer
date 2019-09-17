/*************************************************************************
    > File Name: exer13_13.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月16日 星期一 22时49分08秒
 ************************************************************************/

#include<vector>
#include<iostream>
#include<memory>
using namespace std;

struct X{
	X() {
		cout << "X()" << endl;
	}

	X(const X& x) {
		cout << "X(const X& x)" << endl;
	}
	X& operator=(const X &x) {
		cout << "X& operator=(const X &x)" << endl;
		return *this;
	}
	~X(){
		cout << "~X()" << endl;
	}
};


X func1(X x1){
	return x1;
}

X& func2(X x1){
	return x1;
}


int main() {
	vector<X> xvec;
	X x1;
	X x2 = x1;
	X x3;
	x3 = x2;
	cout << "-----arg&return------------" << endl;
    func1(x1);
    cout << "-----arg------------" << endl;
	func2(x1);
    cout << "------new-----------" << endl;
    auto p = make_shared<X>();
    cout << "-------vector> v;----------" << endl;
    
    /**
	 * push_back函数参数是非引用参数，所以会拷贝初始化，调用一次拷贝构造函数
	 * 函数体内部在拷贝，所以push一个对象会发生两次拷贝构造函数
	 */
	xvec.push_back(x1);
	xvec.push_back(x2);
	xvec.push_back(x3);
	cout << "---------over--------" << endl;
	//func1()
}
