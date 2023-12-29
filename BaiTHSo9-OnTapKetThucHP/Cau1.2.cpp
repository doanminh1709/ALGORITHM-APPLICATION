#include<bits/stdc++.h>
using namespace std;

int sumOfOddNumber(int*A , int sum , int n){
	if(n > -1){
		if(A[n-1] % 2 != 0){
			sum = A[n-1];
		}else{
			sum = 0;	
		} 
		return sum + sumOfOddNumber(A , sum, n-1);
	}else return 0;
}
int main(){
	int n = 5;
	int A[n] = {2 , 4 , 5 , 1 , 6};
	cout<<sumOfOddNumber(A , 0 , n)<<endl;
	
	return 0;
}
