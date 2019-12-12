类的基本思想

- 数据抽象：接口+实现分离
- 封装：使用户只能访问接口 ，隐藏其他部分

## 7.1 定义抽象数据类型

#### 先确定好接口，设计Sales_data类

``` cpp
// bookStore.cpp
Sales_data total;         // variable to hold the running sum
if (read(cin, total))  {  // read the first transaction
    Sales_data trans;     // variable to hold data for the next transaction
    while(read(cin, trans)) {      //  read the remaining transactions
        if (total.isbn() == trans.isbn())   // check the isbns
            total.combine(trans);  // update the running total
        else {
            print(cout, total) << endl;  // print the results
            total = trans;               // process the next book
        }
    }
    print(cout, total) << endl;          // print the last transaction
} else {                                 // there was no input
    cerr << "No data?!" << endl;         // notify the user
}
```



#### 定义类

成员函数的声明必须在内部，但是定义不一定在内部

``` cpp
// Sales_data.hpp
struct Sales_data {
    // new members: operations on Sales_data objects
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // data members are unchanged from § 2.6.1 (p. 72)
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
```



#### 定义类的成员函数

成员函数的声明必须在类的内部，但是成员函数体可以定义在类外

``` cpp
std::string isbn() const { return bookNo; }
```

`isbn`是怎样获得`bookNo`所依赖的对象的？
`total.isbn()`的调用，隐式地将`this`指针传给了`isbn`，即

``` cpp
Sales_data::isbn(&total);
```

然后

``` cpp
return this->bookNo;
```

#### 成员函数中const的作用

`const`的作用是修改`this`指针的类型

没有`const` 时，`this`指针的类型是 `Sales_data *const `
有`const`时，`this`指针的类型是`const Sales_data *const`

也就是说，有了`const`，该函数就不能修改成员数据，该函数被叫做**常量成员函数**

> 猜想：可以根据const重载吗？ 不可以 忽略顶层const
>
> 额…… 可以

#### 类作用域

注意到，即使成员变量声明在后，成员函数也能访问的到，编译器首先扫描成员变量，然后扫描成员函数。无需在意次序。

`Sales_data::`就是类的作用域

#### 外部定义成员函数

``` cpp
double Sales_data::avg_price() const {
	return units_sold ? revenue/units_sould : 0;
}
```

### 7.1.4 构造函数 basic

- 函数名字和类名相同
- 没有返回值
- 不能是const

如果有其他方式的构造函数, 编译器不会自动生成默认构造函数.

``` C++
// 既需要默认构造函数又需要其他构造函数 C++11
Sales_data() = default;
```



``` cpp
// 构造函数声明
Sales_data(const string &s) : bookNo(s) {	}
Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
Sales_data(istream &is);
```



## 7.2 封装：访问控制

#### struct vs class

唯一区别：struct在第一个访问说明符之前是public的，class相反是private的

### 7.2.1 友元

友元：你可以访问我！

加上封装后，原来的`read`等函数不能访问，编译失败，这不是我本义，可以补救！友元

``` cpp
// 添加函数声明  仅仅是访问不是实际上的声明
class Sales_data {
friend Sales_data add (const Sales_data&, const Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
...
};
```

友元告诉类，类允许访问所有成员



## 7.3 类的其他特性

### 7.3.1 再看类成员

通过定义相关类`Screen`和`Window_mgr`说明

``` C++
class Screen {
    public:
    	typedef std::string::size_type pos;
    private:
    	pos cursor = 0;
    	pos height = 0, width = 0;
    	std::string contents;
};
```

**类型别名也有访问权限**

#### 成员函数内联

1. 成员函数定义在类定义内部隐式内联
2. 成员函数在类声明或者外部定义时候显式`inline`

内联函数应该和相应的类定义在同一个头文件中

#### 可变数据成员

`mutable`修饰的变量永远不是`const`

``` cpp
// 无视 const 函数
mutable size_t access_ctr;
```

#### 基于const的重载

函数重载可以区分底层`const`, 所以当可以根据类成员函数是否是`const`(函数的隐式参数)来重载

``` C++
class Screen{
public:
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
};
```

很多代码都是这样, `display`包装`do_display`

- 随着规模的发展, `display`可能变得越来越复杂
- 在开发过程可以在`do_display`增加调试信息, 一处修改处处生效
- 由于内联并且不会增加函数开销

### 7.3.3 类类型

``` c++
class Screen;
```

不完全类型：声明之后，定义之前

不完全类型的使用

1. 定义指向该类的指针和引用
2. 声明以不完全类型作为形参或者返回值的函数

### 7.3.3 再看友元

``` cpp
class Screen{
    friend class Window_mgr;  
    friend void Window_mgr::clear(ScreenIndex);
};
```

`Window_mgr`是`Screen`的朋友，可以访问Screen的所有成员，但是朋友的朋友，不是朋友

必须在类的外部提供相应的声明从而使得函数可见

``` C++
struct x{
    friend void f() { /**/ }
    X() { f(); } // error f没有被声明
    void g();
    void h();
};
// 外部
void X::g() { return f(); } // error
void f();		// 声明定义在X的函数
void X::h() {return f();}	//正确

```



## 7.4 类的作用域

作用域内就是家，作用域外还要显示声明自己是哪儿的

## 7.5 再看构造函数

### 7.5.1 构造函数初始化列表

构造函数中的冒号是让成员变量初始化, 而函数体内部是定义后赋值

## 7.6 类的静态成员

声明：静态成员没有this指针，也就没有const限制（const是限制this指针的）

访问：类作用域或者类的对象

定义：不能重复使用static

初始化：必须在类外部初始化

区别：静态数据成员可以是不完全类型、



