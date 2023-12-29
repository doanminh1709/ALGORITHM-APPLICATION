#include<bits/stdc++.h>
using namespace std;


void Xuat2(char S[] ,int M[] ,int k){
	for(int i = 0 ; i < k ; i++)
	 	cout<<S[M[i]-1]<<" ";
	cout<<endl;
}

void Generate(char S[], int n , int k){
	//Kiem tra tu cuoi xem phai cau hinh tren chua 
	//Khoi tao cau hinh dau tien 
	int *A = new int[k];
	for(int j = 0 ; j < k ; j++) A[j] = (j+1);
	
	int i;
	//Bai toan hoan vi ta luon co a[i] >= a[i-1] + 1 && a[i] <= n - k + i
	do{
	//In ra cau hinh dau tien 
	Xuat2(S , A , k);
	
	i =  k - 1;
	//Duyet tu cuoi ve dau tim phan tu chua dat gioi han tren 
	while(i >= 0 && A[i] == n - k + i + 1)
		i--;
	if(i >= 0){
		A[i]++;//Tang phan tu do len 1 	
		//Dat tat ca cac phan tu ngay sau no bang gioi hang duoi cua no 
		
		for(int j = i + 1 ; j < k ; j++){
            A[j] = A[j-1]+1;
        	}		
		}			
	}while(i>=0);
	
}

void Xuat(char S[] , int M[] ,int k){

	for(int i = 0 ; i < k ; i++)
//	 	cout<<S[M[i] - 1]<<" ";
		cout<<M[i+1]<<" ";
	cout<<endl;
}
void Try(char S[] , bool check[] , int M[] , int i , int n , int k){

 	for(int j = M[j- 1] + 1 ; j <= n - k + i ; j++){
 		if(!check[j]){
 		check[j] = true;
		M[i] = j;
 		if(i == k){
 			Xuat(S , M  , k);
		 }else
		 {
		 	Try(S, check , M , i+1 , n , k);
		}
		 check[j] = false;
		}
	}
 }
 
int main()
{
	int k ;
	int n =7 ;
	
	cin>>k;
	
	char S[n] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 

	int M[100] = {0};
	bool C[100] = {false};
	Try(S, C , M , 1 , n , k);
	
//	cout<<"Su dung phep sinh"<<endl;
	Generate(S , n , k);
	
	return 0;
 } 
