#include<iostream>
using namespace std;

void Merge(int A[] , int l , int r , int mid){
	int i = l;
	int j = mid+1;
	int k = l;
	
	int Acp[r+1];
	while(i <= mid && j <= r){
		if(A[i] > A[j]){
			Acp[k++] = A[i++];
		}else{
			Acp[k++] = A[j++];
		}
	}
	
	for(; i <= mid ; i++)
		Acp[k++] = A[i];
	
	for(;j <= r ; j++)
		Acp[k++] = A[j];
		
	for(int t = l ; t <= r ; t++)
		A[t] = Acp[t];
}

void MergeSort(int A[] , int l , int r){
	int mid;
	if(l < r){
		mid = (l + r)/2;
		MergeSort(A , l , mid);
		MergeSort(A , mid + 1 , r);
		Merge(A , l , r , mid);
	}
}
//sap xep giam dan 
int buildTow(int A[] , int M1 , int M2){
	int i = M1 > M2 ? M1 : M2;
	int j = M1 > M2 ? M2 : M1;
	
	int sum1 = 0;
	int t = 1;
	int p = 0;
	while(t <= j){
		sum1+= t * A[p++];
		sum1+= t * A[p++];
		t++;
	}
	int sum2 = 0;
	for(; t <= i ; t++){
		sum2 += t * A[p++];
	}
	return sum1 + sum2;	
}

int main()
{
	int t , cnt = 1;
	cin>>t;
	while(t>0){
	
	int N , M1 , M2;
	cin>>N>>M1>>M2;
	int A[N];
	for(int i = 0 ; i < N ; i++)
		cin>>A[i];
		
	MergeSort(A , 0 , N - 1);
	
	cout<<"#"<<cnt<<" "<<buildTow(A , M1 , M2)<<endl;
	cnt++;
	t--;
	}
	return 0;
}
