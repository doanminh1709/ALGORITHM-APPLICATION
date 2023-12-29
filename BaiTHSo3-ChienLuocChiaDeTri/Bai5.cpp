#include<bits/stdc++.h>
using namespace std;
//Tinh tong cac so trong mang bang chien luoc chia de tri 
double sumOfArr(double arr[] , int l , int r){
	if(l == r) return arr[l];
	else {
		int mid = (l+r)/2;
		return sumOfArr(arr , l , mid) + sumOfArr(arr , mid + 1 , r);
	}
}
int main(){
	int n = 20;
	double a[n] = {2.3 , 2 , 4 , 2.4 , 5.3  , 3.2 , 4.5 , 6.2 , 8 , 9.3};
	
	cout<<sumOfArr(a , 0 , n-1);
}
