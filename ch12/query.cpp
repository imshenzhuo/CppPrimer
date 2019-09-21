/*************************************************************************
    > File Name: TextQuery.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月10日 星期二 19时00分14秒
 ************************************************************************/

#include<iostream>
#include"TextQuery.hpp"
#include"QueryResult.hpp"

using namespace std;

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
	string text;
	while(getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word){
			auto &lines = wm[word];
			if(!lines)	lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}


QueryResult 
TextQuery::query(const std::string &sought) const{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc==wm.end())
		return QueryResult(sought. nodata, file);
	return QueryResult(sought, loc->second, file);
}


