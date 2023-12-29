#include<bits/stdc++.h>
using namespace std;

int soChanNhoNhat(int a[] , int l , int r){
	if(l == r){
		return a[l] % 2 == 0 ? a[l] : -1;
	}
	//Neu mang co 2 phan tu 
	if(l + 1 == r){
		return (a[l] < a[r] && a[l] % 2 == 0) ? a[l] 
		: (a[r] % 2 == 0) ? a[r] : -1; 
	}
	//Mang co nhieu hon 2 phan tu 
	else{
		int mid = (l + r)/2;
		int minLeft = soChanNhoNhat(a , l , mid);
		int minRight = soChanNhoNhat(a , mid+1 , r);
		
		return (minLeft < minRight && minLeft  % 2 == 0) 
		? minLeft : (minRight % 2 == 0) ? minRight : -1;
	}
}

int main(){
	int n = 20;
	int a[n] = {2 , 1 , -3 , 4 , 10 , 3 , 2 , -1 , 0 , 12 , 32 , -23 , 12 , 23
	,33 , 23 , -110 , 12 , -32 , 20};
	
	int scnn = soChanNhoNhat(a , 0 , n -1);
	if(scnn != -1){
		cout<<"So chan nho nhat trong mang : "<<scnn<<endl;
	}else{
		cout<<"Khong ton tai so chan nao nho nhat trong mang :"<<endl;
	}
	
	return 0;
} 
