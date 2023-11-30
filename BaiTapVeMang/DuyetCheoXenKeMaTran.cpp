#include<iostream>
using namespace std;

int main(){
	
	int n = 5;
	int Matrix[n][n] = {{11 , 19 , 20 , 24 , 25}, 
						{10 , 12 , 18 , 21 , 23}, 
						{4 , 9 , 13 , 17 , 22}, 
						{3 , 5 , 8 , 14, 16}, 
						{1 , 2 , 6 , 7 , 15}};
	
	//duyet tam giac vuong ben trai 
	for(int i = n - 1 ; i >= 0 ; i--){
		
		//i chan thi duyet cheo xuong 
		if(i % 2 == 0){
		int k = i;
		for(int j = 0 ; j < n - i ; j++){
			if(k < n){
				cout<<Matrix[k][j]<<" ";
				k++;
			}
		}
		cout<<endl;	
		}
		//i le thi duyet cheo len 
		else{
			int k = n - 1;
			for(int j = n - i - 1 ; j >= 0 ; j--){
			if(k >= i){
				cout<<Matrix[k][j]<<" ";
				k--;
			}
		}
		cout<<endl;
		}
	}
	
	//duyet tam giac vuong ben phai 
	for(int i = n - 1 ; i >= 0 ; i --){
		if((i-1) % 2 == 1){
		int k = i - 1;
		for(int j = n - 1 ; j >= n - i; j--){
			if(k >= 0){
				cout<<Matrix[k][j]<<" ";
				k--;
				}
			}
		cout<<endl;
		}else{
			int k = 0;
			for(int j = n - i ; j < n ; j++){
				if(k <= i-1){
				cout<<Matrix[k][j]<<" ";
				k++;
			}
		}
		cout<<endl;
	}
}	
	return 0;
}
