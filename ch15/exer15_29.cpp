/*************************************************************************
    > File Name: exer15_29.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月19日 星期四 12时43分08秒
 ************************************************************************/

#include<iostream>
#include <string>
#include <vector>
#include <memory>

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
    std::vector<shared_ptr<Quote>> basket;
    // C++ primer
    Bulk_quote bq1("c++ primer", 128.0, 5, 0.9);
    // CSAPP 10本以上打8折
    Bulk_quote bq2("CSAPP", 99.0, 10, 0.8);

    std::cout << "bulk_quote's total: " << bq1.net_price(15) + bq2.net_price(15) << std::endl;


    basket.push_back(make_shared<Bulk_quote> (bq1));
    basket.push_back(make_shared<Bulk_quote> (bq2));


    double price = 0.0;
    for(auto &q : basket) {
        double d =  q->net_price(15);
        cout << d << endl;
        price += d;
    }
    cout << price << endl;

    return 0;
}
