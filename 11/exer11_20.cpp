//! @Alan
//!
//! Exercise 11.3:
//! Write your own version of the word-counting program.
//!
//! Exercise 11.4:
//! Extend your program to ignore case and punctuation.
//! For example, “example.” “example,” and “Example” should
//! all increment the same counter.
//!

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

//! Exercise 11.4
void word_count_pro(std::map<std::string, int>& m, std::ifstream &input, std::ofstream &output){
//void word_count_pro(std::map<std::string, int>& m, ifstream &input, ofstream &output)
    std::string word;
    while (input >> word) {
        for (auto& ch : word) ch = tolower(ch);
        //! According to the erase-remove idiom.
        //! For more information about the erase-remove idiom, please refer to
        //! http://en.wikipedia.org/wiki/Erase-remove_idiom
        word.erase(std::remove_if(word.begin(), word.end(), ispunct),
                   word.end());
		auto ret = m.insert({word,1});
		if (!ret.second)	++ret.first->second;
//        ++m[word];
    }
    for (const auto& e : m) output << e.first << " : " << e.second << "\n";
}

//! Exercise 11.3
void ex11_3()
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while (std::cin >> word) ++word_count[word];

    for (const auto& elem : word_count)
        std::cout << elem.first << " : " << elem.second << "\n";
}

int main(int argc, char* argv[])
{
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);

	std::map<std::string, int> m;

    word_count_pro(m, input, output);

    return 0;
}
