/*
De bai : C�ng ty van tai A c� n chiec xe tai voi c�c xe c� t?i tr?ng
kh�c nhau, xe tai ti c� tai trong l� ki (tro dk ki tan).
C�ng ty A can van chuyen m tan h�ng tu mot kho den dia
diem kh�c, hoi c�ng ty can su dung bao nhi�u chiec xe
tai, gom nhung xe n�o (cho bi?t t?i tr?ng c?a xe ��?c
ch?n s? d?ng) sao cho s? xe t?i c?n s? d?ng l� �t nh?t.
C�i �?t ch��ng tr?nh gi?i quy?t b�i to�n (s? d?ng chi?n 
l�?c tham lam)
*/

#include<iostream>
using namespace std;

#define MAX 100
int n , m;
int F[MAX];
int T[MAX];

void input(){
	cin>>n>>m;
	
	for(int i = 0 ; i < n ; i++){
		T[i] = (i+1);
		cin>>F[i];
	}
		
}

void merge(int l , int r , int mid){
	int i = l , j = mid + 1;
	int k = l;
	int Fcp[n];
	int Tcp[n];
	
	while(i <= mid && j <= r){
		if(F[i] > F[j]){
			Fcp[k] = F[i];
			Tcp[k] = T[i];
			i++; k++;
		}else{
			Fcp[k] = F[j];
			Tcp[k] = T[j];
			j++; k++;
		}
	}
	
	for( ; i < mid + 1 ; i++){
		Fcp[k] = F[i];
		Tcp[k] = T[i];
		k++;
	}
	
	for(; j <= r ; j++){
		Fcp[k] = F[j];
		Tcp[k] = T[j];		
		k++;
	}
			
	for(int i = l ; i <= r ; i++){
		F[i] = Fcp[i];
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
	int i = 0;
	while(i < n && F[i] <= m){
		m-=F[i];
		cout<<"Chon xe tai "<<T[i]<<" co tai trong = "<<F[i]<<endl;
		i++;
	}
	cout<<"Vay cong ty can it nhat "<<(i)<<" chiec xe tai"<<endl;
}
int main(){
	
	input();
	mergeSort(0 , n - 1);
	solve();
	
	return 0;
}
