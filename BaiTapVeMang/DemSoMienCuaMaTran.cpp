#include<iostream>
using namespace std;

#define MAX 101

int Matrix[MAX][MAX];
int n , m;
int dx[8]= {-1 , -1 , -1 , 0 , 1 , 1 , 1 , 0};
int dy[8]= {-1 , 0 , 1 , 1 , 1 , 0 , -1 , -1}; 

void input(){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			cin>>Matrix[i][j];
}
//tu tuong , duyet tat ca kha nang cua 1 diem voi tat ca trong cung mien voi no 
void dfs(int i , int j){
	Matrix[i][j] = 0;
	
	for(int k = 0 ; k < 8 ; k++){
		int x = dx[k] + i;
		int y = dy[k] + j;
		
		//kiem tra dieu kien bien va gia tri cua phan tu tai vi tri moi x , y khong phai vi tri i , j 
		if(x >= 0 && x < n && y >= 0 && y < m && Matrix[x][y] == 1){
			dfs(x , y);//goi de quy de duyet tat ca cac diem lien quan 
		}	
	}
}

void solve(){
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(Matrix[i][j] == 1){
								++cnt;
				dfs(i , j);
			}
		}
	}
	cout<<cnt<<endl;
}


int main(){
/*
Test:  
5 5
0 1 1 0 1
1 1 0 0 1
0 0 0 0 1
1 1 1 0 0
1 1 1 1 1

Output : 3
*/
	input();
	solve();
		
	return 0;
 } 
