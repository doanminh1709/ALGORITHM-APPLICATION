#include<iostream>
using namespace std;

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
				
		int max_value = INT_MIN;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++)
				max_value = max(max_value , Matrix[i][j]);
		}
		
		cout<<max_value<<endl;
		//in ra vi tri 
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++){
				if(Matrix[i][j] == max_value){
					cout<<"A["<<i+1<<"]["<<j+1<<"]"<<endl;
				}
			}
		}
				
	}
}
