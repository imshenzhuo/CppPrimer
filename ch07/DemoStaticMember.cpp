/*************************************************************************
    > File Name: DemoStaticMember.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月31日 星期六 12时28分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Account {
	public:
		void calculate() {
			amount += amount * interestRate;
		}
		
		static double rate() {
			return interestRate;
		}

		static void rate(double);


	private:
		string owner;
		double amount;
		static double interestRate;
		static double initRate(double init) {
			return init;
		}
};

// 外部定义静态函数，不用static
void Account::rate(double newRate) {
	interestRate = newRate;
}


int main() {
	// access 作用域
	double r = Account::rate();
	cout << r << endl;
	Account ac1;
	Account *ac2 = &ac1;
	r = ac1.rate();
	cout << r << endl;
	r = ac2->rate();
	cout << r << endl;

}
