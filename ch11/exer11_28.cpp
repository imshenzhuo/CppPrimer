/*************************************************************************
    > File Name: exer11_28.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月08日 星期日 20时00分09秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
#include<vector>

int main(){
	std::map<std::string, std::vector<int>> str2ivec;
	str2ivec["Author"] = {2,5,34};
	str2ivec["Aur"] = {2,5,34};
	str2ivec["thor"] = {2,5,34};
	str2ivec["Ahor"] = {2,5,34};
	
	auto it = str2ivec.find("Aur");
	for(auto &i : (*it).second)
		std::cout << i << std::endl;

}
