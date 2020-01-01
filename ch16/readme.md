# 模板与泛型编程

模板是创建类或者函数的蓝本,比如`vector`类型或者`find`函数

与OOP多态不同,蓝本转为特定的类发生在编译时期.

## 16.1 定义模板

起因,函数体完全一样,却要因为类型不同编写重复性的函数体.

### 16.1.1 函数模板

``` cpp
template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```

#### 实例化**函数**模板

``` cpp
cout << compare(1, 0) << endl;       // T is int
```

当调用一个函数模板的时候, 编译器根据参数推断模板实参(就是上面的`T`)类型, 生成多个模板的实例

所以实际上相当于和编译器说好一个协议,协议就是模板定义的格式,程序员从原来的每个函数都要编写,到现在只需要编写一个模板,重复的工作交给编译器去做.

***

函数模板里面的模板参数有两种

- 类型参数
- 非类型参数

#### 模板中的类型参数

上面代码中模板的参数就是类型参数,该参数`T`代表一个类型,所以在前面必须要加 `class` 或者 `typename`
在模板类型参数中, 两者没有什么不同

#### 模板中的非类型参数

还有一种模板的参数叫非类型参数, 也就是说模板里面的参数代表的不是类型而是一个值, 比如指定数组大小,但是必须是**常量表达式** 

``` cpp
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}
```

函数调用以及实际上

``` cpp
compare("hi", "mom")
int compare(const char (&p1)[3], const char (&p2)[4])    
```

注意:此处的参数是`const`引用类型,既可以避免大对象的拷贝,也可以保证用于不能拷贝的类型

#### 模板编译

函数模板和类模板成员函数的定义通常放在头文件中.

模板在实例化的时候才会生成对应的代码.

> Q:模板使用不就是实例化吗?
>
> A: 
>
> ``` cpp
> template <typename T> class Stack{ };
> void f1(Stack<char>);
> ```
>

### 16.1.2 类模板

> 生成类的蓝图

与函数模板不同的是,编译器**不能推断**类模板的参数类型,所以就会想`vector<int>`一样,专门写明类型信息

#### 定义类模板

> 以之前`StrBlob`为例,从针对`String`类型泛化到`T`型, 该类的目的在于多个对象共享一块数据

``` cpp
template <typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // constructors
    Blob();
    Blob(std::initializer_list<T> il);
    // number of elements in the Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const T &t) {data->push_back(t);}
    // move version; see § 13.6.3 (p. 548)
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    // element access
    T& back();
    T& operator[](size_type i); // defined in § 14.5 (p. 566)
private:
    std::shared_ptr<std::vector<T>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;
};
```

注意到

- 格式和函数模板类似
- 第四行的重命名要显式 `typename`

#### 实例化模板

必须提供元素类型, 不然编译器没法整

``` cpp
// these definitions instantiate two distinct Blob types
Blob<string> names; // Blob that holds strings
Blob<double> prices;// different element type
```

实例化出两个不同的类, 两者互不相干.

#### 类模板的函数成员

**注意**

 - `Blob<T>`才是类型名
 - `Blob`是模板名

在类外**定义函数**和普通成员函数定义有所不同

``` cpp
template <typename T>
ret-type Blob<T>::member-name(parm-list)
```

1. 加上模板声明(不同的类生成不同的函数)
2. 作用域变成 `Blob<T>` (类名嘛!)

#### 类模板的构造函数

``` cpp
template <typename T> 
Blob<T>::Blob():data(std::make_shared<std::vector<T>>()) {}
```

也没有什么不同的地方

#### 类模板成员函数实例化

成员函数只有使用时才会被实例化

#### 类模板作用域内的简化

类模板内, 不需要`A<T>`

``` C++
template <typename T>
class A{
  A& operator++();  
};
```

类模板外的定义, 不需要`A<T>`

``` C++
template <typename T>
A<T> A<T>::operator++(int) {
    A ret = *this;
    ++*this;
    return ret;
}
```

在类模板的作用域内,可以直接使用模板名而不用指明类名(即指明实参).

#### 类模板和友元

##### 一对一友好

> 类模板与另一个模板建立对应实例的友元

假设对于`Blob<int>`只想要`BlobPtr<int>`做友元关系, 那么

``` cpp
template <typename T> class Blob {
    // ...
    friend class BlobPtr<T>;
    // ...
}
```

只有类型对的上, 才是友元关系

##### 通用和特定的模板友好

``` cpp
// forward declaration necessary to befriend a specific instantiation of a template
template <typename T> class Pal;
class C {  //  C is an ordinary, nontemplate class
    friend class Pal<C>;  // Pal instantiated with class C is a friend to C
    // all instances of Pal2 are friends to C;
    // no forward declaration required when we befriend all instantiations
    template <typename T> friend class Pal2;
};
template <typename T> class C2 { // C2 is itself a class template
    // each instantiation of C2 has the same instance of Pal as a friend
    friend class Pal<T>;  // a template declaration for Pal must be in scope
    // all instances of Pal2 are friends of each instance of C2, prior declaration needed
    template <typename X> friend class Pal2;
    // Pal3 is a nontemplate class that is a friend of every instance of C2
    friend class Pal3;    // prior declaration for Pal3 not needed
};
```

除了一对一还有一对多, 多对多的情况, 总之区分模板名和类名就清楚了.

#### 模板类型别名 C++11

``` C++
template <typename T> using twin = pair<T, T>;
twin<string> authors; //  pari<string, string> author;
template <typename T> using partNo = pair<T, unsigned>;
partNo<string> books; // pair<string, unsigned>
```



### 16.1.3 模板的参数

#### 模板参数和作用域

模板参数就是那个`T`, 特殊的在于不能重复,只能有一个名字

``` cpp
typedef double A;
template <typename A, typename B> void f(A a, B b)
{
    A tmp = a; // tmp has same type as the template parameter A, not double
    double B;  // error: redeclares template parameter B
}
```

#### 使用类的类型成员

当访问模板类的类型成员时, 要用`typename` eg ` typename T::class_member`, 注意是全程都要不只是返回类型

``` cpp
template <typename T>
typename T::value_type top(const T& c)
{
    if (!c.empty())
        return c.back();
    else
        return typename T::value_type();
}
```

这是一个函数模板, 接受`T`的引用, 返回`T`的一个成员

当一个名字表示类型的时候, 要告诉编译器 `typename`

#### 默认模板实参

和函数一样, 模板参数列表也有默认值

``` cpp
template <class T =int> class Foo {
    // ...
};
```



### 16.1.4 成员模板

类(普通/模板)中的成员是模板.

#### 普通类的成员模板

#### 模板类的成员模板

当在外定义的时候, 先声明类的参数列表, 再声明函数的列表

``` C++
// 类外定义
template <typename T> // 类的类型
	template <typename It> // 构造函数的类型参数
		Blob<T>::Blob(It b, It e);
```

#### 实例化

```C++
Blob<int> a2(vi.begin(), vi.end());
```



### 16.1.5 控制实例化

多个文件独立编译模板实例化可能会产生重复的代码, 通过**显式实例化**来避免额外开销

``` cpp
extern template declaration; // instantiation declaration
template declaration;        // instantiation definition
```

declaration是一个类或者函数声明

``` cpp
extern template class vector<string>;
template class vector<Sales_data>;
```

第一行是实例化声明, 表示别的地方实例化了, 此处不用实例化
第二行是实例化定义, 表示就在此处实例化4

### 16.1.6 效率和灵活性





## 16.2 模板实参推断

在调用函数模板的时候,从函数实参来确定模板实参的过程就是模板实参推断.

### 16.2.1 类型转换与模板类型参数

show me the code

``` C++
template <typename T> T fobj(T, T);
template <typename T> T fref(const T&, const T&);

string s1("a value");
const string s2("another value");
fobj(s1, s2); // fobj(string, string) const被忽略
fref(s1, s2); // fref(const string&, const string&) s1 转换为const

int a[10], b[42];
fobj(a, b); // int* int *
fref(a,b); // error 
// a和b是不相同的类型 int (&)[10] 具有10个int类型数组的引用
```

模板实参推断允许发生的(自动)类型转换只有两种情况

- const
- 数组和指针

### 16.2.2 函数模板显式实参

> 显式指定模板参数, 指定从模板列表的第一个开始

``` cpp
// T1 cannot be deduced: it doesn't appear in the function parameter list
template <typename T1, typename T2, typename T3>
T1 sum(T2, T3);
auto val3 = sum<long long>(i, lng); // long long sum(int, long)
```

显式实参是按照声明顺序来的

特别注意 `long long` 是一种类型,  `long double`也是如此

### 16.2.3 尾置返回类型和类型转换

``` C++
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    // process the range
    return *beg;  // return a copy of an element from the range
}
vector<int> vi = {1,2,3,4,5};
auto &i = fcn(vi.begin(), vi.end());
// 所有迭代器返回的都是元素的引用
```

类型转换 : 想要返回一个元素的值并非引用, 使用标准库的类型转换模板remove_reference

``` cpp
template <typename It>
auto fcn2(It beg, It end) ->
    typename remove_reference<decltype(*beg)>::type
{
    // process the range
    return *beg;  // return a copy of an element from the range
}
// Note type是一个类的成员, 该类依赖于模板, 所有要加typename
```

`type`是模板类`remove_reference`的一个public的数据成员, 表示模板类中参数类型去引用后的类型(也就是尖括号内类型去引用后的类型)

`remove_reference`是标准库中的头文件`type_traits`中的函数



### 16.2.5 模板实参推断和引用

``` C++
template <typename T> void f3(T &&);
f3(42); // 42本来就是一个右值
f3(i); // ???
```

`C++`允许的例外, 满足以下两个条件

- 将一个左值如(i)传递给函数的右值引用参数 
- 右值引用参数指向模板类型参数 (`T&&`)

编译器推断模板类型参数为实参的左值引用类型

结论: `f3(i)=>T=>int&`
[code](./TestDiffArgSameEffec.cc)

> 编译器推断模板类型参数是实参的左值引用, 因此`f3(i)`, 编译器推断`T`的类型为`int &`

- `X& &`  `X& &&` `X&& &`都折叠成类型 `X&`
- `X&& &&`折叠成类型`X &&`

### 16.2.6 理解std::move

``` C++
string s3(std::move(s2));
```

`move`在头文件`utility`中, 常用于移动构造代码中, 作用就是不管是左值引用还是右值引用, 都返回右值引用, 这样就可以调用移动构造函数了

``` C++
  template<typename _Tp>
    constexpr typename std::remove_reference<_Tp>::type&&
    move(_Tp&& __t) noexcept
    { return static_cast<typename std::remove_reference<_Tp>::type&&>(__t); }
```

- 第一行是函数模板参数列表, 只有一个模板参数`_Tp`
- 第二行是模板函数的返回值类型, 因为type的模板类的成员函数, 所有在最前面要加上`typename`, 返回的类型是`_Tp`去引用后的右值引用
- 第三行是函数的声明, 参数只有一个
- 第四行是函数的实现 : 通过引用折叠将`__t`转换成一个`_Tp`的右值引用类型. 

### 16.2.6 转发

将一个或者多个实参连同类型不变地转发给其他函数. (包括const 实参的左值还是右值)

``` C++
template <typename F, typename T1, typename T2>
void filp1(F f, T1 t1, T2 t2) {
	f(t2, t1);
}
```

如果f的参数是引用

``` C++
// 是会影响v2的值的
void f(int v1, int &v2) {
    cout << v1 << " " << ++v2 << endl;
}
```

当通过函数模板调用时

``` C++
filp1(f, j, 42);
// flip1( void(*fcn)(int, int&), int t1, int t2);
```

发生了拷贝, `t1`是`j`的拷贝, 函数体内是不会影响到`t1`的

``` C++
// 通过将一个函数参数定义成指向模板类型参数的右值引用
// 可以保持其对用实参的所有信息

// 1. 引用参数保持const属性(const在引用中都是底层的)
// 2. 通过引用折叠实现翻转实参是左右值属性

// T1 int & 
// T1 && => int& && => int&
template <typename F, typename T1, typename T2>
void filp2(F f, T1 &&t1, T2 &&t2) {
	f(t2, t1);
}
```

#### std::forward保持类型信息

保持实参的左右值属性

``` C++
template <typename F, typename T1, typename T2>
void filp1(F f, T1 &&t1, T2 &&t2) {
	f(std::forward<T2>(t2), std::forword<T1>(t1);
}
```



## 16.3 重载与模板

## 16.4 可变参数模板

## 16.5 模板特例化

