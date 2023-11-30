#include<iostream>
using namespace std;

#define MAX 500
int Matrix[MAX][MAX] ;
int n , m;

void input(){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin>>Matrix[i][j];
}
///su dung cau truc du lieu stack 
void solve(){
	

}

int main(){
/*
Input 
4 5
0 1 1 0 
1 1 1 1
1 1 1 1 
1 1 1 0
			 
Output 
1 1 1 1
1 1 1 1
*/

	input();
	solve();
	
	return 0;
}
