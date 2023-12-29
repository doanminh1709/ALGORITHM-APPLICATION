#include<bits/stdc++.h>
using namespace std;

void Solve(int res[][100], int a[] , int b[] , int n , int m){
	
	for(int i = 0 ; i <= m ; i++){
		for(int j = 0 ; j <= n ; j++){
			if(i == 0 || j == 0){
				res[i][j] = 0;
			}
			else if(b[i - 1] == a[j - 1]){
				res[i][j] = res[i-1][j-1] + 1;
			}else if(b[i - 1] != a[j - 1]){
				res[i][j] = max(res[i-1][j] , res[i][j-1]);
			}
		}
	}
	
	cout<<res[m][n]<<endl;
}
void Trace(int res[][100],int a[], int b[], int n, int m) {
    int cnt = 0;
    int trace[100];
    int i = m, j = n;
    while(i > 0 && j > 0){
    	if(res[i-1][j] == res[i][j-1] && res[i][j] == res[i-1][j]){
			i--; j--;
		}else if(res[i-1][j] == res[i][j-1] && res[i][j] > res[i-1][j]){
			i--;
			trace[cnt++] = 	b[i];	
		}else{
			if(res[i-1][j] > res[i][j-1]){
				i--; 
			}else{
				j--;
			} 
		}
	}
	
	for(int i = cnt - 1 ; i >= 0 ; i--){
		cout<<trace[i]<<" ";
	}
}

int main(){
	
	int n = 10, m = 8;	
	int a[n] = {1 , 3 , 2 , 5 , 7 , 6 , 9 , 4 , 10 , 11};
	int b[m] = {3 , 2 , 5 , 7 , 6 , 12 , 4 , 43};
	int res[m+1][100]; 

	Solve(res , a , b , n , m);
	Trace(res , a , b , n , m);
	
	return 0;
}

