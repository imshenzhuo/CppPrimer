/*************************************************************************
    > File Name: project.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月10日 星期二 16时22分13秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<cctype>
#include<algorithm>
#include<memory>

std::map<std::string, std::set<int>> &buildDict(std::ifstream &input, std::vector<std::string> &svec, std::map<std::string, std::set<int>> &dict) {
	std::string line;
	int lineNum = 0;
	while(std::getline(input, line)) {
		svec.push_back(line);
		++lineNum;
		std::istringstream record(line);
		std::string word;
		while (record >> word) {
			for(auto &ch : word)	ch = std::tolower(ch);
			dict[word].insert(lineNum);
		}
	}
	return dict;
}

void find(std::map<std::string, std::set<int>> &dict, const std::vector<std::string> &contents, const std::string &word) {
	std::cout << "element " << word << " occurs " 
		<< dict[word].size() << ((dict[word].size()==0) ? " time": "times") <<".\n";
	for(const auto &e : dict[word]){
		std::cout << "\t(line " << e << "): " << contents[e-1] << std::endl;
	}
}

int main(int argc, char *argv[]){
	std::cout << "begin\n";
	std::ifstream input(argv[1]);
	std::vector<std::string> svec;
	std::map<std::string, std::set<int>> dict;
	dict = buildDict(input, svec, dict);

	for(const auto &d : dict) {
		std::cout << d.first << std::endl;
	}
	std::string word;
	while(std::cin >> word) {
		find(dict, svec, word);
	}

/**	
	int j = 0;
	for(auto it = svec.cbegin(); it!=svec.cend(); ++it, ++j)
		std::cout << j << " " << *it << std::endl;
*/
}





