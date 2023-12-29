#include<bits/stdc++.h>
using namespace std;

int greedAlgo(float*A , float C, int n){
	int cnt = 0;	
	float M = A[n-1];
	for(int i = n-1 ; i >= 0 ; i--){
		if(M <= C){
			M+=A[i];
			cnt++;
		}
	}
	return cnt;
}
bool boyerMooreHorspool(string P , string Q){
	
	int n = P.length();
	int v = Q.length();
	
	int i = v - 1;
	while(i < n){
		int j = v - 1;
		while(P[i] == Q[j] && j > -1){
			i--;
			j--;
		}
		if(j == -1) return true;
		else{
			//kiem tra xem tai cai vi tri khac day no co trong chuoi P hay khong 
			while(P[i] != Q[j] &&  j > -1){
				j--;
			}
			//neu vi tri day khong ton tai o trong mang P 
			if(j == -1) i = i + v;
			else i = i + v - j - 1;
		}
	}
	return false;
}
int main(){
	
	int n = 8;
	float A[n] = {3.3 , 4.1 , 5.4 , 6.6 , 9.3 , 11.2 , 13.4 , 14.1};
	
	float C = 14.2;
	cout<<greedAlgo(A , C , n)<<endl;
	string P = "hello tat ca cac ban da den voi chanel cua toi";
	string Q = "chanel";
	if(boyerMooreHorspool(P , Q)) cout<<"true";
	else cout<<"false"<<endl;
	
	return 0;
}
