#include <iostream>
#include <vector>
#include <string>


using namespace std;

class paper {

public:
    paper(int y, string p, string n, string t) :
        year(y), publish(p), name(n), title(t) {}
    
    void setYear(int year) {
        this->year = year;
    }

    paper(const paper& p) {
        cout << "under copy constructor function" << endl;
        year = p.year;
        publish = p.publish;
        name = p.name;
        title = p.title;
    }    

private:
    int year;
    string publish;
    string name;
    string title;    
};

paper updateYear(paper p, int year) {
    p.setYear(year);
    return p;
}

int main(int argc, char const *argv[])
{
    paper p1(2014, "sci", "ayj", "spc"); // 显式调用普通构造函数
    paper p2(p1); // 显式调用拷贝构造函数 1
    paper p3 = p2; // 隐式调用拷贝构造函数 1

    cout << "------function---------" << endl;
    int year = 2019;
    paper p4 = updateYear(p3, year);
    // 非引用参数形参隐式调用拷贝构造函数 2
    // 返回一个非引用类型隐式调用拷贝构造函数 3

    cout << "-------collection----------" << endl;
    vector<paper> vpaper; cout << "one\n";
    vpaper.push_back(p1); cout << "one\n";
    vpaper.push_back(p2); cout << "one\n";
    vpaper.push_back(p3); cout << "one\n";
    vpaper.push_back(p4); cout << "one\n";
    // 向集合添加隐式调用拷贝构造函数
    // 但是次数为什么不一样呢?
    return 0;
}
