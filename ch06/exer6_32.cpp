/*************************************************************************
    > File Name: exer6_32.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 16时18分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int &get(int *array, int index) {
	return array[index];
}

int main() {
	int array[] = {
		1,9,9,7,3,6
	};
	get(array, 4) = 400;
	for(auto a : array) {
		cout << a << endl;
	}

	int ia[10];
	for(int i=0; i!=10; ++i) {
		get(ia, i) = i;
	}
	for(auto a : ia) {
		cout << a << endl;
	}

}
