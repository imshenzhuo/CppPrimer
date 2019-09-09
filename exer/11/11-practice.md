# 1

> Describe the differences between a map and a vector

`map`是关联容器，按照`key`存取元素， 每个`item`有两个元素
`vector`是顺序容器，按照位置存取元素，每个`item`有一个元素

# 2

> Give an example of when each of list, vector, deque, map, and set might be most useful.

- list 插入多于查询
- vector 索引查找
- deque 消息队列
- map 电话簿
- set 黑名单

# 3&4

https://github.com/imshenzhuo/CppPrimer/blob/master/exer/11/exer11_4.cpp

# 5 

> Explain the difference between a map and a set.

当要使用电话簿就map，黑名单就set

# 6 

> Explain the difference between a set and a list. When might you use one or the other?

`set`元素唯一，有序，`list`底层是链表

# 7 

https://github.com/imshenzhuo/CppPrimer/blob/master/exer/11/exer11_7.cpp

# 8

元素唯一且有序

# 9

> Define a map that associates words with a list of line numbers on which the word might occur

https://github.com/imshenzhuo/CppPrimer/blob/master/exer/11/exer11_9.cpp

# 10

> Could we define a map from vector<int>::iterator to int? What about from list<int>::iterator to int? In each case, if not, why not?

可以定义，但是vector定义的`<` list没有，所以当`insert`的时候，list报错

# 12 

> Write a program to read a sequence of strings and ints, storing each into a pair. Store the pairs in a vector.

https://github.com/imshenzhuo/CppPrimer/blob/master/exer/11/exer11_12.cpp

# 13

> There are at least three ways to create the pairs in the program for the previous exercise. Write three versions of that program, creating the pairs in each way. Explain which form you think is easiest to
> write and understand, and why.

显式就 make_pair(v1, v2);

隐式就用初始化列表 pair<T1, T2> = {v1, v2};



# 15

- mapped_type: vector<int>
- key_type int
- value_type pair<const int, vector<int>>

# 20 

> Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead of subscripting. Which program do you think is easier to write and read? Explain your reasoning.

``` cpp
++m[word];
// 
auto ret = m.insert({word, 1});
if(!ret.second){
    ++ret.first->second;
}
```

当然是第一个好写，也好读

# 21

> Assuming word_count is a map from string to size_t and word is a string, explain the following loop:
>
> ``` cpp
> while (cin >> word)
>   ++word_count.insert({word, 0}).first->second;
> ```

word count 的极客版本

# 22 

> Given a `map<string, vector<int>>`, write the types used as an argument and as the return value for the version of insert that inserts one element.

``` cpp
pair<string, vector<int>>;
pair<map<string, vector<int>>::iterator, bool>
```

# 23 

> Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exer in § 11.2.1 (p. 424) to use a multimap.

# 24

m中插入一个数据，key是0，value是1

# 25

Segmentation fault (core dumped)

# 26

key的类型，返回value的类型，即mapped_type对象

# 27

计数的时候用count

不想插入新元素的时候用 find



# 33

https://github.com/imshenzhuo/CppPrimer/blob/master/exer/11/exer11_33.cpp

# 34

> What would happen if we used the subscript operator instead of find in the transform function?

因为在函数参数的`map`类型是`const`约束，而下标操作会改变`map`值，所以编译器不允许编译通过

# 35 

> In buildMap, what effect, if any, would there be from rewriting`trans_map[key] = value.substr(1);`
> as `trans_map.insert({key, value.substr(1)})`?

- 下标操作保留最新的数据
- insert操作保留最旧的数据

# 37

> What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?

无序的比较快，有的key没有必要有序

有序的有序，可以逐个访问

# 38 

https://github.com/imshenzhuo/CppPrimer/blob/master/exer/11/exer11_38.cpp