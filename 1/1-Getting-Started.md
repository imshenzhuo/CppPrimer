### main
main函数是怎样被系统调用的？
return 0是指正常，其他的代表错误代码
每次执行完 `echo $?` 查看

### iostream library
每个程序关的执行联了4个io对象，cin cout cerr clog 进程打开文件@os 

`std::out<<"Enter two numbers:"<<std::endl`
1. "..."是string常量
2. std::endl 不仅是换行，还要刷新buffer，确保输出，程序崩溃的时候可能不输出
3. 可以输出不同类型的变量
4. 这行语句return的就是std::out?


#### namespace
`std::endl` 表明使用的是std命名空间的endl操作


