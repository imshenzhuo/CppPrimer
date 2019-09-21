## Exercise 3.3

> Explain how whitespace characters are handled in the string input operator and in the getline function.

string input首先过滤掉开始的空白符，然后在读，直到遇到第二个空白符
getline函数从开始就读，直到遇到换行符

## Exercise 3.13

> How many elements are there in each of the following vectors? What are the values of the elements?

(a) vector<int> v1;  // 0
(b) vector<int> v2(10); // 10个0
(c) vector<int> v3(10, 42);  //10个42
(d) vector<int> v4{10}; //1 -- 10
(e) vector<int> v5{10, 42}; // 2 -- 10 42
(f) vector<string> v6{10}; // 10 -- ""
(g) vector<string> v7{10, "hi"}; // 10 --- "hi"



## Exercise 3.18

> Is the following program legal? If not, how might you fix it?
>
> ``` cpp
> vector<int> ivec;
> ivec[0] = 42;
> ```

``` cpp
ivec.push_back(42);
```

## Exercise 3.19

> List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.

```cpp
vector<int> ivec = (10, 42);
vector<int> ivec = {42,42,42,42,42,42,42,42,42,42};
vector<int> ivec;
for(int i=0; i<10; ++i)
    vector.push_back(42);
```

## Exercise 3.26

> In the binary search program on page 112, why did we write mid = beg + (end - beg) / 2; instead of mid = (beg + end) /2;?

可能会越界 ×

迭代器之间没有相加操作，只有相减操作

## Exercise 3.27

> Assuming txt_size is a function that takes no arguments
> and returns an int value, which of the following definitions are illegal?
> Explain why.
> unsigned buf_size = 1024;
> (a) int ia[buf_size];
> (b) int ia[4 * 7 - 14];
> (c) int ia[txt_size()];
> (d) char st[11] = "fundamental";

a. illegal. not a const value
b. legal
c. illegal
d. error no space for null

## Exercise 3.28

> What are the values in the following arrays?
>
> ``` cpp
> string sa[10]; // 10 * ""
> int ia[10]; // 10 0
> int main() {
>     string sa2[10]; // undefine
>     int    ia2[10];
> }
> ```

## Exercise 3.29

> List some of the drawbacks of using an array instead of a vector.

定长、