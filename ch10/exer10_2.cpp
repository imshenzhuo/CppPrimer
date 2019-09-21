/*************************************************************************
    > File Name: exer10_2.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月03日 星期二 09时46分25秒
 ************************************************************************/

#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	list<string> slis = {
		"I", "just", "want", "to", "program"
	};
	string val;
	while(cin>>val){
		auto result = count(slis.cbegin(), slis.cend(), val);
		cout << result << endl;
	}



}
