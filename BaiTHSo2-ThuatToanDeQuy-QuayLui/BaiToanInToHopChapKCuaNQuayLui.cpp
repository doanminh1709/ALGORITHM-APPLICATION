#include<bits/stdc++.h>
using namespace std;

int N , X[100] , K;

void show(){
	for(int i = 1 ; i <= K ; i++){
		cout<<X[i];
	}
	cout<<endl;
}
//i lon nhat: N - K + i
//i nho nhat: X[i-1] + 1
//i = 1 : X[0] + 1 = 0 + 1 = 1
void Try(int i){
	//Duyet tat ca kha nang ma X[i] co the nhan duoc thi doi voi bai toan to hop chap K 
	//thi gia tri lon nhat co the nhan la gioi han duoi cua no : N - K + i va gia tri nho
	// nhat phai la gioi han tren X[i-1] + 1
	for(int j = X[i-1] + 1 ; j <= N - K + i ; j++){
		X[i] = j;
		if(i == K){
			show();
		}else{
			Try(i+1);
		}
	}	
}
int main(){
	
	cin>>N>>K;
	X[0] = 0;
	Try(1);
	
	return 0;
}
