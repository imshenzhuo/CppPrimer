# 1 

> What is a copy constructor? When is it used?

如果一个类的构造函数第一个参数是该类的类引用，且没有其他参数或者其他参数都有默认值，那这个函数就是拷贝构造函数

使用

- = 运算符号,拷贝初始化
- 初始化非引用类类型参数
- 初始化列表
- 其他  容器的insert

# 2

> Explain why the following declaration is illegal:
>
> ```` cpp
> Sales_data::Sales_data(Sales_data rhs);
> ````
>
> 

如果是这样的话，当调用函数时，初始化非引用类类型，就要调用拷贝构造函数，无限递归

# 3

> What happens when we copy a StrBlob? What about StrBlobPtrs?
>
> ``` cpp
> class StrBlobPtr;
>  
> class StrBlob {
>     friend class StrBlobPtr;
>     public:
>         typedef std::vector<std::string>::size_type size_type;
>         StrBlob();
>         StrBlob(std::initializer_list<std::string> il);
>         size_type size() const{ return data->size(); }
>         bool empty() const { return data->empty(); }
>         void push_back(const std::string& t) { data->push_back(t); }
>         void pop_back();
>         std::string& front() ;
>         std::string& back() ;
>         StrBlobPtr begin();
>         StrBlobPtr end();
>     private:
>         std::shared_ptr<std::vector<std::string> > data;
>         void check(size_type i, const std::string &msg) const;
> };
>  
> class StrBlobPtr {
>     public:
>         StrBlobPtr() : curr(0) {}
>         StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
>         std::string& deref() const;
>         StrBlobPtr& incr();
>     private:
>         std::shared_ptr<std::vector<std::string> >
>         check(std::size_t, const std::string&) const;
>         std::weak_ptr<std::vector<std::string> > wptr;
>         std::size_t curr;
> };
> ```

拷贝`StrBlob`时，调用编译器的合成拷贝构造函数，拷贝`StrBlob`的唯一成员：智能指针，两个对象都指向同一个动态内存，引用数＋1；拷贝`StrBlobPtr`时，调用编译器的合成拷贝构造函数，拷贝`C++`基本成员，以及`weak_ptr`，但是`weak_ptr`指向的动态内存对象引用数不会＋1

# 4

> Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:
>
> ```cpp
> Point global;
> Point foo_bar(Point arg) // 1
> {
>  Point local = arg,/**2*/ *heap = new Point(global); //3
>  *heap = local;
>  Point pa[ 4 ] = { local, *heap }; // 4 5
>  return *heap; // 6
> }
> ```

# 5 [exer13_5.cpp](./exer13_5.cpp)

> Given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps
> points, rather than copying ps itself. 
>
> ```cpp
> class HasPtr {
> public:
>     HasPtr(const std::string &s = std::string()):
>         ps(new std::string(s)), i(0) { }
> private:
>     std::string *ps;
>     int    i;
> };
> ```
>
``` cpp
HashPtr(const HasPtr& ori): 
	i(ori.i),
	ps(new std::string())
     {}
```



# 6

> What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?

拷贝赋值运算符是一个`operator=`函数

赋值的时候使用

给等号左边的每一个非static数据成员赋值

没有重载`=`的时候，生成合成拷贝赋值运算符

# 7

> What happens when we assign one StrBlob to another? What about StrBlobPtrs?

StrBlob.cpp & StrBlobPtr 定义见题目3

产生了一样的效果`

# 8 [exer13_8.cpp](./exer13_8.cpp)

> Write the assignment operator for the HasPtr class from exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your assignment operator should copy the object to which ps points.

有点点疑问。第一步就delete ps这样会有什么问题吗？

``` cpp
HasPtr& HasPtr::operator=(const HasPtr &rhs){
    delete ps;
    ps = new string(*(rhs.ps));
    return *this;
}
```

当参数是自己的时候，也就是自赋值时，上述代码会出现二次释放！所以更改如下

``` cpp
HasPtr& HasPtr::operator=(const HasPtr &rhs){
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}
```



# 9

> What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?

析构函数用来销毁类对象的成员函数。构造函数的逆序释放非static的成员；没有定义时候会生成合成析构函数

# 10

> What happens when a StrBlob object is destroyed? What about a StrBlobPtr?

StrBlob 释放成员数据，也就是智能指针，对象的引用数减一，当为零时，释放动态内存

StrBlobPtr 释放成员数据，但是由于是weak_ptr，不影响所指对象

# 11 [exer13_11.cpp](./exer13_11.cpp)

> Add a destructor to your HasPtr class from the previous exercises.

# 12

> How many destructor calls occur in the following code fragment?
>
> ``` cpp
> bool fcn(const Sales_data *trans, Sales_data accum)
> {
>     Sales_data item1(*trans), item2(accum);
>     return item1.isbn() != item2.isbn();
> }
> ```

三次；分别是参数`accum`，局部变量`item1`和`item2`

# 13 [exer13_13.cpp](./exer13_13.cpp)

> A good way to understand copy-control members and constructors is to define a simple class with these members in which each member prints its name:
>
> ``` cpp
> struct X {
>     X() {std::cout << "X()" << std::endl;}
>     X(const X&) {std::cout << "X(const X&)" << std::endl;}
> };
> ```
>
> Add the copy-assignment operator and destructor to X and write a program using X objects in various ways: Pass them as nonreference and reference parameters;dynamically allocate them; put them in containers; and so forth. Study the output until you are certain you understand when and why each copy-control member is used. As you read the output, remember that the compiler can omit calls to the copy constructor.



# 14 [exer13_14.cpp](./exer13_14.cpp)

> Assume that numbered is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named mysn. Assuming numbered uses the synthesized copy-control members and given the following function:
>
> ```cpp
> void f (numbered s) { cout << s.mysn << endl; }
> ```
>
> what output does the following code produce?
>
> ``` cpp
> numbered a, b = a, c = b;
> f(a); f(b); f(c);
> ```



``` cpp
numberd a; // 默认构造函数
numbered b = a; // 拷贝初始化  合成拷贝构造函数 完全copy 没有+1
```

# 15 [exer13_15.cpp](./exer13_15.cpp)

> Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?

a b c的值为1 2 3 但是输出 2 3 4，非引用参数也是拷贝初始化，调用拷贝构造函数，拷贝构造函数内写的是参数+1，所以自然形参的值就都比实参的多1

# 16 [exer13_16.cpp](./exer13_16.cpp)

> What if the parameter in f were const numbered&? Does that change the output? If so, why? What output gets generated?

引用没有拷贝，所以就是预计值1 2 3

# 17 

> Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.

# 18 [exer13_18.cpp](./exer13_18.cpp)

> Define an Employee class that contains an employee name and a unique employee identifier. Give the class a default constructor and a constructor that takes a string representing the employee’s name. Each constructor should generate a unique ID by incrementing a static data member.

# 19 [exer13_19.cpp](exer13_19.cpp)

> Does your Employee class need to define its own versions of the copy-control members? If so, why? If not, why not? Implement whatever copy-control members you think Employee needs.

不用。`Employee`本就不应该有这些操作，所以禁用。

# 20

> Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes
>
> ``` cpp
> class QueryResult; // declaration needed for return type in the query function
> class TextQuery {
> public:
>     using line_no = std::vector<std::string>::size_type;
>     TextQuery(std::ifstream&);
>     QueryResult query(const std::string&) const;
> private:
>     std::shared_ptr<std::vector<std::string>> file;  // input file
>     // map of each word to the set of the lines in which that word appears
>     std::map<std::string,std::shared_ptr<std::set<line_no>>> wm;
> };
> class QueryResult {
> friend std::ostream& print(std::ostream&, const QueryResult&);
> public:
>     QueryResult(std::string s,
>                 std::shared_ptr<std::set<line_no>> p,
>                 std::shared_ptr<std::vector<std::string>> f):
>         sought(s), lines(p), file(f) { }
> private:
>     std::string sought;  // word this query represents
>     std::shared_ptr<std::set<line_no>> lines; // lines it's on
>     std::shared_ptr<std::vector<std::string>> file; // input file
> };
> ```

拷贝时调用合成拷贝构造函数，成员复制，智能指针所指的引用＋1；赋值时候调用合成拷贝赋值运算符，相同的操作，最后销毁调动析构函数，智能指针释放，引用数－1；

# 21 [exer13_21_project.cpp][./exer13_21_project.cpp]

> Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think
> these classes require.

要delete，拷贝没有意义要禁止该操作。

# 22 [exer13_22.cpp](./exer13_22.cpp)

> Assume that we want HasPtr to behave like a value. That is, each object should have its own copy of the string to which the objects point. We’ll show the definitions of the copy-control members in the next section. However, you already know everything you need to know to implement these members. Write the HasPtr copy constructor and copy-assignment operator before reading on.

# 23

> Compare the copy-control members that you wrote for the solutions to the previous section’s exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.

理解了。到处是坑，不过《C++ Primer》好书！

# 24

> What would happen if the version of HasPtr in this section didn’t define a destructor? What if HasPtr didn’t define the copy constructor?

没有析构函数：会发生内存泄露，对象销毁，但是成员函数string不会销毁

没有拷贝构造函数：那么所有通过拷贝初始化的对象都会有一个共同的string成员

# 25

> Assume we want to define a version of StrBlob that acts like a value. Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr class can still use a weak_ptr to the vector. Your
> revised class will need a copy constructor and copy-assignment operator but will not need a destructor. 
>
> Explain what the copy constructor and copy-assignment operators must do. Explain why the class does not need a destructor.

拷贝构造函数和拷贝赋值运算符需要将智能指针指向的动态内存拷贝，所有智能指针的引用数都为1

因为都是智能指针，引用数为零时自动释放内存，所以不需要手动析构。

# 26 [exer13_26.cpp](./exer13_26.cpp)

> Write your own version of the StrBlob class described in the previous exercise.

# 27 [exer13_27.cpp](./exer13_27.cpp)

> Define your own reference-counted version of HasPtr.

# 28

> Given the following classes, implement a default constructor and the necessary copy-control members.
>
> ``` cpp
> class TreeNode {
> private:
>      std::string value;
>      int         count;
>      TreeNode    *left;
>      TreeNode    *right;
>  };
> ```
>
> ``` cpp
> class BinStrTree {
>       private:
>            TreeNode *root;
>       };
> ```

``` cpp
class TreeNode {
public:
    TreeNode() : value(""), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode& t) : value(t.value), count(t.count), left(t.left), right(t.right) { }
private:
     std::string value;
     int         count;
     TreeNode    *left;
     TreeNode    *right;
 };
```

# 29 

> Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.

参数类型不同，函数重载

# 30 [exer13_30.cpp](./exer13_30.cpp)

> Write and test a swap function for your valuelike version of HasPtr. Give your swap a print statement that notes when it is executed.

# 31 [exer13_31.cpp](./exer13_31.cpp)

> Give your class a < operator and define a vector of HasPtrs. Give that vector some elements and then sort the vector.
>
> Note when swap is called.

??? 没有识别？或者说是根据声明识别

# 32 

> Would the pointerlike version of HasPtr benefit from defining a swap function? If so, what is the benefit? If not, why not?

自定义swap是为了避免值型的类型不必要拷贝，指针型的就没有必要了

# 33

> Why is the parameter to the save and remove members of Message a Folder&? Why didn’t we define that parameter as Folder? Or const Folder&?

因为要修改参数的内容

# 34 [exer13_34.cpp](./exer13_34.cpp)

> Write the Message class as described in this section.

# 35

> What would happen if Message used the synthesized versions of the copy-control members?

本义是想要复制一个message，得到两个message，两个message所在的folder是相同的。而且folder由原来的一个message，变为两个message

如果使用合成拷贝构造函数的话，只能实现前者，folder不会有变化。

# 36&37 [exer36&37](./mail.cpp)

> Add members to the Message class to insert or remove a given Folder* into folders. These members are analogous to Folder’s addMsg and remMsg operations.

编程过程发现，函数中先创建的后销毁；如果没有编写其中一个类的析构函数，并且该类先销毁的话，会造成`double free`

# 38

> We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?











## 遗留问题

- 28 数据结构：二叉树
- 31 友元、重载操作符
- 38 拷贝并交换

