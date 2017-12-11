#include<iostream>
using namespace std;
struct node{
	int year;
};
void showYear(node a){
	cout<<"year is :"<<a.year<<endl;
}
void show(int a ){
	cout<<"year is :"<<a<<endl;
}
int main() {
	// 结构体类型
	node s1,s2,s3;
	s1.year = 1996;
	s2.year = 1997;
//	showYear(s1);  //  year is 1996
//	showYear(s2);  //  year is 1997

	//结构体指针
	node * p_s3 = &s3;
	p_s3->year = 1998;
//	showYear(*p_s3);  //  year is 1998

	//结构体数组
	node n_arr[3];
	n_arr[0].year = 1999;
	(n_arr + 1)->year = 2000;
//	showYear(n_arr[0]);  	 //  year is 1999
//	showYear(*(n_arr+1));   //  year is 2000


	//指针数组
	const node * p_arr[3] = {&s1, &s2, &s3};
//	showYear(*p_arr[0]);  // *p_arr[0] is s1 , so year is 1996
//	showYear(**(p_arr+1));
//	show(p_arr[0]->year);
//	show((*(p_arr+1))->year);


	//指针的指针
	const node ** pp_arr = p_arr; // point the first element of p_arr array
//	showYear(**pp_arr);			  // **pp_arr is *p_arr[0] , so year also is 1996
//	showYear(**(pp_arr+1));     //  year is 1997
//	show((*pp_arr)->year);
	// c++ 11
	auto pp_auto = p_arr;    //auto keyword make it simple
//	showYear(**pp_auto);


	return 0;
} 
