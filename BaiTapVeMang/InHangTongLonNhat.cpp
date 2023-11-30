#include<iostream>
#include<vector>
using namespace std;

int main()
{
	
	int N , M;
	cin>>N>>M;
	int Matrix[N][M];
	
	long long ans = INT_MIN;
	vector<int>row;//luu tat ca cac hang co tong lon nhat 
	for(int i = 0 ; i < N ; i++){
		long long sum = 0;
		for(int j = 0 ; j < M ; j++){
			cin>>Matrix[i][j];
			sum+=Matrix[i][j];
		}
		if(sum > ans){
			ans = sum;
			row.clear();
			row.push_back(i);
		}else if(sum == ans){
			row.push_back(i);
		}
	}
	//in ra hang 
	cout<<ans<<endl;
	for(int x : row){
		cout<<x+1<<endl;
	}
	
	return 0;
}
