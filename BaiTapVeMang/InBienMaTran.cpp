#include<iostream>
using namespace std;

int main()
{
	
	int t;
	cin>>t;
	
	for(int i = 1 ; i <= t ; i++){
		
		int maxSubMatrix = -1e8;
		int  M , N , H , W;
		cin>>H>>W>>M>>N;
		
		int A[M][N];
		for(int i = 0 ; i < M ; i++){
			for(int j = 0 ; j < N ; j++){
				cin>>A[i][j];
			}
				
		}
		
		for(int i = 0 ; i <= M - H  ; i++){
			for(int j = 0 ; j <= N - W ; j++){
				int sum = 0;
				for(int t = i ; t < i + H ; t++){
					for(int k = j ; k < j + W ; k++){
						if(t == i || t == i + H - 1 || k == j || k == j + W - 1){
							if(A[t][k] % 2 == 0) sum+=A[t][k];
						}
					}
				}
				maxSubMatrix = maxSubMatrix < sum ? sum : maxSubMatrix;
			}
		}
		cout<<"#"<<i<<" "<<maxSubMatrix<<endl;		
	}
	
	return 0;
}
