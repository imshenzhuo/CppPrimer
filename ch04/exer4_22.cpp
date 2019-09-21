/*************************************************************************
    > File Name: exer4_22.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月29日 星期四 09时32分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
	int grade;


	while (cin >> grade){

		string final_grade = grade>90 ? "high pass"
			: (grade > 75) ? "pass" 
			: (grade > 60) ? "low pass"
			: "fail";
		cout << final_grade << endl;
	}

	return 0;
}
