/*
John có mot chiec xe tai voi kích thuoc thùng xe là k (m3).
Công ty B có n kien hàng khác nhau, kien hàng ti
có khoi luong mi(kg) và kích thuoc ki(m3). Công ty B thuê John
cho mot so kien hàng trong so n kien hàng. Hay cho biet
John xep dc bao nhiêu kien hàng lên thùng xe, gom
nhung kien hàng nào, sao cho tong khoi luong xep lên xe
dat dc là lon nhat?
*/
#include<iostream>
using namespace std;


#define MAX 100
int n , k;
int M[MAX];
int S[MAX];
int T[MAX];

//sap xep giam dan theo khoi luong chon lan luot kich co tu trai qua phai 

void input(){
	cin>>n>>k;
	
	for(int i = 0 ; i < n ; i++){
		T[i] = (i+1);
		cin>>M[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>S[i];
	}
		
}

void merge(int l , int r , int mid){
	int i = l , j = mid + 1;
	int k = l;
	
	int Mcp[n];
	int Scp[n];
	int Tcp[n];
	
	while(i <= mid && j <= r){
		if(M[i] > M[j]){
			Mcp[k] = M[i];
			Scp[k] = S[i];
			Tcp[k] = T[i];
			i++; k++;
		}else{
			Mcp[k] = M[j];
			Scp[k] = S[j];
			Tcp[k] = T[j];
			j++; k++;
		}
	}
	
	for( ; i < mid + 1 ; i++){
		Mcp[k] = M[i];
		Scp[k] = S[i];
		Tcp[k] = T[i];
		k++;
	}
	
	for(; j <= r ; j++){
		Mcp[k] = M[j];
		Scp[k] = S[j];
		Tcp[k] = T[j];	
		k++;
	}
			
	for(int i = l ; i <= r ; i++){
		M[i] = Mcp[i];
		S[i] = Scp[i];
		T[i] = Tcp[i];	
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
	int sum = 0;
	int i = 0;
	while(i < n && S[i] <= k){
		sum+= M[i];
		k-=S[i];
		cout<<"John co the xep kien thang thu "<<T[i]
		<<" voi trong luong = "<<M[i]<<" va kich thuoc = "
		<<S[i]<<endl;
		i++;
	}
	cout<<"Vay John xep duoc tong cong : "<<i<<" kien hang"<<" voi khoi luong max : "<<sum<<endl;
}
int main(){
	
	input();
	mergeSort(0 , n - 1);
	solve();
	
	return 0;
}
