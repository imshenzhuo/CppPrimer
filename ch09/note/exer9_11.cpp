/*************************************************************************
    > File Name: exer9_11.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月02日 星期一 15时49分06秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

void print(const vector<int> &vec) {
	for(auto it = vec.begin(); it!=vec.end(); ++it) {
		cout << *it << endl;
	}
}


int main() {
	vector<int> vec0 ={
		3,2,1,7,8,6,5,4
	};
	print(vec0);

	vector<int> vec1(vec0);
	vec1[1] = 111111;
	print(vec1);

	vector<int> vec2 = vec0;
	vec2[2] = 222222;
	print(vec2);

	vector<int> vec3(vec2.begin(), vec2.end());
	vec3[3] = 333333;
	print(vec3);

	vector<int> vec4(10);
	print(vec4);

	vector<int> vec5(10, -1);
	print(vec5);


}
