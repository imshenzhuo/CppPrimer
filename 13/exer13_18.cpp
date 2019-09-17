/*************************************************************************
    > File Name: exer13_18.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月11日 星期三 15时15分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Employee{
	public:
		Employee(){
			id = ++generateId;
		}
		Employee(string name): name(name){
			id = ++generateId;
		}
		void print() {
			cout << "employee's name is " << name << " id is " << id << endl;
		}
	private:
		static int generateId;
		string name;
		int id;

};

// 类的静态变量要在类外初始化
int Employee::generateId = 0;


int main(){
	string s("Jack Ma");
	for(int i=0; i<3; ++i){
		Employee e(s);
		e.print();
	}

}
