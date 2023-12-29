/*
 Trong nha ban sach dang ban mot bo sach gom n cuon sach co gia la a[i]. 
 Nha sach dang co uu dai la mua 3 cuon thi mien phi cho sach re nhat trong 3 cuon. 
 Tim chi phi thap nhat de mua het n cuon sach 
 
 Vi du:
 7
 5 3 6 9 1 2 2 
 21  
*/

#include<iostream>
using namespace std;

#define MAX 1000001
int a[MAX];
int n;

int main(){

	//nhap vao n 
	cin>>n;
	
	//nhap vao mang 
	for(int i = 0 ; i < n ; i++)
		cin>>a[i];
		
	//sap xep mang giam dan 
	for(int i = 0; i < n - 1 ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(a[i] < a[j]) swap(a[i] , a[j]);
		}
	}
	
	//phuong phap 
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		if((i + 1) % 3 == 0){
			continue;
		}
		ans += a[i];
	}
	//in ra ket qua 
	cout<<ans<<endl;
	
	return 0;	
}

