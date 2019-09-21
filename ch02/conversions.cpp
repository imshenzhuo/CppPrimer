/*************************************************************************
    > File Name: conversions.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 10时15分20秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;


void signed_unsigned(){

	// converting a negative number to unsigned 
	unsigned u = 10;
	int i = -42;
	std::cout << i + i << std::endl;  // prints -84
	std::cout << u + i << std::endl;  // if 32-bit ints, prints 4294967264


	unsigned u1 = 42, u2 = 10;
	std::cout << u1 - u2 << std::endl; // ok: result is 32
	std::cout << u2 - u1 << std::endl; // ok: but the result will wrap around

}

void testAssign(){
	bool b = 1.2;
	cout<< b <<endl;
	float f = b;
	cout<< f <<endl;
	unsigned char c1 = -1;
	cout<< c1 <<endl;
	signed char c2 = 256;
	cout<< c2 <<endl;
	printf("c2 is %d\n", c2);
}



int main(){
	printf("sizeof(1) = %ld\n", sizeof(1));
	printf("sizeof('c') = %ld\n", sizeof('c'));
	testAssign();
	signed_unsigned();

}
