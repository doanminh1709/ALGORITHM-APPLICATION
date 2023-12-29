#include<iostream>
using namespace std;

int res[1000];

int TinhSoFibonacciN(int n){
	if(n == 0 || n == 1){
		res[0] = res[1] = 1;
		return res[n];
	}else{
		res[n-1] = TinhSoFibonacciN(n - 1);
		res[n-2] = TinhSoFibonacciN(n - 2);
	return res[n-1] + res[n-2];
	}
}

int main(){
	int n = 20;
	cout<<TinhSoFibonacciN(n)<<endl;
	return 0;
}
