/*************************************************************************
    > File Name: exer15_7.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月18日 星期三 15时18分54秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {  }
    std::string isbn() const { return bookNo;   }
    virtual double net_price(std::size_t n) const {
        return n*price;
    }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string&, double, size_t, double);
	double net_price(size_t) const override;
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const string& book, double p, size_t qyt, double disc) :
	Quote(book, p), min_qty(qyt), discount(disc) {	}

double Bulk_quote::net_price(size_t cnt) const {
	if (cnt >= min_qty)	return cnt * (discount) * price;
	return cnt * price;
}

double print_total(ostream &os, const Quote &item, std::size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}


class Bulk2_quote : public Quote
{
public:
    Bulk2_quote(const string &s, double p, size_t qyt, double disc) :
        Quote(s, p), max_qty(qyt), discount(disc) {}
    double net_price(size_t cnt) const {
        if (cnt <= max_qty) return cnt * discount * price;
        return cnt * price;
    }
private:
    size_t max_qty = 0;
    double discount = 0.0;

};

int main() {
    /**
     * 直接将派生类传入原来写的函数
     * 完全不用更改
    */

    string s = "tiaoloushuaimai";
    // s 书， 每个 0.1 超过30本，不打折
    Bulk2_quote b(s, 0.1, 30, 0.9);
    print_total(cout, b, 40);
    print_total(cout, b, 29);


}
