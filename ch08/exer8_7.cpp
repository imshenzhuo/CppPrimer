/*************************************************************************
    > File Name: bookStore.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月30日 星期五 15时21分21秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include"Sales_data.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	Sales_data total;         // variable to hold the running sum
	if (read(input, total))  {  // read the first transaction
		Sales_data trans;     // variable to hold data for the next transaction
		while(read(input, trans)) {      //  read the remaining transactions 
			if (total.isbn() == trans.isbn())   // check the isbns 
				total.combine(trans);  // update the running total 
			else { 
				print(output, total) << endl;  // print the results 
				total = trans;               // process the next book 
			}
		}
		print(output, total) << endl;          // print the last transaction 
	} else { 
		// there was no input 
		cerr << "No data?!" << endl;         // notify the user 
	}
}
