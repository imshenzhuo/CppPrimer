/*************************************************************************
    > File Name: exer13_27.cpp
	  定义自己的引用计数类
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月17日 星期二 10时55分47秒
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class HasPtr{
    public:
        HasPtr(const string &s = string()) :
        ps(new string(s)), i(0), use(new size_t(1)) {  }
        HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) {
            ++*use;
        }
        HasPtr& operator=(const HasPtr &rhs) {
            ++*rhs.use;
            if (--*use == 0)
            {
                delete ps;
                delete use;
            }
            i = rhs.i;
            use = rhs.use;
            ++*use;
            return *this;
        }
        void print(){
            cout << *ps << "  " << i << "  " << *use << endl;
        }
        ~HasPtr() {
            if (--*use == 0) {
                delete ps;
                delete use;
            }
        }
    private:
        string *ps;
        int i;
        // 记录有多少个对象共享*ps成员
        size_t *use;
};

int main(int argc, char const *argv[])
{
    string s =  "happy";
    string s2 =  "get up";

    HasPtr hp(s);
    HasPtr hp2 = hp;

    HasPtr hp3(s2);
    HasPtr hp4 = hp3;
    HasPtr hp5 = hp3;
    
    hp.print();
    hp2.print();
    hp3.print();
    hp4.print();
    hp5.print();

    return 0;
}
