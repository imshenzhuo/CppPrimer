/*************************************************************************
    > File Name: DemoDummy.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月31日 星期六 14时44分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

int okc = 1;

class M {
	public:
		void p() {
			cout << okc << endl;
		}
	private:
		int okc = 0;
};


int main() {
	M m;
	m.p();
}
