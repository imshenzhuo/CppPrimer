/*************************************************************************
    > File Name: ex2_3.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2019年08月26日 星期一 10时06分37秒
 ************************************************************************/

#include<iostream>
using namespace std;


int main(){
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;  // ok
	std::cout << u - u2 << std::endl;  // 翻车  先计算为-32 写入二进制  在将二进制解释为无符号int
	
	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;  // ok
	std::cout << i - i2 << std::endl;  // ok
	 
	 
	std::cout << i - u << std::endl;  
	std::cout << u - i << std::endl;
	
	std::cout << i - u2 << std::endl; // 大家都是int 有符号和无符号计算  先将有符号转为无符号 最后解释为无符号数据
	std::cout << u2 - i << std::endl; // 总之 有符号 -> 无符号

	unsigned short us1 = 10, us2 = 42;
	unsigned ui = 42;
	cout << i-us2 << endl;
	cout << i-ui << endl;
	
	return 0;
}
