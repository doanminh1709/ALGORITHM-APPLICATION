#include<iostream>
using namespace std;

int main()
{
	int n = 5;
	int Matrix[n][n] = {{15 , 19 , 22 , 24 , 25}, 
					{10 , 14 , 18 , 21 , 23}, 
					{6 , 9 , 13 , 17 , 20}, 
					{3 , 5 , 8 , 12, 16}, 
					{1 , 2 , 4 , 7 , 11}};
	
	for(int i = n - 1 ; i >= 0 ; i--){
		int k = n - 1;
		for(int j = n - i - 1 ; j >= 0 ; j--){
			if(k >= i){
				cout<<Matrix[k][j]<<" ";
				k--;
			}
		}
		cout<<endl;
	}
	
	for(int i = n - 2 ; i >= 0 ; i--){
		int k = i;
		for(int j = n - 1 ; j >= n - i - 1; j--){
			if(k >= 0){
				cout<<Matrix[k][j]<<" ";
				k--;
			}
		}
		cout<<endl;
	}
	return 0;
}
