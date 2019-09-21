/*************************************************************************
    > File Name: exer15_14.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月18日 星期三 17时03分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

class B{
	public:
		 void f() {
			cout << " B f " << endl;
		}
		virtual void g() {
			cout << " B g " << endl;
		}
};

class D : public B {
	public:
		void f() {
			cout << "D f" << endl;
		}
		virtual void g() override{
			cout << "D g" << endl;
		}
};


int main() {
	B b;
	D d;
	B *bpb = &b;
	D *dpd = &d;
	bpb->f();
	dpd->f();

	B *bpd = &d;
	bpd->f();
	bpd->g();
}


