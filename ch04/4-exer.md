## Exercise 4.1

> What is the value returned by 5 + 10 * 20/2?

105

## Exercise 4.2

> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
> (a) * vec.begin()
> (b) * vec.begin() + 1

``` cpp
*(vec.begin())
(*vec.begin()) + 1
```

## Exercise 4.3

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

经验不足，无法回答。不知道有多大的优化空间，也不知道会遇到什么陷阱

## Exercise 4.8

> Explain when operands are evaluated in the logical AND , logical OR , and equality operators.

AND: 左边的必执行 如果左边的是true，右边的执行
OR：左边的必执行 如果左边的是false，右边的执行
==：都执行

## Exercise 4.9

> Explain the behavior of the condition in the following if
>
> ``` cpp
> const char *cp = "Hello World";
> if (cp && *cp)
> ```

指针不是空指针并且指针指的东西不是空

## Exercise 4.12

> Assuming i, j, and k are all ints, explain what i != j < k means.

先是优先级，才是关联性，`i!=j<k` => `i!=(j<k)` ,也就是说，如果`j<k`并且`i!=1`那么返回`1`

## Exercise 4.13

> What are the values of i and d after each assignment?
> int i;   double d;
> (a) d = i = 3.5;
> (b) i = d = 3.5;

a. i=3 d=3
b. d = 3.5 i = 3

## Exercise 4.14

> Explain what happens in each of the if tests:
> if (42 = i)   //  ...
> if (i = 42)   //  ...

Error  
assignment true

## Exercise 4.15

> The following assignment is illegal. Why? How would you correct it?
>
> ``` cpp
> double dval; int ival; int *pi;
> dval = ival = pi = 0;
> ```

## Exercise 4.19

> Given that ptr points to an int, that vec is a vector<int>, and that ival is an int, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
> (a) ptr != 0 && *ptr++
> (b) ival++ && ival
> (c) vec[ival++] <= vec[ival]

a. !ptr && (*ptr)++
b. right
c. undefined

## Exercise 4.20: 

> Assuming that iter is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.

(a) `*iter++;` // legal  先取iter所指的对象，在iter++
(b) `(*iter)++;`  //   iter所指的对象 + 1 但是string没有++操作
(c) `*iter.empty()` // illegal `(*iter).empty()`
(d) `iter->empty();` // legal
(e) `++*iter;` //  优先级`++`高于`*` 所以，`iter`先指向下一个对象，然后取下一个对象 但是string没有++
(f) `iter++->empty();` // 优先级 `-> ` 高于 `++` 所以返回`iter->empty()` 然后`iter++`

