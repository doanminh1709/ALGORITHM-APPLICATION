#include<iostream>
using namespace std;

int ResultFibonacci(int n){
	if(n == 0 || n == 1) return 1;
	else return ResultFibonacci(n - 1) + ResultFibonacci(n-2);
}
int main(){
	
	int n = 5;
	cout<<"F("<<n<<") = "<<ResultFibonacci(n)<<endl;
	
	return 0;
} 
