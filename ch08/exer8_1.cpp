/*************************************************************************
    > File Name: exer8_1.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月01日 星期日 12时25分18秒
 ************************************************************************/

#include<iostream>
using namespace std;

istream &read(istream &is) {
	char ch;
	while(is >> ch){
		cout << ch;
	}
	is.clear();
	return is;
}

int main() {
	cout << cin.rdstate();
	read(cin);
	cout << cin.rdstate();

}
