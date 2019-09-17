/*************************************************************************
    > File Name: exer13_18.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月11日 星期三 15时15分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Employee{
	public:
		Employee(){
			id = ++generateId;
		}
		Employee(string name): name(name){
			id = ++generateId;
		}
		Employee(const Employee&) = delete;
		Employee& operator=(Employee &) = delete;
		void print() {
			cout << "employee's name is " << name << " id is " << id << endl;
		}
	private:
		static int generateId;
		string name;
		int id;

};

int Employee::generateId = 0;


int main(){
	vector<Employee> evec;
	string s("Jack Ma");
	Employee e1(s);
//	evec.push_back(e1);
	
	Employee e2("Pony");
//	evec.push_back(e2);

//	Employee e3 = e1;
	// copy init 
	// copy constructor
//	evec.push_back(e3);

	for(auto &e : evec){
		e.print();
	}
}
