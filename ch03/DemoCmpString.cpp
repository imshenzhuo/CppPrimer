/*************************************************************************
    > File Name: DemoCmpString.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月27日 星期二 21时48分29秒
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

int main() {
	string str = "Hello";
	string phrase = "Hello World";
	string slang = "z";

	cout << (str < phrase) << endl;
	cout << (phrase < slang) << endl;

	return 0;

}
