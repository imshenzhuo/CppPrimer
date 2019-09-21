/*************************************************************************
    > File Name: test15_5.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月19日 星期四 09时59分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Base{
public:
    int base_public;

protected:
    int base_protected;

private:
    int base_private;    
};


class Pub_De : public Base {
public:
    void f() {
        cout << base_protected << endl;
    }

};


class Pri_De : private Base
{
public:
    void f() {
        cout <<  base_public << endl;
        cout <<  base_protected << endl;
        // cout <<  base_private << endl;
    }
};

int main(int argc, char const *argv[])
{
    Pub_De pd;
    pd.base_public = 100;
    // error
    // pd.base_protected = 100;
    pd.f();

    Pri_De ppd;
    // ppd.base_protected = 100;
    // ppd.base_public = 100;
    ppd.f();
    return 0;
}

