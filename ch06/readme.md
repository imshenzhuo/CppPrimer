函数，一个命了名的代码块

## 6.1 函数基础

#### 实参argument和形参parameter

函数内定义的参数是形参，调用时候传递的参数是实参，用实参初始化形参。

函数不能返回数组或者函数，但是可以返回数组或函数的指针



## 6.2 参数传递

就是形参的初始化的过程

```cpp
// 引用大法好
void reset1(int *ip){
	*ip = 0;
}
void reset2(int &j){
    j = 0;
}
int i = 33;
reset1(&i);
reset2(i);
```

### 6.2.3 const 形参和实参

实际上就是带有const内容初始化的重演，初始化时会忽略top-level的const

``` cpp
void f(const int i) {} // 传入const或者un const 只不过f函数只能读
void f(int i) {} // 重复定义
```

const能用就用，不然会有想不到的麻烦

### 6.2.4 数组形参

数组两个特性

- 不能拷贝
- 使用时候通常转换为指针

#### 数组引用形参

``` cpp
void print(int (&arr)[10] );
```

#### 二维数组

```cpp
void print(int matrix[][10], int rowSize);
void print(int (* matrix)[10]. int rowSize);
```



### 6.2.5 main 处理命令行选项

## 6.3  返回类型和return语句

### 6.3.2 返回左值

```cpp
char &get_Val(){}
...
get_val() = 'A';

```



### 6.3.3 返回数组指针

``` cpp
int odd[] = {
	1,3,5,7,9
};
int even[] = {
	2,3,4,8,10
};

int (*func(int i))[5] {
	return (i % 2) ? &odd : &even;
}

auto func1(int i) -> int (*)[5] {
	return ((i % 2) ? &odd : &even);
}

decltype(odd) *func2(int i) {
	return ((i % 2) ? &odd : &even);
}
```

## 6.4 函数重载 overload

####  重载和const形参

※ Top-level low-level

一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来

``` C++
Record lookup(Phone);
Record lookup(const Phone);
Record lookup(Phone*);
Record lookup(Phone *const);
```

一个带底层const的形参可以和另一个没有带底层const的形参区分开

``` C++
Record lookup(Account&);
Record lookup(const Account&);

Record lookup(Account*);
Record lookup(const Account*);
```



### 6.4.1 重载和作用域

函数声明当然不能放到局部作用域啊，这样做有屏蔽的作用，除非有特殊用途

### 6.5 语言特性

### 6.5.1 默认实参

可多次声明

``` cpp
string screen(sz, sz, char = ' ');
string screen (sz, sz, char = '*'); // error
string screen (sz = 24, sz = 80, char); 
```

### 6.5.2 内联函数&constexpr函数

向编译器请求在该函数调用处展开, 省去函数开销, 不过编译器可以忽略请求.

- 函数返回类型和所有形参类型都是字面值类型
- 函数体只能有一个`return`语句
- 隐式内联

内联函数和constexpr函数通常定义在头文件中

### 6.5.3 调试帮助

#### assert

``` C
assert(expr);
```

如果表达式为真, 什么都不做, 如果表达式假, 输出信息停止程序.

assert行为依赖于`NDEBUG`预处理变量, 如果定义assert就无效, 所以关闭`assert`选项的方法就是定义`NDEBUG`

``` bash
$CC -D NDUBUG main.c
```