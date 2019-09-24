/*************************************************************************
    > File Name: exer16_16.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月24日 星期二 13时07分46秒
 ************************************************************************/

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include<iostream>
using namespace std;

template <typename T> class Vec
{
public:
    Vec():elements(nullptr), first_free(nullptr), cap(nullptr) { }
    Vec(const Vec<T>&);
    Vec& operator=(const Vec<T>&);
    ~Vec();

    void push_back(const T&);
    size_t size() const {   return first_free - elements;   }
    size_t capacity() const { return cap - elements;  }
    T *begin() const { return elements; }
    T *end() const { return first_free; }
private:
    // 容量满了充分配
    void chk_n_alloc(){
        if (size() == capacity())  reallocate();
    }
    // 分配内存 并且拷贝范围元素
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    // 销毁元素释放内存
    void free();
    void reallocate();

    std::allocator<T> alloc;
    T *elements;
    T *first_free;
    T *cap;
};

template <typename T>
void Vec<T>::push_back(const T &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e){
    auto data = alloc.allocate(e - b);
    return {data, unintialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free(){
    if(elements) {
        for(auto p = first_free; p!=elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::~Vec() { free(); }

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate()
{
     // we'll allocate space for twice as many elements as the current size
     auto newcapacity = size() ? 2 * size() : 1;
     // allocate new memory
     auto newdata = alloc.allocate(newcapacity);
     // move the data from the old memory to the new
     auto dest = newdata;  // points to the next free position in the new array
     auto elem = elements; // points to the next element in the old array
     for (size_t i = 0; i != size(); ++i)
         alloc.construct(dest++, std::move(*elem++));
     free();  // free the old space once we've moved the elements
     // update our data structure to point to the new elements
     elements = newdata;
     first_free = dest;
     cap = elements + newcapacity;
}

int main(int argc, char const *argv[])
{
    Vec<string> v;
    v.push_back("1");
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    // v.push_back("9");
    // v.push_back("9");
    // v.push_back("7");
    /* code */
    return 0;
}


