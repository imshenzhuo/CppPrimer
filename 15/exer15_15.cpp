/*************************************************************************
    > File Name: exer15_15.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月18日 星期三 22时01分22秒
 ************************************************************************/

#include<iostream>
#include <string>
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
    virtual void debug(ostream &os) const {
        os << " bookNo " << bookNo << " price " << price << endl;
    }
    virtual ~Quote() = default;
protected:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 1.0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double price, 
        size_t qty, double disc) : 
    Disc_quote(book, price, qty, disc) {}
    // 超出的部分打折
    double net_price(size_t cnt) const override {
        if (cnt >= quantity)  return quantity * price + (cnt - quantity) * discount * price; 
        return cnt * price;
    }
    
};

int main(int argc, char const *argv[])
{
    string s = "sanguo";
    Bulk_quote bq(s, 32.1, 30, 0.9);
    double price = bq.net_price(34);
    cout << price << endl;
    return 0;
}