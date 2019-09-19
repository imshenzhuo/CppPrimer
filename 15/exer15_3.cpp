/*************************************************************************
    > File Name: exer15_3.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月18日 星期三 15时07分47秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Quote{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price):
		bookNo(book), price(sales_price) {	}
	std::string isbn() const { return bookNo;	}
	virtual double net_price(std::size_t n) const {
		return n*price;
	}
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

double print_total(ostream &os, const Quote &item, std::size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

/**
int main(){
	string book = "tales";
	Quote item(book, 22.2);
	print_total(cout, item, 20);
}
*/
