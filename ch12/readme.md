# 12 动态内存

了解程序的内存结构, 区分静态内存和动态内存. 

``` C++
const int constglobal = 100;    // 只读段
int global; // 读写段
int main(int argc, char const *argv[])
{
    static int localStatic; // 读写段
    int *t = new int[100]; // 堆
    int local = 0; // 用户栈
	
    delete t;
    return 0;
}

```

 C++支持动态内存，动态分配的对象的生存周期和定义的地方无关，程序显式销毁释放动态对象的正确释放很容易出错。C++提供了两个智能指针帮助程序员

## 12.1 动态内存与智能指针

动态内存使用问题

- 忘记释放内存：内存泄露
- 提早释放内存：引用非法内存指针

智能指针自动释放对象，`memory`头文件

- shared_ptr 多个指针指向一个对象
- unique_ptr 一对一
- weak_ptr 伴随类

#### 两种指针都有的操作

``` cpp
shared_ptr<T> sp;
unique_ptr<T> up;
p // 判断是否为空
*p
p->mem;
p.get(); // 返回p中的指针
swap(p, q);
```

### 12.1.1 shared_ptr类

``` C++
// 独有的操作
p.unique();//测试引用数是否为1
p.use_count();//可能很慢
```

#### 初始化

最安全的方法是调用标准库中的一个方法`make_shared`

``` cpp
make_shared<T> args
```

`make_shared`用其参数来构造给定类型的对象, 返回指向该对象的指针. 


``` cpp
shared_ptr<string> p4 = make_shared<string>(10, '9');
```

#### 拷贝和赋值

每个shared_ptr都会记录有多少个其他shared_ptr指向的对象。shared_ptr的计数器变为0，自动释放内存

``` cpp
auto r = make_shared<int>(42);
r = q;
// q计数器递增；r原来所指的对象自动销毁
```

### 使用动态内存

- 不知道需要多少对象 => 容器
- 不知道所需对象的准确类型 => 多态
- 多个对象之间共享数据 => 智能指针

C++都是“深”拷贝，所以当想要多个对象共享数据的时候，就要使用动态内存

### 12.1.2 直接管理内存

```cpp
string *ps1 = new string; //默认初始化
string *ps = new string(); // 值初始化
vector<int> *pv = vector<int>{0,1,2,3,4,5,6,7,8,9}; // list初始化

const int *p = new const int(1024);

// 内存耗尽
int *p1 = new int; // new throw std::bad_alloc
int *p2 = new (nothrow) int; // 返回一个空指针
```

释放内存, delete的指针必须是动态的或者是空指针

``` cpp
delete p;
```

空悬指针: delete之后, 内存是释放掉了, 但是指针还在那里指着.

#### 释放两次

可能有很多个指针指向动态内存, 当某一个指针释放原有的对象后，很难确保另一个指针p不会再次释放，总之直接管理内存很容易出现问题.

### 12.1.3 结合使用

使用new返回的指针初始化`shared_ptr`

``` cpp
shared_ptr<int> p2(new int(42));
shared_ptr<int> p2 = make_shared<int>(42);
shared_ptr<int> p2 = new int(42); // ERROR
// explicit 构造函数 必须显式调用
```

#### Note1不要混合使用普通指针和智能指针

``` C++
void process(shared_ptr<int> ptr) { ... }
int *x = new int(1024);
process(x); // error
process(shared_ptr<int>(x));
int j = *x; // GG 未定义 x已经悬空
```

#### Note2不要使用get初始化

注意：二次释放！

``` cpp
auto sp = make_shared<int>();
auto p = sp.get();
{
    shared_ptr<int>(p);
}
int foo = *sp; // 未定义
```

### 12.1.4 智能指针和异常

即使发生了异常，智能指针控制的内存也可以释放，内置指针就不行了

使用自己定义的操作, eg 网络连接

``` C++
shared_ptr<T> p(ptr, deleter);
```

### 12.1.5 unique_ptr

``` C++
unique_ptr<T>() u1;
unique_ptr<T>(T*) u1;
u = nullptr;  // 释放u指向的内存
u.release();	// 返回指针, 释放对指针的控制权 但是没有释放内存
u.reset(); 		// 释放指针指向的对象
u.reset(q); 		// q是内置指针
```



必须使用new的动态内存直接初始化, 不能复制或者赋值, 但是在函数返回中可以.

```cpp
unique_ptr<string> p1(new string("Stagosaurus"));
```

调用`release`或者`reset`将指针的所有权从一个`unique_ptr`到另一个

但是`release`不会释放内存!!

``` cpp
unique_ptr<string> p2(p1.release());
p2.reset(p3.release());
```

传入删除器

``` C++
unique_ptr<T,D> u(d);
unique_ptr<T,D> u(T*, d);
```



### 12.1.6 weak_ptr

弱指针不控制所指对象(没有重载`*`和`->`操作符), 是指向`shared_ptr`的观察类

``` C++
weak_ptr<T> w;
weak_ptr<T> w(sp);
w = p;
w.reset();
w.use_count();	// 引用数
w.expired();	// 过期没
w.lock();		// 如果没有过期返回一个指向w的对象的shared_ptr
```

#### 初始化

必须使用`shared_ptr`初始化

``` C++
auto p = make_shared<int>(42);
weak_ptr<int> wp(p); // 不改变计数
auto wp1 = p;
auto wp2 = wp1;

if(shared_ptr<int> np = wp.lock()) {
    // np & p 共享
}
```



## 12.2 动态数组

- new delete
- allocator

能不用就不用

### 12.2.1 new 和 数组

``` cpp
int *pia = new int[变量];
```

#### 注意

- 返回的是元素类型的指针，和数组没有关系，所以维度很关键
- 动态分配一个空数组是合法的
 ``` cpp
char arr[0]; // error
char *cp = new char[0];
 ```

#### 初始化

``` cpp
int *pia = new int[10];
int *pia2 = new int[10]();
int *pia = new int[10]{0,1,2,3,4,5}; // cpp11
```

#### 释放动态数组

``` cpp
delete [] p;
```

#### 智能指针和动态数组

``` cpp
unique_ptr<int []> up(new int[10]);
up.release();
```





# 其他

[循环引用](https://www.cnblogs.com/wxquare/p/4759020.html)

