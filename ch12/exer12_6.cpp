/*************************************************************************
    > File Name: exer12_6.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月10日 星期二 10时53分46秒
 ************************************************************************/

#include<iostream>
#include<vector>
std::vector<int> *func0(){
	auto p = new std::vector<int>();
	return p;
}

std::vector<int> *func1(std::vector<int> *p){
	int i;
	while (std::cin >> i)
		p->push_back(i);
	return p;
}

void func2(std::vector<int> *p) {
	for(const auto &i : *p)
		std::cout << i << std::endl;
	delete p;
}

int main() {
	auto p = func0();
	p = func1(p);
	func2(p);
}
