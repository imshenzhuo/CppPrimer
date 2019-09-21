# OOP 面向对象程序设计

主要介绍面向对象的**继承**和**动态绑定**

OOP适用于一些*相互关联但是有细微差距*的概念。

## 15.1 OOP 概述

- 数据抽象：将类的接口和实现分离
- 继承：定义相似的类型
- 动态绑定：忽略相似的类型，以一样的方式去使用

### 继承

- 基类
- 派生类
  - 派生类列表
- 虚函数

### 动态绑定

在`C++`语言中，当我们使用基类的引用调用一个虚函数时将发生动态绑定（运行时绑定）



## 15.2 定义基类和派生类

### 15.2.1 定义基类

``` cpp
class Quote {
public:
    Quote() = default;  // = default see § 7.1.4 (p. 264)
    Quote(const std::string &book, double sales_price):
                     bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    // returns the total sales price for the specified number of items
    // derived classes will override and apply different discount algorithms
    virtual double net_price(std::size_t n) const
               { return n * price; }
    virtual ~Quote() = default; // dynamic binding for the destructor
private:
    std::string bookNo; // ISBN number of this item
protected:
    double price = 0.0; // normal, undiscounted price
};
```

注意到

- 有的函数添加了`virtual`关键字，保留了函数体
- 析构函数也添加了 基类(root那种)通常定义一个虚析构函数，咱也不知道为什么？ -> 15.7.1
- `protected`访问修饰符

#### 成员函数和继承

任何构造函数之外的非静态函数都可以是虚函数；`virtual`只能出现在类内的函数声明。

#### 访问控制和继承

派生类并不能访问基类的全部，只能访问`public`部分

引入`protected`访问控制：基类的派生类可以访问，但是其他类不能访问

### 15.2.2 定义派生类

``` cpp
class Bulk_quote : public Quote { // Bulk_quote inherits from Quote
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0; // minimum purchase for the discount to apply
    double discount = 0.0;   // fractional discount to apply
};
```

值得注意的是，`C++`中的继承还有三种类型 `public` `private` `protected`，用来控制从基类继承而来的成员对派生类是否可见

#### 派生类向基类的类型转换

派生类自定义的部分和基类的部分不一定连续存储，存在隐式的转换

``` cpp
Quote item;        //  object of base type
Bulk_quote bulk;   //  object of derived type
Quote *p = &item;  //  p points to a Quote object
p = &bulk;         //  p points to the Quote part of bulk
Quote &r = bulk;   //  r bound to the Quote part of bulk
```

派生类使用基类的**构造函数**初始化派生类的基类部分

``` cpp
Bulk_quote(const std::string& book, double p,
           std::size_t qty, double disc) :
           Quote(book, p), min_qty(qty), discount(disc) { }
    // as before
};
```

#### 继承和静态成员

静态成员只定义一次，整个继承体系都是如此。

#### 禁止继承 C++11

``` cpp
class NoDerived final {
  /** */  
};
```

### 15.2.3 类型转换和继承

#### 静态类型和动态类型



## 15.3 虚函数

派生类必须要实现虚函数。一般函数可以只声明不定义，虚函数不行，因为编译器编译的时候压根不知道会不会用到，但是一般函数是知道的。

动态绑定只有当通过**指针或者引用**调用**虚函数**时才会发生

#### override&final 说明符

只有引用调用虚函数才会发生动态绑定，如果我们错误(只是名字相同)覆盖了虚函数的方法，就不会发生动态绑定，而且编译器不会报错，所以`C++11`提供了机制确保动态绑定`override` ，编译器确保只有虚函数才可以覆盖。

``` cpp
struct Base {
    virtual void f1(int) const;
};
struct De : B {
    void f1(int) const override;
}
```

类似的，`final`规定了不能覆盖



## 15.4 抽象基类

``` cpp
class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 1.0;
};
```

含有(或者没有覆盖直接继承)`纯虚函数`的类是抽象基类。

纯虚函数 = `（虚函数 = 0）`

尽管抽象基类不能定义这个类的对象，但是这不影响该类有构造函数



## 15.5 访问控制与继承

一般说的访问控制有两种：派生类的成员函数访问和派生类直接访问，下表是派生类访问基类成员的访问控制。 [code](./test15_5.cpp)

| 继承方式\基类本身访问修饰符 |        public        |        protected         |    private     |
| :-------------------------: | :------------------: | :----------------------: | :------------: |
|           public            |  派生类可以直接访问  | 派生类只能在成员函数访问 | 派生类不能访问 |
|           private           | 派生类在成员函数访问 | 派生类只能在成员函数访问 | 派生类不能访问 |

上表看出该不能访问还是不能访问，变得只有public，私有继承只能在成员函数中访问了。

如果是public继承，那么派生对象可以当成基类对象使用

#### protected

protected + 友元

派生类的成员或者友元只能通过**派生类对象**来访问基类的`protected`成员

``` cpp
class Base {
protected:
    int prot_mem;     // protected member
};
class Sneaky : public Base  {
    friend void clobber(Sneaky&);  // can access Sneaky::prot_mem
    friend void clobber(Base&);    // can't access Base::prot_mem
    int j;                          // j is private by default
};
// ok: clobber can access the private and protected members in Sneaky objects
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
// error: clobber can't access the protected members in Base
void clobber(Base &b) { b.prot_mem = 0; }
```

#### 派生访问说明符：公有、私有 和 protected 继承

`private`继承和`public`继承不影响派生类的访问权限，影响的是从基类继承来的函数成员的访问权限

``` cpp
class Base {
public:
    void pub_mem();   // public member
protected:
    int prot_mem;     // protected member
private:
    char priv_mem;    // private member
};
struct Pub_Derv : public Base {
    // ok: derived classes can access protected members
    int f() { return prot_mem; }
    // error: private members are inaccessible to derived classes
    char g() { return priv_mem; }
};
struct Priv_Derv : private Base {
    // private derivation doesn't affect access in the derived class
    int f1() const { return prot_mem; }
};

Pub_Derv d1;   //  members inherited from Base are public
Priv_Derv d2;  //  members inherited from Base are private
d1.pub_mem();  //  ok: pub_mem is public in the derived class
// 因为是private继承，所以基类的函数成员的访问权限修改，全部变为private，自然不能调用
d2.pub_mem();  //  error: pub_mem is private in the derived class
```

#### 友元与继承

友元是不能继承的

#### 改变个别成员的可访问性

using声明

#### 默认的继承保护级别

``` cpp
class Base { /* ...   */ };
struct D1 : Base { /* ...   */ };   // public inheritance by default
class D2 : Base { /* ...   */ };    // private inheritance by default
```



## 15.6 继承中的类作用域

#### 编译时名字查找

``` cpp
Bulk_quote bulk;
Bulk_quote *bulkP = &bulk; //  static and dynamic types are the same
Quote *itemP = &bulk;      //  static and dynamic types differ
bulkP->discount_policy();  //  ok: bulkP has type Bulk_quote*
itemP->discount_policy();  //  error: itemP has type Quote*
```

#### 名字冲突与继承

派生类的成员将屏蔽基类中的成员，如果要访问需要显式指定。

#### 名字查找先于类型检查

先找名字，再对参数

``` cpp
struct Base {
    int memfcn();
};
struct Derived : Base {
    int memfcn(int);   // hides memfcn in the base
};
Derived d; Base b;
b.memfcn();       //  calls Base::memfcn
d.memfcn(10);     //  calls Derived::memfcn
d.memfcn();       //  error: memfcn with no arguments is hidden
d.Base::memfcn(); //  ok: calls Base::memfcn
```



## 15.7 构造函数和拷贝控制

### 15.7.1 虚析构函数

基类(root)定义虚析构函数的意义在于，派生类也都继承析构函数，如果我们要删除基类指针指向的派生类对象时，会发生动态绑定，执行真正要执行的析构动作；幸运的是，只需要在基类写就好了。

涉及到移动复制，先略过



## 15.8 容器与继承

习题`15.28` `15.29`两个程序说明

### 15.8.1 编写Basket类

待补充

## 15.9 文本程序再探

待补充