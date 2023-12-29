#include<iostream>
using namespace std;

int ucln(int a , int b)
{
    if( a % b == 0) return b;
    else return ucln(b , a % b);
}
int main(){
	
	int a = 4 , b = 8;
	cout<<ucln(a , b)<<endl;
	
	return 0;
} 
