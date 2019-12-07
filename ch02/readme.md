语言的最基本特征

- 内置类型&变量
- 表达式&语句
- if while控制流
- 函数

# 第二章 变量和基本类型

> **Types** are fundamental to any program: They tell us what our data **mean** and what **operations** we can perform on those data.

- 内置类型
- 初步了解c++如何支持更复杂的数据类型

## 2.1 基本内置类型

基本内置类型包括

- 算术类型: int float等
- 空类型: `nullptr`

### 2.1.1 算数类型

算数类型包括整型和浮点型，cpp标准规定了各个类型占用的最小位数

#### signed/unsigned

哪些类型区分有无符号? 整型**除了bool和扩展char类型**外，都区分有/无符号

**char是signed还是unsigned取决于编译器**

选择类型Tips

- 用`int`:`short`太短，long又往往和int一样，如果不够用long long
- 选`double` : `double`花销不一定比`float`大, float往往精度不够 long double没必要

### 2.1.2 类型转换

#### 赋值时

``` C
unsigned char c1 = -1; // 255
signed char c2 = 256; // 0 or 未定义(看操作系统)
// sizeof(1) = 4字节
// 这种赋值时候的做法像是直接截断
```

#### 判断时

if 条件判断自动转换  非bool <=> bool

unsigned类型永远都会大于等于零

#### 计算时

一般来讲是向上转换，尽量不丢失信息
**当一个有符号一个无符号，有符号转为无符号型** 所以根据这个可以得出无符号的最大值是多少

``` C
unsigned u = 10;
int i = -42;
cout << u + i << endl;
// i 先转换为无符号型，之后在相加
```

### 2.1.3 字面值常量

常量的类型都是什么？

常量的类型由前后缀显式决定, 前缀主要针对字符(串), 后缀针对数值

- L => long
- LL => long long
- f => float
- U => unsigned
- 注意到：对于浮点数 L是long double 默认double f是float

#### bool字面值和指针字面值

true false nullptr

## 2.2 变量

> A variable provides us with named storage that our programs can manipulate.

### 2.2.1 变量定义

#### 初始化和赋值

初始化是在**创建对象时**给该对象value，赋值是要**覆盖原来**的value，这在C++中真的有很大的区别(eg 隐式调用拷贝构造函数的一定要是初始化才行)

#### 列表初始化 `C++11`

``` c++
int unit_sold = 0;
int unit_sold = {0};
int unit_sold{0};
int unit_sold(0);
```

当存在**丢失信息**风险的时候, 编译器不答应

``` c++
int f{3.14}; // error
int f = {3.14}; // error
```

默认值取决于变**量的类型**和**定义的位置**

当内置类型变量定义在函数外时，会被初始化为0，在函数内时，随机数，正常访问


### 2.2.2 变量的声明和定义

为了分离编译，C++区分变量的声明和定义, 定义只有一次, 但是声明可以有多次

- **声明规定变量的类型和名字**
- **定义申请存储空间, 并可能赋值**

```C
extern int j; // 声明
int i; // 定义
extern double pi = 3.14; // 定义  显式初始化抵消了extern的作用
```

### scope

相同变量名在不同的scope可以有多个定义，内嵌的变量会**屏蔽外层的变量**，除非有特定的目的，不然不建议这样使用

``` c++
int reuse = 42;
int main()
{
    int reuse = 24;
    cout << reuse << endl; // 24
    cout << ::reuse << endl; // 42
}
```



## 2.3 复合类型

> A compound type is a type that is defined in terms of another type.引用和指针就是两种复合类型

### 2.3.1 引用

> 严格来说是左值引用

```C
int refVal = 2;
int &refVal3 = refVal; // reference
int &refVal2 = refVal3; // 2rd alias
```

### 2.3.2 指针

#### 空指针

- **nullptr** c++11
- 0
- NULL #include<cstdlib>

### 指针的引用

```C
int i = 42;
int *p;
int *&r = p;
r = &i;
*r = 0;
```

第三行从右往左读，`&r`代表是一个引用，`int *`代表一个整型指针的引用，所以最后r就是p的引用，就是p的第二个名字，就有了后面两行

**引用和指针到底有什么不同**

1. 指针本身是一个object，引用不是
2. 指针可以被赋值被复制，引用是一次性绑定
3. 指针不用初始化定义，引用一定要初始化

##### void *

- 可以存放任何对象的地址
- 不能直接操作`void *`指针所指的对象

## 2.4 const 限定符

const 修饰的变量必须定义时初始化，如果不初始化，也行，extern

``` C
extern const int bufSize; // 在多个文件之间共享const对象
```

### 2.4.1 const的引用

把引用绑定到常量对象

#### 定义

```C
const int ci = 1024;
const int &ref = ci;
r1 = 43; // Error
int &r2 = ci; // Error
```

引用类型和被引用对象类型不一致的特例: 可以用任意非const对象，常量 或者表达式**初始化常量引用**

```C++
int i = 42;
const int &r1 = i; // 用非const对象初始化常量引用
const int &r2 = 42; // 用常量来初始化常量引用
const int &r3 = r1 * 2; // 用任意表达式来初始化常量引用
int &r4 = r1 * 2; // Error
```
为什么类型不一致就可以引用呢?
``` c++
double dval = 3.14; 
const int &ri = dval; // pass
// ri => 3
int &ri = dval; // error
```

实际上是这样

```C
const int temp = dval;
const int &ri = temp;
```

所以就会产生以下现象

``` c++
double dval = 3.14;
const double &r1 = dval;
const int &r2 = dval;
cout << &rr << "," << &rr2 << "," << &dval << endl; // &dval == &r1 != &r2
```



### 2.4.2 指针和引用

``` C
const double pi = 3.14;   //pi is const; its value may not be changed
double *ptr = &pi;        //error: ptr is a plain pointer
const double *cptr = &pi; //ok: cptr may point to a double that is const
*cptr = 42;               //error: cannot assign to *cptr
// ----------------------------
int errNumb = 0;
int *const curErr = &errNumb;  // curErr will always point to errNumb
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const object
```

注意区分

- 指向常量的指针: `const int *` 指针指向的内容不能改变 low-level
- 常量指针 `int *const` 指针**本身**的内容(地址)不能改变 top-level

### 2.4.3 Top-Level const

```Cpp
int i = 0;
int *const p1 = &i;  // we can't change the value of p1; const is top-level
const int ci = 42;   // we cannot change ci; const is top-level
const int *p2 = &ci; // we can change p2; const is low-level
const int *const p3 = p2; // right-most const is top-level, left-most is not
const int &r = ci;  // const in reference types is always low-level
```

`const`关键字限定自己不能改变的就是top-level，否则就是low-level，当复制一个对象的时候，top-level忽略，**low-level不能忽略** , 当前对象不能该别人的(const指针和所有引用)就是底层const

> low-level 不同，类型不同，如果不能通过convert，就会Error

### 2.4.4 常量表达式

- 初始化定义常量
- 编译时就得到计算结果

``` c++
const int max_files = 20; // constexep
const int limit = max_files + 1; // constexep
int staff_size = 27; // not
const int sz = get_size();; // not
```

是不是常量表达式由数据类型和初识值一起决定.

#### constexpr 变量 c++11

使用constexpr声明的变量是使用常量表达式的常量

``` c++
constexpr int mf = 20;
constexpr int limit = mf + 1;
constexpr int sz = size(); // if function is constexpr
```

**constexpr和指针**

```Cpp
const int *p = nullptr;     // p is a pointer to a const int p是指向int常量的指针
constexpr int *q = nullptr; // q is a const pointer to int q是指向int的常量指针
```

区别非常大，constexpr在对象上组成了一个top-level const，所以p可以指向另一个const int类型的变量，但是q是top-level，不能改，只能初始化定义死了。

## 2.5 处理类型

### 2.5.1 类型别名

传统方法

``` cpp
typedef double wages; // wages => double
typedef wages base, *p; // base => double  p=>double *

typedef char *pstring;
const pstring cstr = 0; // cstr是=> char *const cstr
```

新方法

```cpp
// cpp 11
using sufu = wages;
```

### 2.5.2 auto c++11

cpp11 auto ordinarily ignores top-level consts.

``` cpp
int i = 0, &r = i;
const int ci = i, &cr = ci;
auto b = ci;  // b is an int (top-level const in ci is dropped)
auto c = cr;  // c is an int (cr is an alias for ci whose const is top-level)
auto d = &i;  // d is an int*(& of an int object is int*)
auto e = &ci; // e is const int*(& of a const object is low-level const)

const auto f = ci; // deduced type of ci is int; f has type const int

auto k = ci, &l = i;    // k is int; l is int&
auto &m = ci, *p = &ci; // m is a const int&;p is a pointer to const int
// error: type deduced from i is int; type deduced from &ci is const int
auto &n = i, *p2 = &ci;
```



### 2.5.3 decltype

和auto类似，让编辑器猜类型的, 和auto不同的是, decltype不会忽略顶层const信息

```cpp
const int ci = 0, &cj = ci;
decltype(ci) x = 0; // x has type const int
decltype(cj) y = x; // y has type const int& and is bound to x
decltype(cj) z;     // error: z is a reference and must be initialized

decltype((c)) xx = x; // 带括号的代表引用
```

## 2.6 写自己的类型

### 2.6.2 写自己的Header文件

使用

``` c++
#ifndef XXX
#define XXX
#include <string>
....
#endif
```

确保只加载一次