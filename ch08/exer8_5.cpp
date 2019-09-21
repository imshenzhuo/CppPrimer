/*************************************************************************
    > File Name: exer8_4.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月01日 星期日 13时07分51秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char *argv[]) {
	if (argc < 2) return -1;
	ifstream input(argv[1]);

	vector<string> vecs;
	string s;
	while(input >> s) {
		vecs.push_back(s);
	}
	input.close();
	cout << vecs.size() << endl;
	for(auto it = vecs.begin(); it!=vecs.end(); ) {
		cout << *it++ << endl;
	}
}
