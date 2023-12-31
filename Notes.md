# 第二章 信息的表示和处理

## 2.1 信息储存

### 2.1.1 十六进制表示法

用`0x1234FF`的形式表示十六进制数字，1位十六进制数字对应4位二进制数字。

### 2.1.2 字数据大小

1byte=8bits

![截屏2023-09-24 14.49.58](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-09-24%2014.49.58-6941860.png)

### 2.1.7 C语言中的位级运算

确定位级表达式最好的方式：16->2->16

#### 掩码运算

掩码是一个位模式，表示从一个字中选出的位的集合

**EG**

`0x89ABCDEF&0xFF---->0x000000EF`

这里的`0xFF`便是掩码，选出了后8位

·`~0`是一个常见的表达全1的掩码

### 2.1.9 C语言中的移位运算

![截屏2023-09-24 14.57.16](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-09-24%2014.57.16-6941876.png)

**通常使用算术右移**

当需要移动k位（k很大时），实际上位移量仅仅是`k mod w`



## 2.2 整数表示

### 2.2.1 整型数据类型

![截屏2023-09-24 15.12.21](../../../../Library/Application%20Support/typora-user-images/%E6%88%AA%E5%B1%8F2023-09-24%2015.12.21.png)

### 2.2.2 & 2.2.3 无符号数和补码编码

无符号数：按照普通二进制码

补码：第一位代表负数

![截屏2023-09-24 15.14.37](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-09-24%2015.14.37-6941932.png)

### 2.2.4 有符号数和无符号数之间的转换

保持二进制编码不变，直接转换

![截屏2023-09-24 15.16.26](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-09-24%2015.16.26-6941949.png)

**在无符号数存在的情况下，统一转换为无符号数比较**



### 2.2.5 C语言中的有符号数和无符号数

C语言中默认为有符号数



### 2.2.6 扩展一个数字的位表示

#### 无符号数的扩展

直接在前加0

#### 补码的扩展

在前添加最高位有效数字的值



### 2.2.7 截断数字

#### 无符号数截断

舍弃高w-k位，得到`x mod 2^k`

#### 补码截断

截断后最高有效位的权值变成`-2^k-1`

**EG**

将x=53191从int截断为short，舍弃了16位，而`53191 mod 65535=53191`,但截断后最高位是-65535，所以答案是53191-65535=-12345

## 2.3 整数运算

### 2.3.1 无符号加法

两个无符号数相加，若溢出，会直接舍弃高位

#### 检测加法溢出

令s=x+y,若s<x或s<y则发生了溢出

### 2.3.2 补码加法

正溢出，减去 2^w;负溢出，加上 2^w;

#### 检测加法溢出

当且仅当，x>0,y>0,s<=0时，发生正溢出；当且仅当，x<0,y<0,s>=0时，发生负溢出

### 2.3.4 & 2.3.5 无符号乘法&补码乘法

`x*y=x·y mod 2^w`

### 2.3.6 乘以常数

乘以2^k即左移k位

### 2.3.7 除以2的幂

x>>k产生x/2^k(向下取整)

## 2.4 浮点数

### 2.4.2 IEEE浮点数表示法

![截屏2023-10-10 20.46.32](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-10%2020.46.32.png)

![截屏2023-10-10 20.27.20](../../../../../Library/Application%20Support/typora-user-images/%E6%88%AA%E5%B1%8F2023-10-10%2020.38.25.png)



**1.规格化的数字**

![截屏2023-10-10 20.47.56](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-10%2020.47.56.png)

**2.非规格化的数字**

![截屏2023-10-10 20.49.17](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-10%2020.49.17.png)

**3.特殊值**

![截屏2023-10-10 20.51.26](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-10%2020.51.26.png)

### 2.4.4舍入

**常见的舍入方式**

![截屏2023-10-10 21.00.11](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-10%2021.00.11.png)

其中，向偶数舍入是默认采用的。当浮点数取值不是恰好为中间值的时候，依然遵守小于中间值向下，大于中间值向上的规则。若浮点数取值恰好是中间值，则向偶数舍入。

在二进制中，0视作偶数，1视作奇数。只有当舍入位的右侧是100……形式时，才考虑向偶数舍入，如果小于100……就向下，大于100……就向上。

![截屏2023-10-10 21.02.05](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-10%2021.02.05.png)

# 第三章 程序的机器级表示

## 3.3 数据格式

![截屏2023-10-22 13.03.46](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.03.46.png)

**常用后缀为q**

## 3.4 访问信息

![截屏2023-10-22 13.05.29](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.05.29.png)

**只有生成4个字节数据的操作会将高位置0**

### 3.4.1. 寻址模式

![截屏2023-10-22 13.09.01](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.09.01.png)

**General Mode**

Imm($R_b$,$R_i$,$S$)表示$R_b+S*R_i+Imm$

**Special Mode**

$(R_b,R_i)$表示$R_b+R_i$



### 3.4.2 数据传送指令

#### MOV类

![截屏2023-10-22 13.20.11](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.20.11.png)

![截屏2023-10-22 13.20.26](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.20.26.png)

**不能从Mem到Mem**

--**EG**--

![截屏2023-10-22 13.21.59](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.21.59.png)

**指针加括号**

#### MOVZ类

![截屏2023-10-22 13.24.57](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.24.57.png)

**没有movzlq因为原始的movq已经可以实现**

#### MOVS类

![截屏2023-10-22 13.25.42](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.25.42.png)

## 3.5 算术和逻辑操作

### 3.5.1 加载有效地址LEA

`leaq (SOURCE),DEST`

将source写入dest

常用于加法和乘法

### 3.5.2 一元和二元操作



![截屏2023-10-22 13.33.58](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-22%2013.33.58.png)![截屏2023-10-22 13.33.21](../../../../../Library/Application%20Support/typora-user-images/%E6%88%AA%E5%B1%8F2023-10-22%2013.33.36.png)

### 3.5.5 特殊的算术操作

![截屏2023-11-01 19.41.01](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-01%2019.41.01.png)

## 3.6 控制

### 3.6.1 条件码

#### 会设置条件码的操作

![截屏2023-10-31 21.27.21](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2021.27.21.png)

*leaq除外*

![截屏2023-10-31 21.28.29](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2021.28.29.png)

#### 常用条件码

![截屏2023-10-31 21.29.12](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2021.29.12.png)

### 3.6.2 访问条件码

![截屏2023-10-31 21.32.46](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2021.32.46.png)

### 3.6.3 跳转指令

![截屏2023-10-31 21.37.55](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2021.37.55.png)

所谓大于，是指$S_2>S_1$

![截屏2023-10-31 22.02.00](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2022.02.00.png)

### 3.6.5 条件控制

![截屏2023-11-01 19.59.11](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-01%2019.59.11.png)

### 3.6.6 条件传送

![截屏2023-10-31 21.46.45](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2021.46.45.png)

```C
v=then-expr;
ve=else-expr;
t=test-expr
if(!t)
	v=ve;
return v;
```



### 3.6.7 循环

**实现方式是在分支中加入跳转语句**

### 3.6.8 Switch语句

![截屏2023-10-31 21.59.34](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2021.59.34.png)

![截屏2023-10-31 21.59.52](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2021.59.52.png)

**用什么来利用跳转表？**

`*.L4(,%rdi,8)`

间接跳转到.L4+%rdi中的数（输入）乘8的地方（.L4:start of jump table）

**FALL THROUGH**

![截屏2023-10-31 22.03.15](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2022.03.15.png)

**DEFAULT**

![截屏2023-10-31 22.03.35](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-10-31%2022.03.35.png)

## 3.7 过程

### 3.7.1 运行时栈



![截屏2023-11-14 21.43.25](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2021.43.25.png)

**%rsp指向栈顶，栈向低地址扩充。pop指令使%rsp增加，push指令使%rsp减小**

![截屏2023-11-14 21.44.46](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2021.44.46.png)

### 3.7.2 转移控制

![截屏2023-11-14 21.51.05](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2021.51.05.png)

![截屏2023-11-14 21.51.16](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2021.51.16.png)

![截屏2023-11-14 21.51.30](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2021.51.30.png)

![截屏2023-11-14 21.55.04](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2021.55.04.png)**%rip指向程序当前代码的地址，%rsp指向的是运行时栈的栈顶，注意区分**

**1.call时，将返回地址（call下一条语句的地址）压入栈中。%rip指向调用函数的首地址。**

**2.ret时，将返回地址出栈，%rip指向返回地址**

### 3.7.3 数据传送

![截屏2023-11-14 21.56.26](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2021.56.26.png)

### 3.7.4 栈上的局部储存

![截屏2023-11-14 22.06.07](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2022.06.07.png)

![截屏2023-11-14 22.09.37](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2022.09.37.png)

**movq $534,(%rsp)表示将534这个值存入%rsp所指的地址中**

**leaq 8(%rsp),%rsi表示将%rsp+8的地址存入%rsi中**

### 3.7.5 Caller/Callee Saved

![截屏2023-11-14 22.16.01](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2022.16.01.png)

![截屏2023-11-14 22.16.14](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-14%2022.16.14.png)

### 3.7.6 递归

![截屏2023-11-15 19.42.12](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2019.42.12.png)

**将(x&1)的值存在%rbx中，递归调用函数完成后一层层的加上**

## 3.8 数组

### 3.8.1 基本原则

![截屏2023-11-15 19.47.38](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2019.47.38.png)

![截屏2023-11-15 19.47.55](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2019.47.55.png)

### 3.8.3 多维数组

![截屏2023-11-15 19.50.32](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2019.50.32.png)

![截屏2023-11-15 19.52.28](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2019.52.28.png)

### 3.8.5 NxN Matrix

![截屏2023-11-15 19.56.32](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2019.56.32.png)

## 3.9 异质的数据结构

### 3.9.1 Structure

![截屏2023-11-15 19.59.38](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2019.59.38.png)

![截屏2023-11-15 20.09.47](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2020.09.47.png)

![截屏2023-11-15 20.10.04](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2020.10.04.png)

![截屏2023-11-15 20.10.54](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2020.10.54.png)

**储存在栈上时，先定义的在下**

### 3.9.2 Union

![截屏2023-11-15 20.14.28](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2020.14.28.png)

## 3.11 浮点数

![截屏2023-11-15 20.19.08](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2020.19.08.png)

![截屏2023-11-15 20.19.30](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-15%2020.19.30.png)

## 3.12 内存布局

![截屏2023-11-21 15.40.59](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2015.40.59.png)

![截屏2023-11-21 15.41.20](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2015.41.20.png)

![截屏2023-11-21 15.41.30](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2015.41.30.png)

## 3.13 缓冲区溢出

![截屏2023-11-21 15.56.40](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2015.56.40.png)

![截屏2023-11-21 15.57.01](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2015.57.01.png)

**在输入23个字符及以前，均不会有异常。若超过23个，会破坏返回地址和其他内容，产生危害**

![截屏2023-11-21 15.58.43](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2015.58.43.png)

### 解决方式

#### 使用更优的函数

![截屏2023-11-21 15.59.38](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2015.59.38.png)

#### 栈随机化

![截屏2023-11-21 16.01.15](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2016.01.15.png)

#### 限制可执行区域

![截屏2023-11-21 16.04.02](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2016.04.02.png)

#### 金丝雀

![截屏2023-11-21 16.05.45](../../../../../../../users/mickey/typora/%E6%88%AA%E5%B1%8F2023-11-21%2016.05.45.png)
