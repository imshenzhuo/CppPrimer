/** 
	HasPtr 值行为
*/

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string("init")):
	     ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr& p): 
		i(p.i),
		ps(new std::string(*p.ps))
     		{}
	HasPtr& operator=(const HasPtr& hp) {
		auto newp = new std::string(*hp.ps);
		delete ps;
		ps = newp;
		i = hp.i;
		return *this;
	}
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs){
		return *lhs.ps < *rhs.ps;
	}
	~HasPtr(){
		delete ps;
	}
	void print() const{
		std::cout << (*ps) << " " << i << std::endl;	
	}
private:
	std::string *ps;
	int    i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs){
	std::cout << "void swap(HasPtr &lhs, &rhs)" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}


int main() {
	std::vector<HasPtr> v;
	v.push_back(HasPtr("zkkk"));
	v.push_back(HasPtr("akk"));
	v.push_back(HasPtr("dkk"));
	v.push_back(HasPtr("kzkk"));
	std::cout<< v.size() << std::endl;
	for(auto it = v.cbegin(); it!=v.cend(); ++it)
		(*it).print();
	sort(v.begin(), v.end());
	
	for(auto it = v.cbegin(); it!=v.cend(); ++it)
		(*it).print();
	
	return 0;
}
