#include<iostream>
using namespace std;

#define MAX 500
int Matrix[MAX][MAX] , dp[MAX][MAX] ;
int n , m;

void input(){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin>>Matrix[i][j];
}
//Su dung chien thoat quy hoach dong , cap cua ma tran chinh la ta di xet tai phan tu vi tri phai cung , duoi cung 
void solve(){
	
	//neu phan tu o hang 0 hoac cot 0 co nghia chi co the tao ra duoc hinh vuong 
	// co kich thuoc toi da la 1 
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(i == 0 || j == 0) dp[i][j] = Matrix[i][j];
		}
	}
	//tiep tuc kiem tra 
	for(int i = 1 ; i < n ; i++){
		for(int j = 1 ; j < m ; j++){
			if(Matrix[i][j] == 1){
				dp[i][j] = min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1])) + 1;
			}else{
				dp[i][j] = 0;
			}
		}
	}
	//sau khi xu ly xong ta se di tinh phan tu max trong ma tran dp 
	int res = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			res = max(res , dp[i][j]);
		}
	cout<<res<<endl;
}

int main(){
/*
Input : 
6 5
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1  
0 0 0 0 0
			 
Output : 3
*/

	input();
	solve();
	
	return 0;
}
