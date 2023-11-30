#include<iostream>
#define MAX 100
using namespace std;

//Cach thu nhat : tim tu dich tro ve dau  
int MinimumPathSum(int Matrix[][MAX] ,int N, int M ){

	int sum = Matrix[N-1][M-1];
	int i = N - 1 , j = M - 1;

	while(!(i - 1 < 0 && j - 1 < 0)){
		
		if(i - 1 >= 0 && j - 1 >= 0){
			if(Matrix[i-1][j] < Matrix[i][j-1]){
				sum+=Matrix[i-1][j];
				i--;
			}else{
				sum+=Matrix[i][j-1];
				j--;
			}
		}
		//kiem tra truong hop 1 trong 2 cai nho hon 0 
		if(i - 1 < 0 && j - 1 >= 0){
			sum+=Matrix[i][j-1];
			j--;

		}
		if(i - 1 >= 0 && j - 1 < 0){
			sum+=Matrix[i-1][j];
			i--;
		}
	}
	return sum;
}

int MinimumPathSum2(int Matrix[][MAX] ,int N, int M ){
	int dp[N][M];
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(i == 0 && j == 0){
				dp[i][j] = Matrix[i][j];
			}else if(i == 0){
				dp[i][j] = Matrix[i][j] + dp[i][j-1];
			}else if(j == 0){
				dp[i][j] = Matrix[i][j] + dp[i-1][j];
			}else{
				dp[i][j] = Matrix[i][j] + min(dp[i-1][j] , dp[i][j-1]);
			}
		}
	return dp[N-1][M-1];
}
//Cach thu 2 su dung mang 2 chieu tim tong nho nhat co the dat duoc
//Su dung y tuong cua quy hoach dong , tinh tung buoc di , tim ra gia tri thoa man o 2 vi tri cuoi cung 
  
int main(){	
	
	int N , M;
	cin>>N>>M;
	
	int Matrix[N][MAX];
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cin>>Matrix[i][j];
		}
	}
	
	cout<<MinimumPathSum(Matrix , N , M)<<endl;
	cout<<MinimumPathSum2(Matrix , N , M)<<endl;
	return 0;
} 
