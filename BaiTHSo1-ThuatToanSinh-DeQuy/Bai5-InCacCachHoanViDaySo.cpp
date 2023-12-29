#include<iostream>
using namespace std;

void showConfig(string svs[] , int cnt[] , int k){
	for(int i = 0 ; i < k ; i++){
		cout<<svs[cnt[i]-1]<<" ";
	}
	cout<<endl;
}
void generateConfig(string svs[], int n , int k){
	
	int cnt[k];
	for(int i = 0 ; i < k ; i++) cnt[i] = i+1;
	int i;
	do{
		showConfig(svs , cnt , k);
		
		i = k-1;	
		while(i >= 0 && cnt[i] == n - k + i + 1){
			i--;
		}
		cnt[i]++;
		if(i >= 0){
			for(int j = i + 1 ; j < n ; j++){
				cnt[j] = cnt[j-1] + 1;
			}
		}
	}while(i >= 0);
}
int main(){
	
	int n = 6 , k = 4;
	string svs[n] = {"Trang" , "Cong" , "Trung" , "Binh" , "Hoan" , "Mai"};
	generateConfig(svs , n , k);
	
	return 0;
}
