/*************************************************************************
    > File Name: exer11_12.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月08日 星期日 16时02分30秒
 ************************************************************************/

#include<iostream>
#include<utility>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

int main(){
	std::vector<std::pair<std::string, int>> pvec;
	std::string line;
	while(getline(std::cin, line)) {
		std::istringstream record(line);
		std::string word;
		while(record>>word){
			pvec.push_back({word, word.size()});
		}
	}
	for(const auto &e : pvec){
		std::cout << e.first << "  "
			 << e.second << std::endl;
	}
}
