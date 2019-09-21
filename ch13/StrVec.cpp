#include "StrVec.hpp"
#include <string>

using namespace std;

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e){
    auto data = alloc.allocate(e - b);
    return {data, unintialized_copy(b, e, data)};
}

void StrVec::free(){
    if(elememts) {
        for(auto p = first_free; p!=elememts;)
            alloc.destroy(--p);
        alloc.deallocate(elememts, cap - elememts);
    }
}

StrVec::StrVec(const StrVec &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs)
{
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
     // we'll allocate space for twice as many elements as the current size
     auto newcapacity = size() ? 2 * size() : 1;
     // allocate new memory
     auto newdata = alloc.allocate(newcapacity);
     // move the data from the old memory to the new
     auto dest = newdata;  // points to the next free position in the new
array
     auto elem = elements; // points to the next element in the old array
     for (size_t i = 0; i != size(); ++i)
         alloc.construct(dest++, std::move(*elem++));
     free();  // free the old space once we've moved the elements
     // update our data structure to point to the new elements
     elements = newdata;
     first_free = dest;
     cap = elements + newcapacity;
}


