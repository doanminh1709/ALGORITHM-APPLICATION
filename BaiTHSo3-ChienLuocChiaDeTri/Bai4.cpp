#include<bits/stdc++.h>
using namespace std;
//Tim a^n
//Chia ra 2 th 
//n chan = a^(n/2) * a^(n/2)
double resultPow(double a , int n){
	//th suy bien neu n == 1
	if(n == 1) return a;
	
	double t = resultPow(a , n /2);
	//Th neu n chan 
	if(n % 2 == 0) 
		return t*t;
	else 
		return t*t*a; 
}

int main()
{
	cout<<resultPow(3.2 , 2);
	return 0;
}
