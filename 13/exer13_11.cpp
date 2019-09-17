#include<iostream>
#include<string>


class HasPtr {
public:
	HasPtr(const std::string &s = std::string("init")):
	     ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr& ori): 
		i(ori.i),
		ps(new std::string())
     		{}
	HasPtr& operator=(const HasPtr& hp) {
		delete ps;
		ps = new std::string(*hp.ps);
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
