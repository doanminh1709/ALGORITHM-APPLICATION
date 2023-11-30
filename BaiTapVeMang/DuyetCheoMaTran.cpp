#include<iostream>
using namespace std;

int main(){
	
	int n = 5;
	int Matrix[n][n] = {{11 , 16 , 20 , 23 , 25}, 
						{7 , 12 , 17 , 21 , 24}, 
						{4 , 8 , 13 , 18 , 22}, 
						{2 , 5 , 9 , 14 , 19}, 
						{1 , 3 , 6 , 10 , 15}, };
	
	for(int i = n - 1 ; i >= 0 ; i --){
		int k = i;
		for(int j = 0 ; j < n - i ; j++){
			if(k < n){
				cout<<Matrix[k][j]<<"\t";
				k++;
			}
		}
		cout<<endl;
	}
		//tiep tuc duyet 
	for(int i = 0 ; i < n - 1 ; i++){
		int k = 0;
		for(int j = i + 1 ; j < n ; j++){
			if(k < n - i - 1){
				cout<<Matrix[k][j]<<"\t";
				k++;
			}
		}
		cout<<endl;
	}
		
	return 0;
}
