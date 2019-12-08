# 字符串 向量 数组

## 3.1 命名空间的using声明

using声明后, 就可以不用在`std::xxx`了

``` c++
using std::cin;
using std::cout;
using std::endl;
```

### 头文件不应该包含using声明

头文件的内容会被拷贝到所有引用它的文件中, 头文件不使用using声明可以避免可能出现的命名空间冲突

## 3.2 标准库类型string

```cpp
#include <string>   // string在库string中
using std::string; // string定义在std空间
```

###  3.2.1 定义和初始化

- copy初始化 有`=`
- 直接初始化 没有`=`

```cpp
string s1;
string s2(s1);
string s2 = s1;
string s4("hiya");
string s3 = "hiya";
string s5(5, 'c');
```

### 3.2.2 string对象上的操作

``` c++
os<<s  s写入os, 返回写好的os
is>>s  
getline(is, s) 返回is
s.empty();	   返回bool
s.size();	   返回string::size_type
				1. 无符号
				2. 适用于string所有的长度
s[n];
s1 + s2;
s1 = s2;
s1 == s2;
s1 != s2;
< , <= , >, >=
```

#### add

字符串相加`+`的两侧，至少有一个是string类型

```cpp
string s6 = (s1 + ", ") + "world";
string s7 = ("hello" + ", ") + s2; // error: can't add string literals
```

- getline读到的字符串不包括`\n`
- 字符串字面值不是string类型(和C兼容)

### 3.2.3 处理string中的一个字符

#### cctype vs type.h

内容是一样的，除了

- cctype更cpp
- cctype的内容定义在std命名空间内

```C
isalnum(c);
isalpha(c);
iscntrl(c);
isdigit(c);
ispunct(c);
tolower(c);
```

#### range for `c++11`

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

- 接受一个 `string::size_type`类型参数
- 返回该字符的一个引用

## 3.3 标准库类型vector

``` c++
#include<vector>
using std::vector;
```

vector是一个类模板，但是现在不需要知道那么多，会用就可以了，毕竟介绍类模板还是在第16章

只需要告诉编译器根据那个类模板生成某某类型的类, 让编译器实例化就可以了

老式的`vector<vector<int> >`最后两个`>`要加空格, `C++11`后不用加

### 3.3.1 定义和初始化

``` C++
vector<T> v1;
vector<T> v2(v1);
vector<T> v2 = v1;
vector<T> v3(n, val);
vector<T> v4(n);
vector<T> v5{a, b, c, ...};
vector<T> v5 = {a, b, c...};
```

#### 分清楚是计数还是值

如果是`{}`首先看能不能list初始化，如果不能就找构造方法

```cpp
vector<string> v5{"hi"}; // list initialization: v5 has one element
vector<string> v6("hi"); // error: can't construct a vector from a string literal
vector<string> v7{10};       // v7 has ten default-initialized elements
vector<string> v8{10, "hi"}; // v8 has ten elements with value "hi"
```

### 3.3.2 add 

push_back

注意：range for循环只能用于size不变的情况

### 3.3.3 其他操作

类似于String, 同意支持下标操作

``` c++
v.empty();
v.size(); // 返回类型vector<T>::size_type
v.push_back();
v[n];
v1 = v2;
v1 == v2;
<, <=, >, >=;
```

## 3.4 迭代器

> 所有的库容器都支持迭代器，但是只有少数才支持下标操作

### 3.4.1 使用迭代器

``` cpp
// 第一个字母变成大写
string s("some string");
if (s.begin() != s.end()) { // make sure s is not empty
    auto it = s.begin();    // it denotes the first character in s
    *it = toupper(*it);     // make that character uppercase
}
```

#### 迭代器类型

begin end的返回类型取决于迭代对象是否是const

``` cpp
vector<int> v;
auto it1 = v.begin();  // it1 has type vector<int>::iterator
const vector<int> cv;
auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
```

C++11

``` cpp
auto it3 = v.cbegin(); // it3 has type vector<int>::const_iterator
```

注意:**任意改变`vector`容量的操作都会使该对象的迭代器失效!**

### 3.4.2 迭代器运算

``` C++
iter1 - iter2; //两个迭代器之间的距离 返回的类型是带符号的 difference_type
if (iter < mid);// 有先后顺序 
```

迭代器可以算术加减还可以比较。这是和其他语言最不一样的地方了。

## 3.5 数组

数组和指针引用一样, 都是内置复合数据类型

### 3.5.1 定义和初始化

- 不能拷贝和赋值
- 维数一定要在编译期内确定，维数一定是常量表达式

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

``` C++
int *(&array)[10] = ptrs;	// array是个引用 引用包含10个元素的数组  数组的元素类型是int指针
```

### 3.5.2 访问数组元素

同样可以使用for range语句循环访问

### 3.5.3 指针和数组

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

C风格字符串就是约定以`\0`结尾的字符串

#### C标准String函数

``` C
#include <cstring>
strlen(p); //不包括\0
strcmp(p1, p2);
strcat(p1, p2);
strcpy(p1, p2);
```

连接字符串, C风格要求新的string必须事先知道并且分配足够空间, 但是这是很难的, 也是Bug出现的主要源头.

``` C++
string s1 = "aaaaa";
string s2 = "bbbbbb";
string s = s1 + s2;
// --------没什么问题--------
const char ca1[] = "aaaaa";
const char ca2[] = "bbbbb";
// ca1 + ca2 Error
strcpy(newca, ca1);
strcat(newca, ca2);
```

### 3.5.6 兼容

#### string和C风格

``` C++
string s = "aaaaaa";
const char *str = s.c_str();
```

#### vector和数组

``` C++
int arr[] = {0, 1, 3, 4};
vector<int> ivec(begin(arr), end(arr));
vector<int> ivec(arr, arr+3);
```