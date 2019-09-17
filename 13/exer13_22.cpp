/** 
	HasPtr 值行为
*/

#include<iostream>
#include<string>


class HasPtr {
public:
	HasPtr(const std::string &s = std::string("init")):
	     ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr& p): 
		i(p,.i),
		ps(new std::string(*p.ps))
     		{}
	HasPtr& operator=(const HasPtr& hp) {
		auto newp = new string(*np.ps);
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

int main() {
	HasPtr hp;
	HasPtr nhp;
	nhp = hp;

	hp.print();
	nhp.print();
	return 0;
}
