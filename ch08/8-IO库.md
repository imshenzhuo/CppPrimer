IO库中的类型支持从设备读取数据、向设备写入数据的IO操作，设备可以是文件、控制台还有一些类型允许操作的内存IO（string）

## 8.1 IO类

IO库的类型有三种

| 头文件   | 类型                                         |
| -------- | -------------------------------------------- |
| iostream | istream、ostream、iostream                   |
| fstream  | fistream、ofstream、fstream                  |
| sstream  | istringstream、ostringstream、iostringstream |

`fstream`和`sstream`继承于`iostream`，所以使用完全一样

### 8.1.1 IO对象无拷贝或者赋值

### 8.1.2 条件状态

- badbit
- failbit
- eofbit
- goodbit

### 8.1.3 管理输出缓冲

输出，即向一个设备写入数据是很耗费资源的，因此每一个输出流都管理一个buffer，buffer刷新才会有一次输出。

#### 刷新输出缓冲区

```cpp
cout << "hi!" << endl; // 回车 + flush
cout << "hi!" << flush;
cout << "hi!" << endls; // flush + ' '
```

#### unitbuf 操作符

``` cpp
cout << unitbuf;
// 任意输出立即刷新
cout << nounitbuf;
```

#### 关联输入和输出流

如果输入流和输出流关联在一起，任何输入流读写，输出流都会flush

``` cpp
cin > val;
// cout flush
```



## 8.2 文件IO

### 8.2.1 使用文件流对象

``` cpp
ifstream in(file);
ofstream out;
out.open(ifle + ".copy");
if (out) {}
```

fstream对象被销毁，自动调用close函数

> 利用继承的关系，只需要更改几处地方就可以把标准IO变成文件IO，很赞

### 8.2.2 文件模式

输出流写入文件，如果该文件存在，默认清空，如果想要追加

``` cpp
ofstream out("file", ofstream::app);
```



## 8.3 String流

处理一行文本的单个单词的时候可以使用`istringstream`

当希望逐步构造输出，最后一起打印的时候使用`ostringstream`

