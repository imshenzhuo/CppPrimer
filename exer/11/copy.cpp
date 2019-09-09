/*************************************************************************
    > File Name: copy.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月08日 星期日 15时10分42秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>

int main(int argc, char *argv[]) {
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);

	std::string line;
	while(getline(input, line)){
		output << line << std::endl;
	}
	return 0;
}
