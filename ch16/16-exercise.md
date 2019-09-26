# 1

编译时期,编译器根据函数调用分析处函数类型,生成对应的代码

# 2 [exer16_2.cpp](./exer16_2.cpp)

# 3 [exer16_3.cpp](./exer16_2.cpp)

``` bash
exer16_2.cpp:15:9: error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
  if (v1 < v2) return -1;
         ^
```

# 4 [exer16_4.cpp](./exer16_4.cpp)

# 9

> What is a function template? What is a class template?

函数模板就是函数的模板. 编译器根据相同函数名字,不同参数类型,自动生成对应的函数
类模板就是类的模板,编译器根据给定的参数类型生成不同的类

函数模板编译器可以推断,类模板必须用户指定

# 10

> What happens when a class template is instantiated?

生成了对应参数类型的类

# 11

> The following definition of List is incorrect. How would you fix it?
>
> ``` cpp
> template <typename elemType> class ListItem;
> template <typename elemType> class List {
> public:
>     List<elemType>();
>     List<elemType>(const List<elemType> &);
>     List<elemType>& operator=(const List<elemType> &);
>     ~List();
>     void insert(ListItem *ptr, elemType value);
> private:
>     ListItem *front, *end;
> };
> ```
>
> 

``` cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *front, *end;
};
```

# 12 [exer16_12.cpp](./exer16_12.cpp)

> Write your own version of the Blob and BlobPtr templates. including the various const members that were not shown in the text.

# 13

> Explain which kind of friendship you chose for the equality and relational operators for BlobPtr.

只有相同类型才有比较的意义,所以关系自然是一对一

# 14 [exer16_14.cpp](./exer16_14.cpp)

> Write a Screen class template that uses nontype parameters to define the height and width of the Screen.

# 16 [exer16_16.cpp](./exer16_16.cpp)

> Rewrite the StrVec class (§ 13.5, p. 526) as a template named Vec.



# 18

a. ×
b. 错
c. 错
d. 错
e. 错



# 25 

> explain 
>
> ```cpp
> extern template class vector<string>;
> template class vector<Sales_data>;
> ```

第一行是实例化声明, 表示别的地方实例化了, 此处不用实例化
第二行是实例化定义, 表示就在此处实例化

# 26

https://stackoverflow.com/questions/21525169/while-explicitly-instantiating-vectorsometype-what-is-the-sometype-default-co

# 27 

> For each labeled statement explain what, if any, instantiations happen. If a template is instantiated, explain why; if not, explain why not.

``` cpp
emplate <typename T> class Stack { };
void f1(Stack<char>);                   // (a)
class Exercise {
    Stack<double> &rsd;                 // (b)
    Stack<int>    si;                   // (c)
};
int main() {
    Stack<char> *sc;                    // (d)
    f1(*sc);                            // (e)
    int iObj = sizeof(Stack< string >); // (f)
}
```

编译, 引用, 指针不需要实例化 `cef`处发生了实例化



# 32

可能发生类型转换

# 33

1. 关于const, 模板是const类型, 实参是非const类型
2. 数组或者指针转换

# 34

1. 不合法 
2. 合法  `const char (&)[4]`

# 35

1. 合法 char
2. 合法 double
3. 合法 char
4. 不合法

# 36

1. `f1(int*, int*)`
2. `f2(int*, int*)`
3. `f1(const int*, const int *)`
4. `f2(const int*, const int *)`
5. error
6. `f2(int*, const int*)`

# 37 [exer16_37.cpp](./exer16_37.cpp)

不能直接使用, 要显式指定

    int a = 6; 
    double b = 6.1231;
    cout << max<int>(a, b) << endl;
 

# 38

不要为难编译器

