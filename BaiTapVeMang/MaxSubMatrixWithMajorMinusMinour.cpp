#include<iostream>
using namespace std;

#define MAXM 402

typedef long long ll;
typedef unsigned long long  ull;
typedef long double ld;

const int MOD = (int)1e9+7;
const int INF = (int)1e9+2804;

int major[MAXM][MAXM] = {0} , minor[MAXM][MAXM] = {0} , matrix[MAXM][MAXM];
int N;
/*
4
9 -2 -8 0
-6 -2 0 9
4 -5 6 1
1 3 4 9
*/

void input(){
	cin>>N;
	
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin>>matrix[i][j];
		}
	}	
}
void update(){

	//update major matrix 
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			if(i == 1 || j == 1){
				major[i][j] = matrix[i][j];
			}else{
				major[i][j] = matrix[i][j] + major[i-1][j-1];	
			}
		}
	}
	
	//update minor matrix 
		for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			if(i == 1 ||  j == N){
				minor[i][j] = matrix[i][j];
			}else{
				minor[i][j] = matrix[i][j] + minor[i-1][j+1];	
			}
		}
	}
}

void solve(){
	//tinh tong tat ma tran con sinh ra duoc tai moi vi tri i va j
	int ans = -1e9;	
	for(int i = N ; i >= 1 ; i--){
		for(int j = N ; j >= 1 ; j--){
			int temp = min(i , j);//co lon nhat cua ma tran vuong trong do i ,j la o ben phai cung 
			int row = i - temp , col = j - temp;
			//tai moi vi tri tinh kha nang ma tran ma no co the sinh ra 
			for(int k = 0 ; k <= temp ; k++){
				int res = (major[i][j] - major[row+k][col+k]) - (minor[i][col + k + 1] - minor[row+k][j+1]);
				ans = max(ans , res);
			}
		}
	}
	cout<<ans<<endl;
}
void ouput(int A[MAXM][MAXM]){
	for(int i = 0 ; i <= N ; i++){
		for(int j = 0 ; j <= N ; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
	ios::sync_with_stdio(false);//C++ co gang dong bo hoa cac hoat dong dau vao va dau ra voi cac ham C cua thu vien stdio, 
	//giup cai thien hieu suat 
	 
	cin.tie(nullptr);//thach thuc c++ khong can thiet lien ket cin va cout , dam bao k co dong code nao xuat sau khi doc tu cin 
	//giup cai thien hieu suat  
	
	input();
	update();
	solve();
	
	cout<<endl;
	ouput(major);
	cout<<endl;
	ouput(minor);
	
	return 0;
}
