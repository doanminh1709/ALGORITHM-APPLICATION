/*
John c� mot chiec xe tai voi k�ch thuoc th�ng xe l� k (m3).
C�ng ty B c� n kien h�ng kh�c nhau, kien h�ng ti
c� khoi luong mi(kg) v� k�ch thuoc ki(m3). C�ng ty B thu� John
cho mot so kien h�ng trong so n kien h�ng. Hay cho biet
John xep dc bao nhi�u kien h�ng l�n th�ng xe, gom
nhung kien h�ng n�o, sao cho tong khoi luong xep l�n xe
dat dc l� lon nhat?
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
