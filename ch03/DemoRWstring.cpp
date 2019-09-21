/*************************************************************************
    > File Name: DemoRWstring.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月27日 星期二 21时11分29秒
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;


int main() {
	string s;
	cin >> s;
	cout << s << endl;
	
	/* 
	string word;
	while( cin>>word ) {
		cout << word << endl;
	}
	*/
	// cin 后buffer会留下一个\n 此处获取该字符
	getchar();
	string line;
	while (getline(cin, line)){
		cout << line << endl;
	}


	return 0;
}
