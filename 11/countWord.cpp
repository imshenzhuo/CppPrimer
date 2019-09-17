/*************************************************************************
    > File Name: countWord.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月05日 星期四 17时20分35秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<set>

using namespace std;


int main(int argc, char *argv[]) {
	
	ifstream input(argv[1]);
	ofstream output(argv[2]);

	map<string, size_t> word_count;

	string line, word;
	while(getline(input, line)) {
		istringstream getword(line);
		while(getword >> word){
			++word_count[word];
		}
	}

	for(const auto &w : word_count)
		output << w.first << " occurs " << w.second 
			<< ((w.second > 1) ? " times " : " time ") << endl;


	return 0;
}

