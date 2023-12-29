/*
Mot kho hàng gom n gói hàng dk ghi stt tu 1 -> n, gói
hàng thu i có kích thuoc Si và klg Mi
(1 <= i <= n).
Ban ðêm mot tên chom len vào kho de lay trom hàng, tên chom
mang theo mot chiec ba lô có kích thuoc k. Vi nu nhi suc yeu
nên tên chom chi chon nhung goi hang nhe nhang 

Yêu cau: Hay chon cho tên chom nhung gói hàng ung y : tong
khoi luong các gói hàng duoc chon là nho nhat và tong kích
thuoc khong vuot qua kich thuoc cua balo

Solution : Sap xep theo khoi luong cac goi hang tang dan , 
va chon lan luot cac goi hang nay cho den khi ma kich thuoc 
no <= kich thuoc ba lo 
*/

#include<iostream>
using namespace std;

#define MAX 100
int n , k;
int S[MAX] , W[MAX];

void input(){
	cin>>n>>k;
	
	for(int i = 0 ; i < n ; i++)
		cin>>S[i];
		
	for(int i = 0 ; i < n ; i++)
		cin>>W[i];
		
}
void output(int A[]){
	for(int i = 0 ; i < n ; i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
void merge(int l , int r , int mid){
	int i = l , j = mid + 1;
	int k = l;
	int Scp[n] , Wcp[n];

	while(i <= mid && j <= r){
		if(W[i] < W[j]){
			Wcp[k] = W[i];
			Scp[k] = S[i];
			i++; k++;
		}else{
			Wcp[k] = W[j];
			Scp[k] = S[j];
			j++; k++;
		}
	}
	
	for( ; i < mid + 1 ; i++){
		Wcp[k] = W[i];
		Scp[k] = S[i];
		k++;
	}
	
	for(; j <= r ; j++){
		Wcp[k] = W[j];
		Scp[k] = S[j];
		k++;
	}
		
		
	for(int i = l ; i <= r ; i++){
		W[i] = Wcp[i];
		S[i] = Scp[i];
	}
}

void mergeSort(int l , int r){
	int mid;
	if(l < r){
		mid = (l + r)/2;
		mergeSort(l , mid);
		mergeSort(mid + 1 , r);
		merge(l , r , mid);
	}
}
void solve(){
	int i = 0;
	int sum = 0;
	//chon den khi nao ma gap goi hang thu i co kich thuoc lon hon balo 
	while(i < n && S[i] <= k){
		k-=S[i];
		sum+=W[i];
		cout<<"Chon goi hang "<<(i+1)<<"co size = "<<S[i]<<" va weight = "<<W[i]<<endl;
		i++;
	}
	cout<<"Tong khoi luong tat ca : "<<sum<<endl;
}
int main()
{
	
	input();
	mergeSort(0 , n - 1);
	solve();
	return 0;
}
