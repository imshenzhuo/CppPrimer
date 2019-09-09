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
	std::multimap<std::string, std::vector<std::string>> houses;
	/* 
	houses["Stark"] = {
		"Robbert",
		"Jone",
		"Samsa"
	};
	*/

	houses.insert({ "Stark", { "Robert", "Snow"	}});
	houses.insert({ "Stark", {"Tony" }});
	
	for(const auto &i : houses){
		std::cout << i.first << std::endl;
		for(const auto &j : i.second)
			std::cout << j << std::endl;
	}
	return 0;
}

