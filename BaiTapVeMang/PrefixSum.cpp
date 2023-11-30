#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

//normal array :2 3 8 6 4 1
//prefix sum : 2 5 13 19 23 24 (luu vao tu 1 -> n)
//prefix (l -> r = perfix_sum[r] - prefix[l - 1]


//prefix sum cho ma tran 2 chieu 
//prefix[i][j] : tong tat ca cac phan tu cua hcn bat dau tu hang 1 , ket thuc o hang i , bat dau tu cot 1 va ket thuc o cot j 
//==> prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + prefix[i][j]
/*
1 2 3 4 
5 6 7 8 
9 10 11 11 
13 14 15 16

voi prefix sum ta se co n + 1 hang va m + 1 cot 
pre[1][2] = pre[0][2] + pre[1][1] - pre[0][1] + pre[1][2]

0 0 0 0 0 
0 1 3  
0
0
0
*/
/*
void prefix_sum_matrix(int Matrix[][MAX] , int h1 , int c1 , int h2 , int c2){
	int Prefix[n+1][m+1] = {0};
//	memset(Prefix , 0 , sizeof(Prefix));
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			Prefix[i][j] = Prefix[i-1][j] + Prefix[i][j-1] - Prefix[i-1][j-1] + Matrix[i][j]; 
		}
	}
	
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++){
			cout<<Prefix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//Tinh tong cac gia tri tu h1 -> c1 va h2 -> c2
	int prefix_sum = Prefix[h2][c2] - Prefix[h1-1][c2] - Prefix[h2][c1-1] + Prefix[h1-1][c1-1];
	cout<<prefix_sum<<endl;
} 
*/
int main()
{
	/*
	int n;
	cin>>n;
	int A[n+1];
	for(int i = 1 ; i <= n ; i++)
		cin>>A[i];
		
	int prefix[n+1] = {0};
	
	//tinh khoang tong truy van tren doan tu l - > r 
	
	for(int i = 1 ; i <= n ; i++)
		prefix[i] = prefix[i - 1] + A[i];
		
	int q;
	cin>>q;
	while(q--){
		int l , r;
		cin>>l>>r;
		
		cout<<prefix[r] - prefix[l - 1]<<endl;
	}
	*/
	int n , m;
	cin>>n>>m;
	
	int Matrix[n][MAX];
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>Matrix[i][j];
		}
	}
	
	int Prefix[n+1][m+1];
	memset(Prefix , 0 , sizeof(Prefix));
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			Prefix[i][j] = Prefix[i-1][j] + Prefix[i][j-1] - Prefix[i-1][j-1] + Matrix[i-1][j-1]; 
		}
	}
	
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= m ; j++){
			cout<<Prefix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	int q;
	cin>>q;
	while(q --){
		int h1 , c1 , h2, c2;
		cin>>h1>>c1>>h2>>c2;
		
		prefix_sum_matrix(Matrix , h1 , c1 , h2 , c2);	
	}
	
	return 0;
}
