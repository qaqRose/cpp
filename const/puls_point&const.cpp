#include<iostream>
using namespace std;
int main(){
	//������ӹ�ϵ   ����ȫ 
//	int i = 2;
//	cin>>i;
//	const int ** pp2;  						 
//	int * p1;		  						
//	const int n = i;  						//���ͳ���  
//	pp2 = const_cast<const int**>(&p1);		//pp2�д����p1�ĵ�ַ 
//	*pp2 = &n;								// pp2 ��ֵ����ָ��p1 �� ָ�� n 
////											 ����  int* �� p1  ָ����  const int �� n 
//	
//	cout<<n<<endl;  // 2
//	cout<<&n<<endl; // 0x6dfe84
//	cout<<*p1<<endl;//  2 
//	cout<<p1<<endl; //0x6dfe84
//	
//	*p1 += 1;      //  �޸��� p1 ָ���� n  ��ֵ 
//	 
//	cout<<n<<endl;  // 2     ��amazing 1�� 
//	cout<<&n<<endl; //0x6dfe84
//	cout<<*p1<<endl;//  3 	��amazing 2��
//	cout<<p1<<endl; //0x6dfe84


	//һ����ӹ�ϵ  ��ȫ
	//���Խ� ��constָ�� ��ֵ��  const ָ�� 
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
