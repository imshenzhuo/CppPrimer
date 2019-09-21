/*************************************************************************
    > File Name: exer12_1.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月10日 星期二 10时09分12秒
 ************************************************************************/

#include<iostream>
#include<memory>
#include<string>
#include<vector>

class StrBlob{
	public:
		typedef std::vector<std::string>::size_type size_type;
		StrBlob() : data(std::make_shared< std::vector<std::string> >()) {}
		StrBlob(std::initializer_list<std::string> li) : data(std::make_shared<std::vector<std::string>>(li)) {	}
		StrBlob(std::shared_ptr<std::vector<std::string>> p_svec) : data(p_svec) {	}
		size_type size() const { return data->size(); }
		bool empty() const {return data->empty();	}
		void poush_back(const std::string &t) {
			data->push_back(t);
		}
		void pop_back(){
			check(0, "pop back on empty strBlob");
			data->pop_back();
		}

		std::string& front() const{
			check(0, "front on empty strBlob");
			return data->front();
		}
		std::string& back() const{
			check(0, "back on empty StrBlob");
			return data->back();
		}
	private:
		std::shared_ptr<std::vector<std::string>> data;
		void check(size_type i, const std::string &msg) const{
			if (i >= data->size())	throw std::out_of_range(msg);
		}
};

int main(){
	std::vector<std::string> svec = {
		"map",
		"set",
		"multiset",
		"multimap"
	};
	auto p = std::make_shared<std::vector<std::string>>(svec);
	StrBlob s(p);
	while (!s.empty()){
		std::cout << s.back() << std::endl;
		s.pop_back();
	}
	return 0;
}

