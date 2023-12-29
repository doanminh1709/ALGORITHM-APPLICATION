#include<iostream>
using namespace std;
/*
	Khi xep 1 con hau thi can phai xac dinh con hau no nam o cot  nao thi ta se khong the cho cac duong cheo xuoi 
	va duong cheo nguoc xep con hau nua va tren ca cot day cung vay 

	Ta se co duong cheo xuoi duoc danh chi so tu 1 den 2*n - 1. O(i , j) quan ly duong cheo xuoi i - j + n quan ly 
	Cac duong cheo nguoc duoc danh chi so tu 1 den 2*n - 1. O (i , j) quan ly duong cheo nguoc i + j - 1 quan ly 
*/

int N, X[100] ,C[100], D1[100] , D2[100];
int A[100][100];

void show(){
	for(int i = 0 ; i <= 99 ; i++)
		for(int j = 0 ; j <= 99 ; j++)
			A[i][j] = 0;
			
			
	for(int i = 1 ; i <= N ; i++){
		A[i][X[i]] = 1;
	}
	for(int i = 1; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
} 

void Try(int i){
	for(int j = 1 ; j <= N ; j++){
		//Neu tren duong cheo nay la an toan 
		if(C[j] == 1 && D1[i - j + N] == 1 && D2[i + j - 1] == 1){
			X[i] = j;
			//danh dau la khong an toan nua 
			C[j] = D1[i - j + N] = D2[i+j-1] = 0;
			if(i == N){
				show();
			}else{
				Try(i+1);
			}
			//Backtracking neu khong thoa man 
			C[j] = D1[i - j + N] = D2[i+j-1] = 1;
		}
	}
}

int main(){
	cin>>N;
	//khoi tao cau hinh ban dau 
	for(int i = 1 ; i<= 99 ; i++){
		C[i] = D1[i] = D2[i] = 1;
	}
	Try(1);
	
	return 0;
}
