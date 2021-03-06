# 1

> What is a virtual member?

虚成员就是虚函数。基类要派生类定义自己的版本，从而实现动态绑定。

# 2

> How does the protected access specifier differ from private?

`private`修饰的成员只有自己可见

`protected`修饰的成员自己可见，派生类可见

# 3 [exer15_3.cpp](./exer15_3.cpp)

> Define your own versions of the Quote class and the print_total function

# 4

> hich of the following declarations, if any, are incorrect?
> Explain why.
>
> ``` cpp
> class Base { ... };
> (a) class Derived : public Derived { ... };
> (b) class Derived : private Base { ... };
> (c) class Derived : public Base;
> ```

a. 错误。自己继承自己，没听说过
b. 正确
c. 错误　派生列表不能出现在这里

# 5&6 [exer15_5.cpp](./exer15_5.cpp)

> Define your own version of the Bulk_quote class

# 7 [exer15_7.cpp](./exer15_7.cpp)

> Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.

# 8

> Define static type and dynamic type

静态类型是在编译时可以确定的，动态类型是在运行时才确定的。
同一个对象在某个时刻的静态类型和动态类型可能是不一样的。

# 9

> When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.

``` cpp
Base *b = &derived;
```

# 11 [exer15_11.cpp](./exer15_11.cpp)

> Add a virtual `debug` function to your `Quote` class hierarchy that displays the data members of the respective classes.

# 12

> Is it ever useful to declare a member function as both `override` and `final`? Why or why not?

`override`是确保当前写的函数是覆盖基类的虚函数的；而`final`是确保当前类的派生类不要覆盖。可是如果一个函数可以是final的，那不就不用override确定了吗？难道final可以修饰非虚函数？

# 13

> Given the following classes, explain each print function:
>
> ``` cpp
> class base {
> public:
>    string name() { return basename; }
>    virtual void print(ostream &os) { os << basename; }
> private:
>    string basename;
> };
> class derived : public base {
> public:
>    void print(ostream &os) { print(os); os << " " << i; }
> private:
>    int i;
> };
> ```
>
> If there is a problem in this code, how would you fix it?

派生类的意思应该是指定使用基类的虚函数实现，但是不显式的话会递归调用

``` cpp
 void print(ostream &os) { base::print(os); os << " " << i; }
```

# 14

> Given the classes from the previous exercise and the following objects, determine which function is called at run time:
>
> ``` cpp
> base bobj;     base *bp1 = &bobj;   base &br1 = bobj;
> derived dobj;  base *bp2 = &dobj;   base &br2 = dobj;
> ```

只有基类的指针或者引用 + 虚函数才会发生动态绑定

(a) bobj.print(); // 基类的函数
(b) dobj.print(); // 派生类的函数
(c) bp1->name(); // 基类
(d) bp2->name(); // 基类
(e) br1.print();  // 基类
(f) br2.print();  // 派生类



# 15 [exer15_15.cpp](./exer15_15.cpp)

> Define your own versions of Disc_quote and Bulk_quote.



# 17  [exer15_17.cpp](./exer15_17.cpp)

> Try to define an object of type Disc_quote and see what errors you get from the compiler.

``` cpp
exer15_17.cpp: In function ‘int main(int, const char**)’:
exer15_17.cpp:47:16: error: cannot declare variable ‘dq’ to be of abstract type ‘Disc_quote’
     Disc_quote dq(s, 32.1, 30, 0.9);
                ^
```

# 18 [exer15_18.cpp](./exer15_18.cpp)

> Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed
>
> ``` cpp
> Base *p = &d1;  //  d1 has type Pub_Derv  √
> p = &d2;        //  d2 has type Priv_Derv
> p = &d3;        //  d3 has type Prot_Derv
> p = &dd1;       //  dd1 has type Derived_from_Public √
> p = &dd2;       //  dd2 has type Derived_from_Private
> p = &dd3;       //  dd3 has type Derived_from_Protected
> ```

**仅当D从B公开继承时，用户代码才可以使用派生到基础的转换**。如果D使用protected或private从B继承，则用户代码可能不使用转换。

# 19 [exer_15_19.cpp](./exer_15_19.cpp)

> Assume that each of the classes from page 612 and page 613 has a member function of the form:
>
> ``` cpp
> void memfcn(Base &b) { b = *this; }
> ```
>

类型转换

直接继承的可以类型转换为基类，无论是什么类型的继承。

间接继承的只要继承路线没有`private`就可以转换

# 24

> What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?

基类需要定义一个虚析构函数



# 28 [exer15_28.cpp](./exer15_28.cpp)

> Define a vector to hold Quote objects but put Bulk_quote objects into that vector. Compute the total net_price of all the elements in the vector.



# 29 [exer15_29.cpp](./exer15_29.cpp)

> Repeat your program, but this time store shared_ptrs to objects of type Quote. Explain any discrepancy in the sum generated by the this version and the previous program. If there is no discrepancy, explain why there isn’t one.

派生类的指针可以转换为基类的指针，反过来的不可以的





# 问题

- 12
- 19 不懂