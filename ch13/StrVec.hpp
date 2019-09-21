#include <memory>
#include<string>
using std::string;

class StrVec
{
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const {   return first_free - elements;   }
    size_t capacity() const { return cap - elements;  }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
private:
    static std::allocator<string> alloc;
    // 容量满了充分配
    void chk_n_alloc(){
           if (size() == capacity())  reallocate();
    }
    // 分配内存 并且拷贝范围元素
    std::pair<string*, string*> alloc_n_copy(const string*, const string*);
    // 销毁元素释放内存
    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};