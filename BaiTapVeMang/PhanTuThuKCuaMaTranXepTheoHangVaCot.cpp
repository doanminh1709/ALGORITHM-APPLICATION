#include<bits/stdc++.h>
using namespace std;

int t , n , k , A[1000001];

void input(){
	cin>>n>>k;
	for(int i = 0 ; i < n*n ; i++)
		cin>>A[i];
}
void output(){
	//sort 
	n*=n;
	sort(A , A + n);
	k--;
	cout<<A[k]<<endl;
}
int main(){
	
	cin>>t;
	while(t--){
		input();
		output();
	}
	return 0;
 } 
