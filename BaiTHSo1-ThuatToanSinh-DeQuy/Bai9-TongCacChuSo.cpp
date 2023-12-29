#include<bits/stdc++.h>
using namespace std;

int TongCacChuSoTrongSo(int n){
	int sum = 0;
	if(n == 0) return sum;
	sum = n % 10;
	return sum + sumOfCharacterNumber(n / 10);
}

int main(){
	
	int n = 12345;
	cout<<sumOfCharacterNumber(n)<<endl;
	return 0;
} 
