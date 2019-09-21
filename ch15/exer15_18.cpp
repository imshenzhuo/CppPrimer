/*************************************************************************
    > File Name: exer15_18.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月19日 星期四 09时09分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Base
{
public:
    void pub_mem();
protected:
    int prot_men;
private:
    char priv_mem;
};


struct Pub_Derv : public Base
{
    int f() {
        return prot_men;
    }    
};


struct Priv_Derv : private Base
{
    int f1() {
        // return prot_men + pub_mem + priv_mem;
        return prot_men;

    }
};

struct Derived_from_Public : public Pub_Derv
{
    int use_base() {
        return prot_men;
    }
};


struct Derived_from_Private : public Priv_Derv
{
    // int use_base() {
        // return prot_men;
    // }
};


int main(int argc, char const *argv[])
{
    Pub_Derv d1;
    Priv_Derv d2;

    Derived_from_Public dd1;
    Derived_from_Private dd2;

    Base *p = &d1;
    // p = &d2; //  error: ‘Base’ is an inaccessible base of ‘Priv_Derv’
    p = &dd1;
    // p = &dd2; // error: ‘Base’ is an inaccessible base of ‘Derived_from_Private’
    
    return 0;
}


