#include<iostream>
#include <climits>
using namespace std;
#define MAXN 100

void input(int Matrix[][MAXN] , int N){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++)
			cin>>Matrix[i][j];
	}
}
void solve(int tc , int Matrix[][MAXN] , int N , int M , int K){
	int minTc = INT_MAX;
	int h = 0 , c = 0 , tempSum = 0;
	for(int i = 0 ; i <= N - M; i++){
		for(int j = 0 ; j <= N - M ; j++){
			int sumMatrix = 0;
			for(int t = i ; t < M + i ; t++){
				for(int v = j ; v < M + j ; v++){
					sumMatrix+=Matrix[t][v];
				}	
			}	
			//tong gan voi sum co nghia la k - tong nay hoac tong nay tru k phai nho nhat 
			int minusKSum = K > sumMatrix ? K - sumMatrix : sumMatrix - K;
			//in ra so gan voi K nhat 
			if(minusKSum < minTc){
				tempSum = sumMatrix;
				minTc = minusKSum;
				h = i , c = j;
			}else if(minusKSum == minTc){
				if(sumMatrix < tempSum){
					h = i , c = j;
					tempSum = sumMatrix;
				}else{
					if((i < h) || (i == h && j < c)){
						h = i , c = j;
					}
				}
			}
		}
	}
	cout<<"#"<<tc<<" "<<h<<" "<<c<<endl;
}
int main()
{
	
	int tc;
	cin>>tc;
	for(int i = 1 ; i <= tc ; i++){
		int N , M , K;
		cin>>N>>M>>K;
		int Matrix[N][MAXN];
		input(Matrix, N);
		solve(i , Matrix , N , M , K);	
	}
	return 0;
}

