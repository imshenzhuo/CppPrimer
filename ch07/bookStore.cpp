/*************************************************************************
    > File Name: bookStore.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月30日 星期五 15时21分21秒
 ************************************************************************/

#include<iostream>
#include"Sales_data.hpp"
using namespace std;

int main() {
	Sales_data total;         // variable to hold the running sum
	if (read(cin, total))  {  // read the first transaction
		Sales_data trans;     // variable to hold data for the next transaction
		while(read(cin, trans)) {      //  read the remaining transactions 
			if (total.isbn() == trans.isbn())   // check the isbns 
				total.combine(trans);  // update the running total 
			else { 
				print(cout, total) << endl;  // print the results 
				total = trans;               // process the next book 
			}
		}
		print(cout, total) << endl;          // print the last transaction 
	} else { 
		// there was no input 
		cerr << "No data?!" << endl;         // notify the user 
	}
}
