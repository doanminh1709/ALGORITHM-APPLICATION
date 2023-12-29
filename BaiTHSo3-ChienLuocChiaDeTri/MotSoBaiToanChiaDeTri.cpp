#include<bits/stdc++.h>
using namespace std;

int max(int a[] , int l , int r)
{
	if(l == r){
		return a[l];
	}
	else if(l == r - 1){
		if(a[l] < a[r]){
			return a[r];
		}
		return a[l];
	}	
	if(l < r ){
		int mid = (l + r)/2;
		int maxLeft = max(a , l , mid);
		int maxRight = max(a , mid + 1, r);
		return maxLeft > maxRight ? maxLeft : maxRight;
	}
}
//Tinh tong cac so le trong mang bang phuong phap chia de tri 
int tongSoLe( int a[] , int l , int r){
	if(l < r){
		int mid = (l + r)/2;
		return tongSoLe(a ,l , mid) + tongSoLe(a , mid+1 , r);
	}
	//Truong hop co so l = r  
	if(l == r){
		if(a[l] % 2== 1)
		return a[l];
		else return 0;
	}
}
double mu(double a , int n)
{
	//Truong hop co so n == 1
	if(n == 1) return a;
	else{
	double b = mu(a , n / 2);
	if(n % 2 == 0){
		return b*b;
	}else{
		return b*b*a;
		}
	}
}
int main()
{
	int a[10] = {1 , 3 , 4 , 20 , 12 , 12 , 11 , 24 , 5};
	cout<<tongSoLe(a , 0 , 9);

//	cout<<mu(2.1 , 3);
	return 0;
 } 
