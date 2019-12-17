> The smart pointers namely the std::unique_ptr and std::shared_ptr are realizations of RAII ( Resource Allocation Is Initialization ) concept.
> RAII是一种技术，程序员不必显式地执行和撤消对资源的一个或一组操作。
## shared_ptr

### 类介绍
`shared_ptr`是一个模板类, 内部有两个指针, 一个是指向操作的动态内存, 一个指向控制块(use_count & function等)
所以`shared_ptr`的大小是两个指针大小, 并且`shared_ptr`引用数的改变都是原子操作, 线程安全, 当引用数为零, 动态内存释放
`shared_ptr`没有过多的限制, 可以赋值可以拷贝可以移动赋值移动构造(移动过程中什么都不变)

不只是使用方便, 程序运行时异常如果没有捕获, 智能指针可以释放, new的就GG了

### 使用
#### 初始化

``` C++
shared_ptr<vector<int>> p = make_shared<vector<int>>(); // 1. make_shared
shared_ptr<int> p(new int(1024));   // 2. new pointer
shared_ptr<int> sPtr(new int(11), deleterFunc); // 3. with deleter 自定义删除器的时候不能使用make_shared
// 4. 从unique_ptr初始化

p.use_count(); //可能会比较慢, 推荐使用weak_ptr
```
实验证明`make_shared`要比`new`构造`shared_ptr`块14%左右

## unique_ptr

### 类介绍
`unique_ptr`同样是一个模板类, 不同的是, `unique_ptr`不能复制和拷贝(可以移动), 独占, 引用数永远是1(如果有的话)
`unique_ptr`的大小和指针有一个大(自定义删除函数可以增加)
关于deleter的信息都是自己类的成员(不是指针)

### 使用
``` C++
std::unique_ptr<int, decltype(deleterFunc1)> uPtrInt1(nullptr, deleterFunc1);
uPtrInt1.reset(new int{ 21 });
uPtrInt1.reset(); // 释放
uPtrInt1 = nullptr; // 释放
```

### 用途
`unique_ptr`主要有两个用途
1. 在工厂方法中返回派生类对象
2. 实现 PImpl(Pointer to Implementation)

#### 工厂设计模式
1. 有一个基类和多个派生类
2. 有一个返回由heap创建的基类对象的工厂方法
3. 该工厂方法有多个参数, 第一个用来确定派生类, 第二个用做方法内的构造函数
4. 工厂方法内部使用switch套件或者if-else梯子来构造派生类并且返回基类

``` C++
template<typename... Ts>
std::unique_ptr<Beverage> make_drink(TypeOfDrink selection, Ts&&... ts)   // function named according to the std::make_unique. std::make_shared etc convention.
{
    // using switch-case ladder is preferable especially when we have more than two derived classes.
    if (selection == TypeOfDrink::Coffee)
        return std::unique_ptr<Coffee>(new Coffee(std::forward<Ts>(ts)...));
    else
        return std::unique_ptr<Tea>(new Tea(std::forward<Ts>(ts)...));
}
```
#### PImpl
Pointer to Implementation主要有两个原因
1. 减少编译器依赖=>更少的build时间
2. 隐藏数据结构

``` C++
// without PIml
//Car.h
#include <string>
#include <map>
class Car
{
public:
    void move(int src, int dest) const;
    void addFeature(std::string, std::string);

private:
    int numOfWheels;
    std::string makeOfCar;
    std::map<std::string, std::string> features;
};

//Car.cpp
#include "Car.h"
#include <iostream>
void Car::move(int src, int dest) const
{
    std::cout << "Moved from " << src << " to " << dest << '\n';
}
void Car::addFeature(std::string key, std::string val)
{
    features[key] = val;
}
```
假设`car.h`在项目中很多文件都被包含, 但是没有真的用到`map`, 但是既然有include的声明, 就会添加`<map>`
以下例子是使用new的方法来解决解决这个问题, 现在推荐使用`unique_ptr`
``` C++
//Car.h
#include <string>
class Car
{
public :
    Car();
    void move(int src, int dest) const;
    void addFeature(std::string, std::string);
    ~Car();
private:
    struct CarImpl;
    CarImpl* impl;
};


//Car.cpp
#include "Car.h"
#include <iostream>
#include <map>
struct Car::CarImpl
{
    int numOfWheels;
    std::string makeOfCar;
    std::map<std::string, std::string> features;
};

Car::Car(): impl(new CarImpl()) {}

Car::~Car() { delete impl;}

void Car::move(int src, int dest) const
{
    std::cout << "Moved from " << src << " to " << dest << '\n';
}

void Car::addFeature(std::string key, std::string val)
{
    this->impl->features[key] = val;
}
```
通过指针实现达到了减少编译时间的效果, 效果主要取决于
1. 包含`car.h`的文件数
2. map文件的大小

## weak_ptr

### 类介绍

`shared_ptr`的伴随类, 用来观察`shared_ptr`, 和`shared_ptr`成员相同, 有相同的大小

### 使用
``` C++
std::shared_ptr<int> sp1 = std::make_shared<int>(23);
std::weak_ptr<int> wpr1(sp1);
// Not recommended, but possible.
wpr = sp1;
```

为了避免竞争条件, 有两种方法同时可以检测并创建`shared_ptr`
1. using api `shared_ptr<int> sp2 = wpr.lock();`
2. 使用`shared_ptr`构造器  `shared_ptr<int> sp2(wpr);`

``` C++
sp2 = wpr1.lock();
if (sp2 == nullptr){
    std::cout << "Weak pointer no longer pointing to valid shared memory location\n";
}


// Using the shared pointer constructor
std::shared_ptr<int> sp3 = std::make_shared<int>(23);
std::weak_ptr<int> wpr3{ sp3 };

// auto sp4{ wpr3 };  auto creates new weak pointer from existing weak pointer
std::shared_ptr<int> sp4{ wpr3 };
if (sp4 != nullptr) {
    cout << "Shared ptr still valid\n";
}
```

