/*************************************************************************
    > File Name: Screen.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年08月30日 星期五 17时16分42秒
 ************************************************************************/

#include<iostream>
using namespace std;


class Screen{
	public:	
		using pos = std::string::size_type;
		Screen() = default;
		Screen(int width, int height) : width(width), height(height) { }
		Screen(int width, int height, char c) : width(width), height(height), contents(width*height, c) { }
		
		Screen &move(pos r, pos c) {
			pos row = r * width;
			cursor = row + c;
			return *this;
		}

		char get(pos r, pos c) const {
			pos row = r * width;
			return contents[row + c];
		}

		Screen &set(char c) {
			contents[cursor] = c;
			return *this;
		}

		Screen &display(ostream &os) {
			print(os, *this);
			return *this;
		}

		ostream &print(ostream &os, const Screen &s) {
			os << "contents is " << s.contents << endl
				<< "heigth is " << s.height << endl
				<< "width is " << s.width << endl
				<< "cursor is " << s.cursor << endl;
		}

	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;

};

int main() {
	/*
	Screen s(24, 12,'*');
	Screen s1 = s;
	s.print(cout, s);
	s1.print(cout, s1);
	*/
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << endl;
	myScreen.display(cout);
	cout << endl;
	
}
