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
