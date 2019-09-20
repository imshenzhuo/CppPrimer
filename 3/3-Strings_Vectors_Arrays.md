## 3.1 namespace using declarations

## 3.2 Library string Type

```cpp
#include <string>   // string在库string中
using std::string; // string定义在std空间
```

###  3.2.1 定义和初始化

- copy初始化 带`=`
- 直接初始化 省略`=`

```cpp
string s1;
string s2 = s1;
string s3 = "hiya";
string s4("hiya");
string s5(5, 'c');
```

### 3.2.2 string的操作

#### 读写string

```cpp
string s;
// whitespace分割  space \t \n
cin >> s; // 得到的s不可能有空白符
getline(cin, s); // 得到的s是一行，不可能有回车
```

#### 横看成岭

不像是java，string的成员函数不够直观

```cpp
string s;
...
s.empty(); // bool
s.size();
```

size()返回的既不是`int`也不是`unsigned`，而是`string::size_type` 有啥不一样？

companion types: the name size_type is defined in the string class.

``` cpp
auto len = s.size(); // type of len is string::size_type
```

len实际是是unsigned的，这就有意思了， 如果加一个同类型的负数的话……

#### add

字符串相加`+`的两侧，至少有一个是string类型

```cpp
string s6 = (s1 + ", ") + "world";
string s7 = ("hello" + ", ") + s2; // error: can't add string literals
```



### 3.2.3 处理string中的一个字符

#### cctype vs type.h

内容是一样的，除了

- cctype更cpp
- cctype的内容定义在std命名空间内

#### cpp11 range for

``` cpp
string s("HEllow");
for (char c : s){
    cout << c << endl;
}
string s("Hello World!!!");
// convert s to uppercase
for (auto &c : s)   // for every char in s (note: c is a reference)
    c = toupper(c); // c is a reference, so the assignment changes the char in s
cout << s << endl;
```

#### 访问单个字符

> 有两种方法  下标和迭代器，此处只说下标

下标法

- 接受一个 string::size_type类型
- 返回该字符的一个引用

## 3.3 vector

``` cpp
#include<vector>
using std::vector;
```

vector是一个类模板，但是现在不需要知道那么多，会用就可以了，毕竟介绍类模板还是在第16章

只需要告诉编译器根据那个类模板生成某某类型的类就可以了

### 3.3.1 定义和初始化

- 默认初始化
- 复制初始化
- list初始化

When we copy a vector, each element in the new vector is a copy of the corresponding element in the
original vector.

``` cpp
vector<int> ivec;             // initially empty
// give ivec some values
vector<int> ivec2(ivec);      // copy elements of ivec into ivec2
vector<int> ivec3 = ivec;     // copy elements of ivec into ivec3
vector<string> svec(ivec2);   // error: svec holds strings, not ints
vector<string> articles = {"a", "an", "the"};
```

#### 分清楚是计数还是值

如果是`{}`首先看能不能list初始化，如果不能就找别的构造方法

```cpp
vector<int> v1(10);    // v1 has ten elements with value 0
vector<int> v2{10};    // v2 has one element with value 10
vector<int> v3(10, 1); // v3 has ten elements with value 1
vector<int> v4{10, 1}; // v4 has two elements with values 10 and 1
vector<string> v5{"hi"}; // list initialization: v5 has one element
vector<string> v6("hi"); // error: can't construct a vector from a string literal
vector<string> v7{10};       // v7 has ten default-initialized elements
vector<string> v8{10, "hi"}; // v8 has ten elements with value "hi"
```

### 3.3.2 add 

push_back

注意：range for循环只能用于size不变的情况

### 3.3.3 其他操作

#### size

```cpp
// v.size() 返回类型
vector<int>::size_type // ok
vector::size_type      // error
```

#### cmp

和string类似的字典顺序

## 3.4 迭代器

> 所有的库容器都支持迭代器，但是只有少数才支持下标操作

### 3.4.1 USE

``` cpp
string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
    auto it = s.begin();    // it denotes the first character in s
    *it = toupper(*it);     // make that character uppercase
}
```

begin end的返回类型取决于迭代对象是否是const

``` cpp
vector<int> v;
const vector<int> cv;
auto it1 = v.begin();  // it1 has type vector<int>::iterator
auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
```

cpp11

``` cpp
auto it3 = v.cbegin(); // it3 has type vector<int>::const_iterator
```

访问迭代器所指对象两种方式

``` cpp
// print each line in text up to the first blank line
for (auto it = text.cbegin();
     it != text.cend() && !it->empty(); ++it)
    cout << *it << endl;
```

迭代器可以算术加减还可以比较。这是和其他语言最不一样的地方了。

## 3.5 Arrays

维数一定要在编译期内确定，维数一定是常量表达式

```cpp
unsigned cnt = 42;          // not a constant expression
constexpr unsigned sz = 42; // constant expression
                            // constexpr see § 2.4.4 (p. 66)
int arr[10];             // array of ten ints
int *parr[sz];           // array of 42 pointers to int
string bad[cnt];         // error: cnt is not a constant expression
string strs[get_size()]; // ok if get_size is constexpr, error otherwise

const unsigned sz = 3;
int ia1[sz] = {0,1,2};        // array of three ints with values 0, 1, 2
int a2[] = {0, 1, 2};         // an array of dimension 3
int a3[5] = {0, 1, 2};        // equivalent to a3[] = {0, 1, 2, 0, 0}
string a4[3] = {"hi", "bye"}; // same as a4[] =  {"hi", "bye", ""}
int a5[2] = {0,1,2};          // error: too many initializers
```

注意char array可以比较特殊 the dimensions of a2 and a3 are both 4.

``` cpp
char a1[] = {'C', '+', '+'};       // list initialization, no null
char a2[] = {'C', '+', '+', '\0'}; // list initialization, explicit null
char a3[] = "C++";                 // null terminator added automatically
const char a4[6] = "Daniel";       // error: no space for the null!
```

Unlike subscripts for vector and string, the index of the built-in subscript operator is not an unsigned type.

Array的下标运算是有符号的，甚至可以是负数

``` cpp
int ia[] = {0,2,4,6,8};  // array with 5 elements of type int
int i = ia[2];  // ia is converted to a pointer to the first element in ia
                // ia[2] fetches the element to which (ia + 2) points
int *p = ia;    // p points to the first element in ia
i = *(p + 2);   // equivalent to i = ia[2]
int *p = &ia[2];  // p points to the element indexed by 2
int j = p[1];     // p[1] is equivalent to *(p + 1),
                  // p[1] is the same element as ia[3]
int k = p[-2];    // p[-2] is the same element as ia[0]
```

### 3.5.5 C-style Character Strings

> C-style strings are a surprisingly rich source of bugs and are the root cause of many security problems.



# 问题

getline是在std空间内的吗？ iostream	