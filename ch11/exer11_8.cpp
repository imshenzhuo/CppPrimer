/*************************************************************************
    > File Name: exer11_8.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月09日 星期一 10时49分18秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int main(){
	std::vector<std::string> unique_word = {
		"aaa", "bbb", "cc"
	};
	std::string word;
	while(std::cin>>word){
		if (std::find(unique_word.cbegin(), unique_word.cend(), word) == unique_word.cend()){
			unique_word.push_back(word);
		}else {
			std::cout << "existed! "<< std::endl;
		}
	}

	for(auto &c : unique_word) {
		std::cout << c << std::endl;
	}

}
