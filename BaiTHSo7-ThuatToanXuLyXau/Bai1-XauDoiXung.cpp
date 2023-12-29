#include<bits/stdc++.h>
using namespace std;

bool checkXauDx(string s){
	int n = s.length();
	for(int i = 0 ; i < n/2 ; i++){
		if(s[i] != s[n-1-i]) return false;
	}
	return true;
}

int main(){
	
	string s = "hemoomem";
	
	if(!checkXauDx(s)){
		int n = s.length();
		int k;
		cin>>k;
		int first_index , last_index;
		
		int i = 1;
		while(k + i  < n && k - i >= 0){
			if(s[k-i+1] == s[k+i]){
				first_index = k - i + 1;
				last_index = k + i;
				i++;
			}else{
				break;
			}
		}
		for(int i = first_index ; i <= last_index ; i++)
			cout<<s[i];
	}else{
		cout<<"s la xau doi xung"<<endl;
	}
	return 0;
}
