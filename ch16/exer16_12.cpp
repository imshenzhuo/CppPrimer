/*************************************************************************
    > File Name: exer16_12.cpp
    > Author: shenzhuo
    > Mail: im.shenzhuo@gmail.com 
    > Created Time: 2019年09月24日 星期二 10时18分01秒
 ************************************************************************/

#include <iostream>
 
#include <vector>
#include <string>
#include <initializer_list>
 
#include <memory>
 
#include <cstddef>
#include <stdexcept>
 
using namespace std;

template <typename T> class Blob; 
template <typename T> class BlobPtr;
template <typename T> 
    bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T> (const Blob<T>&, const Blob<T>&);
    public:
        typedef typename std::vector<T>::size_type size_type;
        Blob();
        Blob(std::initializer_list<T> il);
        size_type size() const{ return data->size(); }
        bool empty() const { return data->empty(); }
        void push_back(const T& t) { data->push_back(t); }
        void pop_back();
        T& front() ;
        T& back() ;
        BlobPtr<T> begin();
        BlobPtr<T> end();
    private:
        std::shared_ptr<std::vector<T> > data;
        void check(size_type i, const std::string &msg) const;
};
 
template <typename T> class BlobPtr {
    public:
        BlobPtr() : curr(0) {}
        BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
        T& deref() const;
        BlobPtr<T>& incr();
    private:
        std::shared_ptr<std::vector<T> >
        check(std::size_t, const std::string&) const;
        
        std::weak_ptr<std::vector<T> > wptr;
        std::size_t curr;
};

template <typename T> 
Blob<T>::Blob():data(std::make_shared<std::vector<T>>()) {}

template <typename T> 
Blob<T>::Blob(std::initializer_list<T> il):
        data(std::make_shared< std::vector<T> >(il)) {}

template <typename T> 
void Blob<T>::check(size_type i, const std::string &msg) const {
    if(i >= data->size())
        throw out_of_range(msg);
}
template <typename T> 
T& Blob<T>::front () {
    check(0, "front on empty StrBlob");
    return data->front();
}
template <typename T> 
T& Blob<T>::back () {
    check(0, "back on empty StrBlob");
    return data->back();
}
template <typename T> 
void Blob<T>::pop_back () {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

template <typename T> 
BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}


template <typename T> 
BlobPtr<T> Blob<T>::end() {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
 

template <typename T> 
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template <typename T> 
T& BlobPtr<T>::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
template <typename T> 
BlobPtr<T>& BlobPtr<T>::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
 
int main (void) {
 
    Blob<std::string> b1;
    //{}释放b2
    {
        Blob<std::string> b2 = {"baby", "girl", "lady", "woman", "female"};
        b1 = b2;
        b2.push_back("pretty");
    }
    std::cout << "b1 size = " << b1.size() << std::endl;
    std::cout << "b1.begin() = " << b1.begin().deref() << std::endl;
    std::cout << "b1.begin().incr().deref() = "
            << b1.begin().incr().deref() << std::endl;

    Blob<int> b3;
    {
        Blob<int> b4 = {1, 9, 9, 6};
        b3 = b4;
        b4.push_back(11);
    }
    std::cout << "b3 size = " << b3.size() << std::endl;
    std::cout << "b3.begin() = " << b3.begin().deref() << std::endl;
    std::cout << "b3.begin().incr().deref() = "
            << b3.begin().incr().deref() << std::endl;
   
 
    return 0;
 
}