/*
Bai toan noi day :
	Cho n day voi chieu dai khac nhau , can phai noi cac day lai voi nhau thanh 1 day. 
	Chi phi noi 2 soi day lai voi nhau duoc tinh bang do dai tong do dai 2 day. 
	Nhiem vu cua bai toan la tim cach noi cac day lai voi nhau thanh 1 day sao cho chi phi noi cac
	day lai voi nhau la it nhat. 

Input 
2
4
4 3 2 6
8
9 7 12 8 6 5 14 4

Output 
29
190 


Huong giai quyet : Tai moi buoc ta se tim 2 day co do dai nho nhat lai voi nhau
*/
#include<iostream>
using namespace std;

#define MAX 100
int L[MAX];
int n;

void input(){
	cin>>n;
	for(int i = 0 ; i < n ; i++)
		cin>>L[i];
}
int find_partition(int A[] , int l , int h){
	int pivot = A[l];
	
	int i = l , j = h;
	do{
		do{i++;}while(A[i] < pivot);
		do{j--;}while(A[j] > pivot);
		if(i < j){
			swap(A[i] , A[j]);
		}
	}while(i < j);
	swap(A[l] , A[j]);
	
	return j;
}
void quickSort(int A[] , int l , int h){
	int partition;
	if(l < h){
		partition = find_partition(A , l , h);
		quickSort(A , l , partition);
		quickSort(A , partition + 1 , h);
	}
}
void output(int A[] , int n){
	for(int i = 0 ; i < n ; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

void solve(){
	
	quickSort(L , 0 , n);
	output(L , n);
	int res = 0;
	
	while(n>1){
		int sum = L[0] + L[1];
		//Tao 1 mang moi gom cac phan tu con lai va tong cua 2 phan tu dau 
		int cnt = 1;
		int B[MAX];
		B[0] = sum;
		
		for(int i = 2 ; i < n ; i++){
			B[cnt] = L[i];
			cnt++;
		}
		cout<<cnt<<endl;
		//sap xep lai mang B
		quickSort(B , 0 , cnt);
		output(B , cnt);
		//gan lai mang L bang mang B 
		for(int i = 0 ; i < cnt ; i++){
			L[i] = B[i];
		}
		//cap nhat lai n 
		n = cnt;
		res += sum;
	}
	cout<<res<<endl;
}
int main(){
	
	int t;
	cin>>t;
	while(t--){
		input();
		solve();	
	}
	return 0;
}
