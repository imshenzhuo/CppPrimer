/*************************************************************************
    > File Name: exer11_7.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月08日 星期日 11时17分28秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>

int main(){
	std::map<std::string, std::vector<std::string>> house;
	house["Stark"] = {
		"Robbert",
		"Jone",
		"Samsa"
	};
	for(const auto &i : house){
		std::cout << i.first << std::endl;
		for(const auto &j : i.second)
			std::cout << j << std::endl;
	}
	return 0;
}

