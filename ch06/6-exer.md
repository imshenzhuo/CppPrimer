# 1

- 形参是定义在函数参数的变量，
- 实参是调用时候的参数，实参初始化形参

# 2

a. 错误  string不能强转为int

b.  error: ISO C++ forbids declaration of ‘f2’ with no type [-fpermissive]
 f2(int i) {

c. 错误 形参名字不能一样

d. 要有花括号

# 3

# 4

# 5

# 7

> 编写一个函数，第一次被调用返回0，以后返回1

``` cpp
int f(){
    static int i = 0;
    if (i == 0)	++i;
    return i;
}
```

# 8&9

``` cpp
// chapter6.h
int getWord(int);
```

``` cpp
// exer6_8.cpp
#include <iostream>
#include "Chapter6.h"
using namespace std;


int main() {
	cout << getWord(3882) << endl;
}
```

``` cpp
// exer6_9.cpp
#include "Chapter6.h"

int getWord(int i) {
	return i % 13;
}
```

``` bash
$ g++ exer6_8.cpp -c # 生成exer6_8.o
$ g++ exer6_9.cpp -c # 生成exer6_9.o
$ g++ *.o -o main
```







## 18

``` cpp
bool compare(matrix&, matrix&);
vector<int>::iterator change_val(int, vector<int>::iterator);
```

## 6.39

a. illegal ignore top-level const

b. illegal 

c.legal

## 6.40

a. illegal

b. 如果一个参数有默认值，后面的也要有默认值

## 6.41

a.error

b.正确

c.正确 非本义

## 6.54

````cpp
int f(int, int);
vector<int (*f)(int, int)> v;
````

## 6.55

```cpp
int add(int a, int b){
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
```

