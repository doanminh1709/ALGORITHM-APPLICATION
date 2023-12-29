#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n = 5 , m = 5;
	int F[n+1][m+1];
		
	F[0][0] = 1;
	//Khoi tao gia tri F[0][0] bang 1 , vi th m = 0 , n = 0 , phan tich so n tu so m thi co 1 cach 
	for(int i = 0 ; i <= m ; i++){
		for(int j = 0 ; j <= n ; j++){
			//Th ma m = 0 , n != 0 thi khong the phan tich duoc 
			if(i == 0 && j > 0){
				F[i][j] = 0;
			}
			//Cac truong hop con lai thi tinh theo cong thuc 
			else if(i != 0 || j != 0){
				//i la m , con j la n 
				if(i > j){
					F[i][j] = F[i-1][j];
				}else{
					F[i][j] = F[i-1][j] + F[i][j - i];
				}
			}
		} 	
	}
	
	for(int i = 0 ; i <= m ; i++){
		for(int j = 0 ; j <= n ; j++){
			cout<<F[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//Su dung 2 mang 1 chieu boi vi thuc chat no se chi can dung 2 cot lien tiep o trong mang
	int arr1[n+1];
	int arr2[n+1];
	
	//khoi tao cho cot 1
	arr1[0] = 1; 
	for(int i = 0 ; i <= n ; i++)
		if(i != 0) arr1[i] = 0;
	
	//tinh gia tri 
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++){
			if(i > j){
				arr2[j] = arr1[j];
			}else{
				arr2[j] = arr1[j] + arr2[j-i];
			}
		}
		//Cap nhat du lieu cua mang 1 chinh la mang 2 
	}
	return 0;
}
