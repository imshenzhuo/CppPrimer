# 1

编译时期,编译器根据函数调用分析处函数类型,生成对应的函数

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