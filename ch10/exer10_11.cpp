/*************************************************************************
    > File Name: demo10_2_3.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月03日 星期二 14时47分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending) {
	return (ctr > 1) ? word + ending : word;
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}


void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), 
			[](const string &a, const string &b){
			return a.size() < b.size();
			});

	auto wc = find_if(words.begin(), words.end(),
			[sz] (const string &a){
				return a.size() >= sz;
			});

	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< "of length " << sz << " or longer" << endl;

	for_each(wc, words.end(),
			[] (const string &s) {
			cout << s << " ";
			});

}


int main() {
	vector<string> svec = {
		"the",
		"quick",
		"red",
		"fox",
		"jumps",
		"over",
		"the",
		"slow",
		"red",
		"turtle"
	};
	

	biggies(svec, 4);
		
	for(const auto &i : svec) 
		cout << i <<  " ";
	cout << endl;

}
