#include<iostream>
using namespace std;
int main(){
	int a[3] = {1,2,3};
	int * pa = a;
	int x ,y; 
	
	cout<<*pa<<endl;   // 1
	
	x = *pa++;           //  x = *pa ,then pa+1
	cout<<*pa<<endl;    // 2
	cout<<x<<endl;      // 1
	
	y = *++pa;          // pa+1 then y = *pa
	cout<<*pa<<endl;    //3
	cout<<y<<endl;      //3


	return 0;
} 
