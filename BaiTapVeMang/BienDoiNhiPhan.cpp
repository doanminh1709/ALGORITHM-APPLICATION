#include<iostream>
using namespace std;

int main(){

	int t; cin>>t;
	while(t--){
	

	int N, M;
	cin>>N>>M;
	
	int A[N][M];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M; j++){
			cin>>A[i][j];
		}
	}
	
	int B[N][M] = {0};
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			if(A[i][j] == 1){
				for(int t = 0 ; t < N ; t++){
					B[t][j] = 1;
				}
				for(int k = 0 ; k < M ; k++){
					B[i][k] = 1;
				}
			}
		}
	}
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cout<<B[i][j]<<" ";		
		}
		cout<<endl;
	}
	
}
	return 0;
 } 
