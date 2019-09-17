//! @shenzhuo
//!
//! Exercise 11.9:
//! Write your own version of the word-counting program.
//!

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <vector>

//! Exercise 11.9
void word_count_pro(std::map<std::string, std::vector<int>>& m, std::ifstream &input, std::ofstream &output){
//void word_count_pro(std::map<std::string, int>& m, ifstream &input, ofstream &output)
    std::string line;
	std::string word;
	int line_num = 0;
    while (std::getline(input, line)) {
		++line_num;
		std::istringstream record(line);
		while (record >> word) {
			for (auto& ch : word) ch = tolower(ch);
	        //! According to the erase-remove idiom.
		    //! For more information about the erase-remove idiom, please refer to
			 //! http://en.wikipedia.org/wiki/Erase-remove_idiom
			word.erase(std::remove_if(word.begin(), word.end(), ispunct),
                   word.end());
//			std::cout << word << " " << line_num << std::endl;
	        m[word].push_back(line_num);
		}
    }
	std::cout << m.size() << std::endl;
    for (const auto& e : m) {
		output << e.first << " : ";
		for(const auto& ee : e.second)	output << ee << " ";
		output << std::endl;

	}
}

int main(int argc, char* argv[])
{
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);

	std::map<std::string, std::vector<int>> m;

    word_count_pro(m, input, output);

    return 0;
}
