#include<iostream>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		
		int Matrix[N][N];
		for(int i = 0 ; i < N ; i++)
			for(int j = 0 ; j < N ; j++)
				cin>>Matrix[i][j];
		
		cout<<endl;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){

				if(i % 2 == 0){
					cout<<Matrix[i][j]<<" ";
				}else{
					cout<<Matrix[i][N - j- 1]<<" ";
				}
			}
			cout<<endl;
		}
	}	
	
		
	
	return 0;
} 
