/*************************************************************************
    > File Name: exer7_4.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月30日 星期五 15时54分44秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Person{
	private:
		std::string name = "lhc";
		std::string addr = "hsp";
	public:
		Person() = default;
		Person(const string &n, const string &a) : name(n), addr(a) {	}
		Person(istream &is) {
			is >> (*this).name >> (*this).addr;
		}
		std::string getName() const {
			return name;
		}
		std::string getAddr() const {
			return addr;
		}

	
};

/*
istream &read(istream &is, Person &p) {
	is >> p.getName() >> p.getAddr();
	return is;
}
*/
ostream &print(ostream &os, const Person &p) {
	os << p.getName() << " " << p.getAddr() << endl;
	return os;
}


int main() {
	/*
	Person p;
	p.name = "sz";
	p.addr = "cd";
	Person p2;
	read(cin,p2);
	print(cout,p2);

	cout << p.getName() << endl;
	cout << p.getAddr() << endl;
*/
	Person p3;
	print(cout, p3);

	Person p4("Pony", "shenzhen");
	print(cout, p4);

	Person p5(cin);
	print(cout, p5);



}
