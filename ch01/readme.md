# 开始

- 类型 变量 表达式 语句 函数
- 如何编译&运行程序

### main

main函数是怎样被系统调用的？
return 0是指正常，其他的代表错误代码
每次执行完 `echo $?` 查看

### iostream library
每个程序关的执行联了4个io对象

- cin 
- cout 
- cerr 
- clog

### 写入数据

`std::out<<"Enter two numbers:"<<std::endl;`

- 这是一个表达式
- 表达式 = 运算对象 + 运算符

#### 输入/输出运算符

`<<`是输出运算符, 类似于四则运算, 输出运算符有两个运算对象, 左侧必须是一个`欧stream`对象, 右侧是要打印的值, 返回值就是写入打印值的`ostream`对象

所以上个表达式就相对于

``` c++
(std::out << "Enter two numbers:") << std::endl;
```

输出操作符同理.

### 其他

类类型: `class type` 

设计一个对象时, 首先定义如何使用, 有了接口, 然后在写实现细节.