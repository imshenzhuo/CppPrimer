/*************************************************************************
    > File Name: exer16_4.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月20日 星期五 15时24分34秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

template <typename Titr, typename T>
Titr find(Titr it, Titr end, const T t) {
    while(it!=end) {
        if (*it == t)   return it;
        ++it;
    }
    return end;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v = {2,1,5,3,7};
    auto it = find(v.begin(), v.end(), 5);
    while(it!=v.cend()) {
        cout << *it++ << endl;
    }
    return 0;
}

