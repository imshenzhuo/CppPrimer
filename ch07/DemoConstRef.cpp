/*************************************************************************
    > File Name: DemoConstRef.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月31日 星期六 14时54分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

class ConstRef{
	public:
		ConstRef(int ii) : i(ii), ci(ii), ri(i) {	}
	private:
		int i;
		const int ci;
		int &ri;
};
