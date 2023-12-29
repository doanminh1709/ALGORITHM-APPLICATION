#include<bits/stdc++.h>
using namespace std;

int m , n;
int F[100][100];

struct Packet{
	int weight;
	int value;
};
void Init(Packet mct[]){
	mct[0] = {2 , 3}; 
	mct[1] = {1 , 7}; 
	mct[2] = {4 , 5}; 
	mct[3] = {3 , 8}; 
	mct[4] = {9 , 4};	
	mct[5] = {1 , 6}; 			
}
int findValue(Packet mct[]){
	int i , j;
	
	for(i = 0 ; i <= n; i++){
		for( j = 0; j <= m ; j++){
			//Khoi tao gia tri tai cot 0 hang 0 bang 0 	
				if(i == 0 || j == 0){
					F[i][j] = 0;
				}else if(mct[i-1].weight <= j ){
					F[i][j] = max(F[i-1][j] , mct[i-1].value + F[i-1][j-mct[i-1].weight]);
				}else{
					F[i][j] = F[i-1][j];
				}
			}
		}

		for(i = 0 ; i <= n; i++){
			for(int j = 0; j <= m ; j++){
				cout<<F[i][j]<<" ";	
			}
			cout<<endl;
		}
	
	return F[n][m];
}
void Title(){
	cout<<left<<setw(10)<<"Goi"
		<<setw(16)<<"Weight"
		<<setw(16)<<"Value"<<endl;
}
void TruyVet(Packet mct[]){
	int i = n;
	int j = m;
	int k = 0;
	int cnt[100] = {0};
	while (i != 0){
		if (F[i][j] != F[i-1][j]) {
			cnt[k++] = i;
			j = j - mct[i-1].weight; //Lay goi thu i
		}
		i--;
	}
	
	Title();	
	for(int i = k ; i >= 0  ; i--){
		if(cnt[i] !=0){
		cout<<left<<setw(10)<<cnt[i]
		<<setw(16)<<mct[cnt[i]-1].weight
		<<setw(16)<<mct[cnt[i]-1].value
		<<endl;
		}
	}
	
}
		
int main(){
	
	n =  6, m = 11;
	Packet mct[n];
	Init(mct);
	
	cout<<"Max value : "<<findValue(mct)<<endl;
	TruyVet(mct);
	return 0;
}
