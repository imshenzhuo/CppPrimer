/*************************************************************************
    > File Name: exer11_33.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月09日 星期一 09时34分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include<sstream>


std::unordered_map<std::string, std::string> getMap(std::ifstream &map_file){
	std::unordered_map<std::string, std::string> buildMap;
	std::string key;
	std::string value;
	while(map_file>>key && getline(map_file, value)){
		if (value.size()>1)		buildMap[key] = value.substr(1); // skip space
		else	throw std::runtime_error("no rule for " + key);
	}
	return buildMap;
}

const std::string &transform(const std::string &word, const std::unordered_map<std::string, std::string> &buildMap) {
	auto map_it = buildMap.find(word);
	if(map_it!=buildMap.cend())	return map_it->second;
	else	return word;
	// error return buildMap[word];

}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
	auto buildMap = getMap(map_file);
	std::string line;
	while(getline(input, line)){
		std::string word;
		std::istringstream record(line);
		bool firstword = true;
		while(record>>word){
			if (firstword)	firstword = false;
			else std::cout << " ";
			std::cout << transform(word, buildMap);
		}
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[]){
	std::ifstream map_file(argv[1]);
	std::ifstream input(argv[2]);
	word_transform(map_file, input);
}
