#include<iostream>
#include<string.h>
using namespace std;
#define MAX 1000


bool checkDoiXung(char str[] , int l , int r){
	
	//check moi chuoi con co the sinh ra tu vi tri j -> i , la moi ki tu o ben trai se bang moi ki tu o ben phai 
	int j = 0;
	for(int i = l ; i <= r ; i++){
		if(str[l+j] != str[r-j]) return false; 
		j++;
	}
	return true;
} 
int count(char S[] , int l , int r){

	int maxLength = INT_MIN , t;
	//bat dau tu dau ve cuoi 
	for(int i = 0 ; i <= r ; i++){
		//bat dau tu vi tri thu i duyet ve den cuoi 
		for(int j = i ; j <= r  ; j++){
			if(checkDoiXung(S , i , j)) {
				maxLength = (j - i) < maxLength ? maxLength : (j-i+1);	
			}
		}
	}
	return maxLength;
}

int main(){
	
	int t;
	cin>>t;
	cin.ignore();
	for(int i = 1 ; i <= t ; i++){
	char S[MAX];
	cin.getline(S , MAX);
	
	int ls = strlen(S);
	cout<<"#"<<i<<" "<<count(S , 0 , ls-1)<<endl;		
}

	return 0;
}
