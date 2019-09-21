/*************************************************************************
    > File Name: exer12_10.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月10日 星期二 11时28分17秒
 ************************************************************************/

#include<iostream>
#include<memory>
#include<string>

void process(std::shared_ptr<int> ptr){
	std::cout << "Inside the process function " << ptr.use_count() << std::endl; // 3
}

int main(){
	std::shared_ptr<int> p(new int(42));
	process(std::shared_ptr<int>(p));

	std::cout << p.use_count() << "\n"; // 1

	process(p);
	std::cout << p.use_count() << "\n"; // 1
}
