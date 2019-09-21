/*************************************************************************
    > File Name: exer4_23.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 09时40分22秒
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

int main() {
	string s = "word";
	string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
	cout << p1 << endl;
	return 0;
}
