
### const 和 数组

#### 显示数组及用const保护数组

在声明形参时，使用关键字const,
```
 void show_array(const double arr[], int n)
```
表示指针arr指向的常量数据，不能修改，因此在这个函数中，指针arr***只有读操作**而没有写操作   
使用 arr[0] += 1 会报错，这样确保了显示函数不能修改原始数


#### 使用数组区间的函数

指定元素区间，   
一个指针标识数组的开头，   
另一个指针标识数组的尾部
```
int sum_arr(const int * begin, const int * end) {
    int * pt;
    for(pt = begin; pt != end; pt++) {
        #code
    }
}

```

###  const 和 指针

> 下面用两个方法将const和指针结合
> - 第一种是让**指针指向一个常量对象**,这样可以防止使用该指针来修改所指向的值
> - 第二种方法是将**指针本身声明为常量**，这样可以防止改变指针指向的位置

1.指向常量的指针
```
const int * pt;
```

2.常量指针
```
int * const pt;
```



看下面的代码

```
int age = 1;
const int * pt = &age;

```
pt 指向一个const int，因此不能使用pt来修改这个值，换句话说，*pt的值是const 不能被修改
```
int arr[3] = {1,3,5};
const int * pa = &arr[0];
cout<<*pa<<endl;	  // 1
// *pa += 1;        //is not allow
pa+=1;                  
cout<<*pa<<endl;    // 3
```
上面这个例子中，pa指针指向数组的第一个元素，所以**pa指向的是一个常量对象**，而**pa本身并不是一个常量**，所以可以通过对pa做加1操作，是pa指向下一个元素，即可以**改变指针所指向的位置**


下面使用一个常量指针
```
int arr[3] = {1,3,5};
int * const pt = n;
cout<<*pt<<endl;        // 1
*pt += 1;
// pt += 1          // not allow
cout<<*pt<<endl;        // 2
```
这里使用的是一个常量指针，c++不允许改变其所指向的位置，不过这是一个整型指针，所以可以修改其指向地址的值


另外，还有两种可能，一种是将const变量的地址赋给const的指针，将~~const的地址赋给常规指针~~，不过第二种是不可行的


```
const float pi = 3.14;
#float * pt = &pi ;   // not allow

```
c++不允许的原因很简单，如果把pi的地址赋给pt,则可以使用pt来修改pi的值，这样pi的const就变得没有意义了

当然，使用强制类型转换可以突破这样的限制
```
int *pt;						 		
const int n = 5;  				
pt = const_cast<int*>(&n);		

*pt += 1;

cout<<n<<endl;    // 6
cout<<*pt<<endl;  // 6
```
上面通过使用const_cast,将const int * 转化为 int * ，其使用方法不变，然后pt便可以修改const n 的值

- 注意  有可能因为编译器优化问题，使得 n 跟 *pt 的值不一样，但是打印输出地址 &n 跟 pt ,却发现是一样的，其实是编译器把n 替换成字面量 5
```
int i;
const int n = i;
```
只要修改成这样，便可以防止编译器优化而输出不同的值


#### 一级间接关系

即将非const指针赋给const指针是可以的
```
int age = 1;
int * pd = &age;     //point to age
const int * pt = pd;  // int point assign to const int

```

#### 二级间接关系

进入二级关系，const与非const混合的指针赋值方式将不再安全

```
const int ** pp2;
int *p1;
const int n = 13;
pp2 = &p1;   // not allow
*pp2 = &n;
*p1 = 10;

```
上面代码中，pp2 = &p1 虽然是**非const指针赋值给const指针**，但因为是**二级间接关系**，情况更加复杂，并不被允许。如果被允许，那么将可以通过p1修改n的值，然而这样的 情况明显是不被允许的。


注意： pp2是一个指向常量指针的指针, p1是一个常规指针，


将指针参数声明为指向常量数据的指针有两个理由：
- 这样可以避免由于无意间修改数据而导致的编译错误
- 使用const 使函数能够处理const和非const实参，否则只能接受非const数据

```
#include<iostream>
using namespace std;
int main(){
	//二级间接关系   不安全
//	int i = 2;
//	cin>>i;
//	const int ** pp2;  						 
//	int * p1;		  						
//	const int n = i;  						//整型常量  
//	pp2 = const_cast<const int**>(&p1);		//pp2中存放了p1的地址
//	*pp2 = &n;								// pp2 的值（即指针p1 ） 指向 n
////											 所以  int* 的 p1  指向了  const int 的 n
//
//	cout<<n<<endl;  // 2
//	cout<<&n<<endl; // 0x6dfe84
//	cout<<*p1<<endl;//  2
//	cout<<p1<<endl; //0x6dfe84
//
//	*p1 += 1;      //  修改了 p1 指向了 n  的值
//	 
//	cout<<n<<endl;  // 2     （amazing 1）
//	cout<<&n<<endl; //0x6dfe84
//	cout<<*p1<<endl;//  3 	（amazing 2）
//	cout<<p1<<endl; //0x6dfe84


	//一级间接关系  安全
	//可以将 非const指针 赋值给  const 指针
//	int n =2;
//	int cn = 2;
//	int n[3] = { 1,3,5};
//	int * p = &n;
//	const int * cp;
//	cp = p;
//	cout<<*cp<<endl;
//	*p += 1;
//	 cout<<*cp<<endl;
//	 
//	const int * pt = &cn;
//	const int * pa = &n[1];
//	cout<<*pt<<endl;
//
//	cout<<*pa<<endl;
//	*pa += 1;
//	pa+=1;
//	cout<<*pa<<endl;
//	 cout<<*pt<<endl;

//	const int * ppt;
//	 
//	ppt =  n;
//	cout<<*ppt<<endl;
//	ppt +=1;
//
//	cout<<*ppt<<endl;

//	int * const pt = n;
//
//	cout<<*pt<<endl;
//	*pt += 1;
//	cout<<*pt<<endl;
	return 0;
}


```
