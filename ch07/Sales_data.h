#include<iostream>

using namespace std;

struct Sales_data {
	// 构造函数声明
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) {	}
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {	}
	Sales_data(istream &is);


	std::string isbn() const {
		return bookNo;
	}
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add (const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

Sales_data::Sales_data(istream &is) {
	read(is, *this);
}

double Sales_data::avg_price() const {
	return units_sold ? revenue/units_sold : 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
/**
 * 其他非类作用域的接口函数
 */
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
