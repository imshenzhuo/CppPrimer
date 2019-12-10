> This chapter focuses on the operators as defined in the language and applied to operands of built-in type.

## 4.1 基础

> An **expression** is composed of one or more **operands** and yields a **result** when it is evaluated.
> 表达式 = 运算符 + 运算对象 + 结果

### 4.1.1 基本概念

- 一元二元三元操作符 
- **操作符**的优先级和结合率
- 表达式里的类型转换
- 操作符重载 @计算万年历之间的天数
- 左值和右值

#### lvalue rvalue 

C语言中, 左值可以位于赋值语句的左侧, 右值不行.

- 当一个对象被用作右值的时候, 用的是对象在内存中的**值**
- 当一个对象被用作左值的时候, 用的是对象在内存中的**位置**

### 4.1.2 优先级和结合率

Because of precedence, the expression 3+4*5 is 23, not 35.

Because of associativity, the expression 20-15-3 is 2, not 8.

Associativity determines how to group operands with the same precedence.

### 4.1.3 执行顺序

``` cpp
int  i = f1() * f2();
```

函数的先后顺序是不能确定的，如果相互影响会产生bug，可以确定的操作只有四种

- &&
- ||
- ？：
- ，

## 4.2 算术操作符

``` cpp
int i = 1024;
int k = -i; // i is -1024
bool b = true;
bool b2 = -b; // b2 is true!
```

%的优先级和乘除是一样的

## 4.3 逻辑和关系操作符

由于关系操作符是**左联系**的

``` cpp
// oops! this condition compares k to the bool result of i < j
if (i < j < k) // true if k is greater than 1!
// ok: condition is true if i is smaller than j and j is smaller than k
if (i < j && j < k) { /* ...  */ }
```

`bool`的坑

``` cpp
if (val) { ... }  // val 非零执行
if (val == true) {}  // val 为1才执行
```

## 4.4 赋值操作符

>  If the types of the left and right operands differ, the right-hand operand is converted to the type of the left:

``` cpp
int k = 3.14; // 3
int i = {3.14}; // error cpp11 feature
```

## 4.5 ++ --

``` cpp
// ++的优先级要高于 *
*it++; // *(it++)
```

## 4.6 成员访问操作符

对象：xxx.member()
指针：xxx->member()
(*xxx).member

## 4.7 条件操作

### 内嵌

``` cpp
string finalgrade = (grade > 90) ? "high pass"
                          : (grade < 60) ? "fail" : "pass";
```

三元操作符优先级很低，记得加上括号

``` C++
cout << ((grade < 60) ? "fail" : "pass"); // correct
cout << (grade < 60) ? "fail" : "pass"; // cout 1 or 0
cout << grade < 60 ? "fail" : "pass"; // error try to cmp cout and 60
```

条件操作符是右联的，cin cout是左链接的

## 4.8 bit 操作

## 4.9 sizeof

返回一个`size_t`的常量表达式, 并且表达式不参与实际运算

``` cpp
sizeof(type);
sizeof expr;
sizeof (expr);
```

`sizeof(arr)`返回整个在stack中数组的字节大小，sizeof 动态分配就不是了

## 4.10 逗号

规定了求值顺序, 从左到右

## 4.11 类型转换

``` cpp
int ival = 3.54 + 1;
```

算术类型的转换是为了保留精度，首先int类型(等号右边的`1`)转换为浮点型，然后相加得到一个浮点型结果，最后转换为初始化的类型`4`

隐式类型转换发生

- 条件语句中, 非bool转换bool
- 初始化和赋值, 右侧转换为左侧类型
- 算术运算关系运算转换为一种类型

### 4.11.1 算术转换

原则：不丢失信息，向上转型

int + unsigned 的时候要注意

### 4.11.2 其他隐式转换

``` c++
int ia[10];
// ia转换成指向数组第一个元素的指针
int *ip = ia;
```

### 4.11.3 显式转换

``` C++
cast-name<type>(expr)
```

#### static_cast

只要不包含low-level const的类型, 都可以`static_cast` 

``` C++
int i,j;
double slope = static_cast<double>(j) / i;
```

编译器无法自动执行的类型转换

``` C++
double d = 3.14;
void *p = &d;
double *dp = static_cast<double*>(p);
```

#### dynamic_cast

Chapter 19 运行时类型识别

#### const_cast

**只能**改变运算对象的**底层**`const`

``` C++
int i = 99;
const int *p = &i;
// *p = -99;// error
int *newp = const_cast<int *>(p);
*newp = -99;
```

#### reinterpret_cast

要对机器很懂

#### 旧制的强制转换

四合一

``` C
(type) expr;
```

