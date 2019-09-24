/*************************************************************************
    > File Name: exer16_14.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月24日 星期二 11时11分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

using pos = std::string::size_type;

template <pos, pos> class Screen;

template <pos H, pos W> std::istream& operator>>(std::istream&, Screen<H, W>&);
template <pos H, pos W> std::ostream& operator<<(std::ostream&, const Screen<H, W>&);


template <pos H, pos W> class Screen {
    friend std::istream& operator>>(std::istream&, Screen<H, W>&);
    friend std::ostream& operator<<(std::ostream&, const Screen<H, W>&);
public: 
    Screen() = default;
    Screen(char c) : contents(H * W, c) {}


    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * W + c];  }

    Screen& move(pos r, pos c) {
        cursor = r * W + c;
        return *this;
    }
    
    Screen &set(char c) {
        contents[cursor++] = ch;
        cursor = std::min(cursor, H * W);
        return *this;
    }
private:
    pos cursor = 0;
    std::string contents;

};

template <pos H, pos W>
std::istream& operator>>(std::istream& is, Screen<H, W>& s)
{
    std::string input;
    is >> input;
    for (char ch : input) s.set(ch);
    return is;
}

template <pos H, pos W>
std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s)
{
    for (pos r = 0; r != H; ++r) {
        for (pos c = 0; c != W; ++c) {
            os << s.get(r, c);
        }
        os << std::endl;
    }
    return os;
}


int main() {
    /*
    Screen s(24, 12,'*');
    Screen s1 = s;
    s.print(cout, s);
    s1.print(cout, s1);
    */
    Screen<std::string> myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
    
}