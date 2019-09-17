/** 
	HasPtr 值行为
*/

#include<iostream>
#include<string>


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
	~HasPtr(){
		delete ps;
	}
	void print(){
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
	HasPtr hp1("ha ppy");
	HasPtr hp2("ma ni");
	hp1.print();
	hp2.print();
	swap(hp1, hp2);

	return 0;
}
