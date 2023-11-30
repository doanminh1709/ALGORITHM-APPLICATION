#include<bits/stdc++.h>
using namespace std;

int main()
{
/*
Test 
1
4 6
10 10 2 0 20 4
1 0 0 30 2 5
0 10 4 0 2 0
1 0 2 20 0 4
	*/
	int t;
	cin>>t;
	//cach 1 : duyet tung kha nang va dua ra kha nang toi uu nhat 
/*	while(t--){
		int N, M;
		cin>>N>>M;
		
		int A[N][M];
		for(int i = 0 ; i < N ; i++)
			for(int j = 0 ; j < M; j++)
				cin>>A[i][j];
			
		int maxSum = -1e8;		
		for(int j = 0 ; j < M; j++){
			
			int tmpSum = A[0][j];
			int i = 1;
			int currCol = j;
			
			while(i < N){
				
				if(currCol - 1 >= 0 && currCol + 1 < M){
					
					int maxvl = max(A[i][currCol-1] , max(A[i][currCol] , A[i][currCol+1]));
					
					if(maxvl == A[i][currCol-1]){
						currCol--;
					} else if(maxvl == A[i][currCol+1]){
						currCol++;
					}
				}else{
					if(currCol - 1 < 0){
						int maxvl = max(A[i][currCol] , A[i][currCol+1]);
						currCol = maxvl == A[i][currCol+1] ? currCol++ : currCol;
						
					}else if(j + 1 > M){
						int maxvl = max(A[i][currCol] , A[i][currCol-1]);
						currCol = maxvl == A[i][currCol-1] ? currCol-- : currCol;
					}
				}
				tmpSum += A[i][currCol];
				i++;
			}
			maxSum = max(maxSum , tmpSum);
		}
		cout<<maxSum<<endl;	
	}
	*/
	//cach 2 : Su dung y tuong cua tham lam , tinh tung buoc 1 , tai moi 1 buoc thi lay thang toi uu nhat 
		while(t--){
		int N, M;
		cin>>N>>M;
		
		int A[N][M];
		for(int i = 0 ; i < N ; i++)
			for(int j = 0 ; j < M; j++)
				cin>>A[i][j];
				
		int maxVl ;
		for(int i = 1 ; i < N ; i++){

			for(int j = 0 ; j < M ; j++){
				
				if(j == 0){
					A[i][j] += max(A[i][j] , A[i][j+1]);						
				}else if(j == M - 1){
					A[i][j] += max(A[i-1][j-1] , A[i-1][j]);
				}else{
					A[i][j] += max(A[i-1][j-1] ,max(A[i-1][j], A[i-1][j+1]));
				}
			}
		}
		maxVl = *max_element(A[N-1] , A[N-1] + M);
		cout<<maxVl<<endl;
	}
	

	return 0;
}
