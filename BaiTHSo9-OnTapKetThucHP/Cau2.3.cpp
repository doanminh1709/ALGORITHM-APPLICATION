#include<bits/stdc++.h>
using namespace std;

struct GoiHang{
	int mi;
	int vi;
};
void info(GoiHang gh){
	cout<<left<<setw(15)<<gh.mi
		<<setw(15)<<gh.vi
		<<endl;
}
void init(GoiHang gh[]){
	gh[0] = {5 , 15};
	gh[1] = {6 , 12};
	gh[2] = {3 , 10};
	gh[3] = {7 , 18};
	gh[4] = {8 , 17};
	gh[5] = {9 , 7};
}
void merge(GoiHang gh[] , int l , int r , int mid){
	int i = l , j = mid+1;
	int k = l;
	GoiHang ghcp[r+1];
	while(i <= mid && j <= r){
		if(gh[i].vi < gh[j].vi){
			ghcp[k++] = gh[i++]; 
		}else{
			ghcp[k++] = gh[j++]; 
		}
	}
	for(;i <= mid ; i++){
		ghcp[k++] = gh[i]; 
	}
	
	for(; j <= r ; j++){
		ghcp[k++] = gh[j];
	}
	
	for(int t = l ; t <= r ; t++){
		gh[t] = ghcp[t];
	}
}
void mergeSort(GoiHang gh[] , int l , int r){
	int mid;
	if(l < r){
		mid = (l + r)/2;
		mergeSort(gh , l , mid);
		mergeSort(gh , mid+1 , r);
		merge(gh , l , r , mid);	
	}
}
int greedAlgo(GoiHang gh[] , int n ,  int C){
	
	int i = 0 , cnt = 0;
	while(i < n){
		if(gh[i].vi <= C){
			C-=gh[i].vi;
			info(gh[i]);
			cnt++;
		}
		i++;
	}
	return cnt;
}
void dynamicPlanning(GoiHang gh[] , int dp[][100] , int n , int M){
	for(int i = 0 ; i <= M ; i++)
		dp[0][i] = 0;
		
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= M ; j++){
			dp[i][j] = dp[i-1][j];
			if(gh[i-1].mi <= j){
				int item = gh[i-1].vi + dp[i-1][j - gh[i-1].mi];
				if(item > dp[i][j]){
					dp[i][j] = item;
				}
			}		
		}
	}
	cout<<"BANG GIA TRI"<<endl;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= M ; j++){
			cout<<dp[i][j] <<" ";
		}
		cout<<endl;
	}
}

void trace(GoiHang gh[] ,int dp[][100], int n , int M){
	int i = n;
	int j = M;
	cout<<"CAC GIA TRI TUONG UNG"<<endl;
	while(i != 0){
		if(dp[i][j] != dp[i-1][j]){
			j = j - gh[i-1].mi;
			info(gh[i-1]);
		}
		i--;
	}
}
int main(){
	
	int C = 20;
	int M = 20;
	int n = 6;
	GoiHang gh[n];
	int dp[n+1][100];
	
	init(gh);
	mergeSort(gh , 0 , n - 1);
	cout<<"Su dung tham lam de lay so phan tu toi da"<<endl;
	cout<<greedAlgo(gh , n , C);
	
	cout<<"Su dung quy hoach dong de tinh so luong phan tu nhieu nhat"<<endl;
	dynamicPlanning(gh , dp , n, M);
	trace(gh , dp , n , M);
	
	return 0;
} 
