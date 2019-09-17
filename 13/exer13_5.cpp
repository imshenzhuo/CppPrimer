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
	void print(){
		std::cout << (*ps) << " " << i << std::endl;	
	}
private:
	std::string *ps;
	int    i;
};

int main() {
	HasPtr hp;
	HasPtr nhp = hp;

	hp.print();
	nhp.print();
	return 0;
}
