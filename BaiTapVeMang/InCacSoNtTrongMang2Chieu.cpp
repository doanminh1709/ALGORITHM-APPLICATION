#include<iostream>
#include<map>
using namespace std;

bool CheckPrime(int n){
	for(int i = 2 ; i*i <= n ; i++)
		if(n % i == 0) return false;
	return n > 1;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int N, M;
		cin>>N>>M;
		int Matrix[N][M];
		for(int i = 0 ; i < N ; i++)
			for(int j = 0 ; j < M ; j++)
				cin>>Matrix[i][j];
				
		map<int,bool> mapNt;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++){
				if(CheckPrime(Matrix[i][j]) && !mapNt[Matrix[i][j]]){
					cout<<Matrix[i][j]<<" ";
					mapNt[Matrix[i][j]] = 1;
				}
			}
		}
	}
	return 0;
}
