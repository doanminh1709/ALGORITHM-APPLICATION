#include<iostream>
using namespace std;

int main(){
	
	string m ="323942432332323", n="4232323424424233";
	
	int i = m.length() , j = n.length();
	
	int str[200] = {0};
	int t = 200;
	while(i >= 0 || j >= 0){
		
		int item1 = m[i-1] - '\0';
		int item2 = n[j-1] - '\0';
		
		int tmp = (item1+item2)%10;
		str[t] = tmp;
		
		
		
	}
	return 0;
}
