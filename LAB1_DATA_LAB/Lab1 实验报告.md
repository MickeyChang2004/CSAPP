# CSAPP DATALAB 实验报告

## 1.bitNor

| 函数名   | bitNor                     |
| -------- | -------------------------- |
| 参数     | int , int                  |
| 功能实现 | ~(x\|y)                    |
| 要求     | 只能使用 ~ 和 &; Max ops:8 |

**实现分析：**

~ (x|y) = (~ x) & (~ y)
根据德摩根律，可以推导出上式


**函数实现：**

```C
int bitNor(int x, int y) {
  return (~x)&(~y);
}
```



## 2.copyLSB

| 函数名   | copyLSB                               |
| -------- | ------------------------------------- |
| 参数     | int                                   |
| 功能实现 | 将最后一位的值复制到每一位            |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:5 |

**实现分析：**

先将最后一位左移至最高位，再右移至最低位，根据算术右移的性质，可以知道这样就完成了复制


**函数实现：**

```C
int copyLSB(int x) {
  return x<<31>>31;
}
```



## 3.isEqual

| 函数名   | isEqual                               |
| -------- | ------------------------------------- |
| 参数     | int, int                              |
| 功能实现 | 如果x等于y输出1，否则输出0            |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:5 |

**实现分析：**

如果x等于y，那么x^y为全0，!(x ^y)即为1；x不等于y，x ^y为全1，!(x ^y)即为0


**函数实现：**

```C
int isEqual(int x, int y) {
  return !(x^y);
}
```



## 4.bitMask

| 函数名   | bitMask                                                      |
| -------- | ------------------------------------------------------------ |
| 参数     | int, int                                                     |
| 功能实现 | 将一个数从lowbit至highbit全部置为1，若lowbit>highbit则置为全0 |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:16                       |

**实现分析：**

先设置一个全1的掩码mask，将其左移(highbit+1)位后和其左移lowbit位后的数按位异或，这样就将lowbit到highbit之间的数都置为1；

而对于lowbit>highbit的情况，只需要将上一步得到的数与mask左移lowbit后的数按位与即可，这样如果lowbit>highbit,会将原先被置为1的数重新置为0


**函数实现：**

```C
int bitMask(int highbit, int lowbit) {
  int mask=~0,mask_lowbit=mask<<lowbit,mask_highbit=mask<<highbit;
  return ((mask_highbit<<1)^mask_lowbit)&(mask_lowbit);
}
```

## 5.bitCount

| 函数名   | bitCount                               |
| -------- | -------------------------------------- |
| 参数     | int                                    |
| 功能实现 | 输出一个数二进制表示中的1的个数        |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:40 |

**实现分析：**

整体来说，采用分治的思想，先求出2位一组中1的个数，再求4位一组，8位一组，16位一组，32位一组（为了节省ops，直接把8位一组中每组1的个数求和即可，即跳过16位1组和32位一组两步）；

以2位一组的情况为例，先利用左移构造出mask1=0x55555555,即0101……0101~2~,通过x&mask1+(x>>1)&mask1即可将每两位一组中1的个数储存在原先两位的位置，后续以此类推。


**函数实现：**

```C
int bitCount(int x) {
  int mask1=0x55,mask2=0x33,mask3=0x0f,count;
  mask1=mask1|(mask1<<8);
  mask1=mask1|(mask1<<16);
  mask2=mask2|(mask2<<8);
  mask2=mask2|(mask2<<16);
  mask3=mask3|(mask3<<8);
  mask3=mask3|(mask3<<16);//以上均是构造所需要的掩码
  count=(x&mask1)+((x>>1)&mask1);
  count=(count&mask2)+((count>>2)&mask2);
  count=(count&mask3)+((count>>4)&mask3);
  count=(count&0xff)+((count>>8)&0xff)+((count>>16)&0xff)+(count>>24);//每8位中1的个数直接求和，节省ops
  return count;
}
```



## 6.tmax

| 函数名   | tmax                                  |
| -------- | ------------------------------------- |
| 参数     | Void                                  |
| 功能实现 | 输出最大的2's complement integer      |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:4 |

**实现分析：**

最大的2's complement integer即为0111……1111~2~,将1000……0000~2~取反即可


**函数实现：**

```C
int tmax(void) {
  return ~(1<<31);
}
```



## 7.isNonNegative

| 函数名   | isNonNegative                         |
| -------- | ------------------------------------- |
| 参数     | Int                                   |
| 功能实现 | x>=0输出1，x<0输出0                   |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:6 |

**实现分析：**

将x右移31位后加1即可。若x为负数，则是1111……1111~2~+1等于全0；若x是正数或0，则是0000……0000~2~+1等于1


**函数实现：**

```C
int isNonNegative(int x) {
  return (x>>31)+1;
}
```



## 8.addOK

| 函数名   | addOK                                  |
| -------- | -------------------------------------- |
| 参数     | Int, int                               |
| 功能实现 | 相加无溢出输出1，否则输出0             |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:20 |

**实现分析：**

只要x和y的符号均与x+y一样，就可以判定没有溢出。所以利用异或即可完成。最后取非以达到输出0或1的要求。


**函数实现：**

```C
int addOK(int x, int y) {
  int sum=x+y;
  return !(((x^sum)&(y^sum))>>31);
}
```



## 9.rempwr2

| 函数名   | rempwr2                                |
| -------- | -------------------------------------- |
| 参数     | Int, int                               |
| 功能实现 | 计算x%(2^n)，负数则输出为负            |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:20 |

**实现分析：**

x%(2^n),实际上就是要保留x的后n位。先统一把x转换为正数，便于操作，然后利用全1左移n位后取反，来实现保留x的后n位的效果。最后若x是负数则转换回负数。

其中，x=(x^sign)+(sign&1)的本质就是取反加一，但是这样写就不会对正数产生影响了


**函数实现：**

```C
int rempwr2(int x, int n) {
    int sign=x>>31;
    x=(x^sign)+(sign&1);//x如果是负数就转换成正数
    x=x&(~(~0<<n));
    return (x^sign)+(sign&1);//x如果是负数就转换回负数
}
```



## 10.isLess

| 函数名   | isLess                                 |
| -------- | -------------------------------------- |
| 参数     | Int, int                               |
| 功能实现 | 如果x<y，返回1，否则返回0              |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:24 |

**实现分析：**

因为当x，y不同号时，做x-y可能会发生溢出，所以要分情况。

当x，y不同号且x负y正时，可以直接判定x<y;

当满足x-y<0(通过对y取反加1实现减法)且x，y同号时，可以判定x,y;


**函数实现：**

```C
int isLess(int x, int y) {
  return ((((x^y)&x)|((x+~y+1)&(~(x^y))))>>31)&1;
}
```



## 11.absVal

| 函数名   | absVal                                 |
| -------- | -------------------------------------- |
| 参数     | Int                                    |
| 功能实现 | 输出x的绝对值                          |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:10 |

**实现分析：**

原理同rempwr2函数中仅将负数转换成正数且不对正数造成影响


**函数实现：**

```C
int absVal(int x) {
    int sign=x>>31;
    return (x^sign)+(sign&1);
}
```

## 12.isPower2

| 函数名   | isPower2                                   |
| -------- | ------------------------------------------ |
| 参数     | Int                                        |
| 功能实现 | 如果x是2的幂，返回1，否则返回0,负数也输出0 |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:20     |

**实现分析：**

若x是2的幂，则x中有且仅有一位是1，那么将x-1后再和x按位与，会得到全0；需要特别注意，x=0时也满足上述情况，所以要单独用!!x来排除x=0的情况


**函数实现：**

```C
int isPower2(int x) {
  return ((x>>31)+1)&(!(x&(x+~0)))&(!!x);
}
```



## 13.float_neg

| 函数名   | float_neg                              |
| -------- | -------------------------------------- |
| 参数     | Unsigned                               |
| 功能实现 | 输出-f，若f是NaN，直接返回f            |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:10 |

**实现分析：**

先判断是否是NaN,如果和0x7fffffff按位与之后大于0x7f800000就表示exp为全1，且frac不为0，也就是NaN;

如果不是NaN,就通过与1000……0000异或来改变符号位


**函数实现：**

```C
unsigned float_neg(unsigned uf) {
  if((uf&0x7fffffff)>0x7f800000) //NaN
    return uf;
  return uf^0x80000000;
}
```

## 14.float_half

| 函数名   | float_half                              |
| -------- | --------------------------------------- |
| 参数     | Unsigned                                |
| 功能实现 | 返回0.5*f的位级表示,若f是NaN，直接返回f |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:30  |

**实现分析：**

先判断是否是NaN;

若exp不为0或1，则直接将exp-1即可满足要求，相当于乘了1/2，为了节省ops，即为减去0x800000;

若exp为0或1，则将frac先右移一位，若exp是0，首位就补0，exp是1，首位就补1. 然后关注舍入的问题，如果原先的frac以11结尾，那么就需要进1，其他情况均不需要进1


**函数实现：**

```C
unsigned float_half(unsigned uf) {
  unsigned exp=uf&0x7f800000,sign=uf&0x80000000,frac=uf&0x7fffff;
  if(exp==0x7f800000)//NaN
    return uf;
  if(exp>0x800000)
    return uf-0x800000;
  else
    return (sign|((frac>>1)|(0x400000&(exp>>1))))+((frac&3)==3);
}
```



## 15.float_i2f

| 函数名   | float_i2f                              |
| -------- | -------------------------------------- |
| 参数     | Int                                    |
| 功能实现 | 返回(float)x的位级表示                 |
| 要求     | 只能使用! ~ & ^ \| + << >>; Max ops:30 |

**实现分析：**

对于0和0x80000000两种特殊情况单独处理；

如果x是负数需先转换成正数；

通过while循环确定x中第一个1出现的地方，同时得出exp；

然后进行舍入操作，特别注意，如果frac的第24位为1，表示需要进位。在这种情况下，将指数exp加1，并将frac设置为0，以确保正确的舍入行为


**函数实现：**

```C
unsigned float_i2f(int x) {
  int sign,exp,frac,n,tail;
  if (x==0) 
    return 0;
  else if(x==0x80000000) 
    return 0xcf000000;
  sign=x&0x80000000;
  if (sign) 
    x=-x;
  n=1;
  while (x>>n)//找第一个1的位置
    n++;
  n--;
  exp=n+127;
  x=x<<(31-n); //移到最左
  frac=(x>>8)&0x7FFFFF;
  //舍入
  if (n>23) 
  {
    tail=x&0xFF;
    if ((tail>128)||((tail==128)&&(frac&1))) 
    {
      frac+=1;
      if (frac>>23) 
      {
        exp+=1;
        frac=0;
      } 
    }
  }
  return sign|(exp<<23)|frac;
}
```

