#include<bits/stdc++.h>
using namespace std;

//Mot so bai toan de quy 

//Tim ucln 
int gcd(int a , int b){
	if(b == 0) return a;
	else return gcd(b , a % b);
}

//Tinh to hop chap k cua n 
int cKn(int k , int n){
	if(k == 0 || n == 1) return 1;
	else return cKn(k - 1 , n - 1) + cKn(k - 1 , n);
}
//Tinh a ^b 
//Th co so : b = 0 thi bang 1 
//Con lai chia ra 2 th 
// b la so chan thi se a^(b/2) * a ^(b/2)
// b la so le thi se a^(b/2)*a^(b/2)*a
int aMub(int a , int b){
	int m = aMub(a , b/2);
	if(b == 0) return 1;
	else 
	if(b % 2 == 0) return m*m;
	else return m*m*a;
}
int fibonacci(int n){
	if (n == 0 || n == 1) return 1;
	else return fibonacci(n - 1) + fibonacci(n-2);
}
//Bai toan tim day con doi xung 
int dayConDx(int arr[] , int l , int r){
	//L va r gap nhau , hoan thanh viec xet doi xung 
	if(l >= r) return 1;
	//Xet theo thu tu , neu gap phan tu phia tay trai k bang ben phai thi day k dx
	if(arr[l] != arr[r]) return 0;
	else 
		return dayConDx(arr , l+1 , r-1);
	
}
int main()
{
//	int a = 3 , b = 6;
//	cout<<"Gcd "<<"("<<a<<","<<b<<") = "<<gcd(a , b)<<endl;
//	cout<<"Ckn "<<"("<<a<<","<<b<<") = "<<cKn(a , b)<<endl;
//	cout<<"A^B vs "<<"("<<a<<","<<b<<") = "<<aMub(a , b)<<endl;

	int n; cin>>n;
	int arr[n];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	if(dayConDx(arr, 0, n-1)){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
//	cout<<"Ckn"<<cKn(3 , 5)<<endl;
	
	return 0;
}
