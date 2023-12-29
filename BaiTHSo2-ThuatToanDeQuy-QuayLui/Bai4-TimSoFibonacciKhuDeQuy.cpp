#include<iostream>
using namespace std;

int ResultFibonacci(int n){
	int f1 = 1, f2 = 1, fn = 0;
	for(int i = 2 ; i <= n ; i++){
		fn = f1+f2;
		f2 = f1;
		f1 = fn;
	}	
	return fn;
}
int main(){
	
	int n = 5;
	cout<<"F("<<n<<") = "<<ResultFibonacci(n)<<endl;
	
	return 0;
} 
