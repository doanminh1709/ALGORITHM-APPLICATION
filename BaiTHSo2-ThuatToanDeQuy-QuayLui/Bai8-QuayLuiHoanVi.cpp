#include<bits/stdc++.h>
using namespace std;

int N , X[100] , used[100]={0};


void show(){
	
	for(int i = 1 ; i <= N ; i++){
		cout<<X[i]<<" ";
	}
	cout<<endl;
}
void Try(int i , int &cnt){
	//duyet tat ca cac kha nang ma X[i] co the nhan duoc 
	for(int j = 1 ; j <= N; j++){
		//Xet xem lieu rang co the gan X[i] bang j hay khong 
		if(used[j] == 0){
			X[i] = j;
			used[j] = 1;
			if(i == N){
				show();
				cnt++;
			}else{
				Try(i+1 , cnt );
			}
			//backtrack 
			used[j] = 0;
		}
	}
}
int main(){
	
	N = 4;
	int cnt = 0;
	Try(1 , cnt );
	
	cout<<cnt<<endl;
	return 0;
}
