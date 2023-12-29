#include<iostream>
using namespace std;

void showConfig(int n , char str[]){
	for(int i = 0 ; i < n ; i++)
		cout<<str[i];
	cout<<endl;
}
void generate(int n){
	char str[n];
	for(int i = 0 ; i < n ; i++) str[i] = 'a';
	int i;
	do{
		showConfig(n , str);
		i = n - 1;
		
		while(i >= 0 && str[i] == 'b'){
			i--;
		}
		str[i] = 'b';
		if(i >= 0){
			for(int j = i + 1 ; j < n ; j++)
				str[j] = 'a';
		}
	}while(i >= 0);
}

int main(){
	
	generate(4);
	
	return 0;
}
