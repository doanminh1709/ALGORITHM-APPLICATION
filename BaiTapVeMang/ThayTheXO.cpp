#include<iostream>
using namespace std;

#define MAX 20

int dx[4] = {-1 , 0 , 1 , 0};
int dy[4] = {0 , 1 , 0 , -1};
int N , M;
char MXO[MAX][MAX];

void dfs(int i , int j){
	MXO[i][j] = '*';
	
	for(int k = 0 ; k < 4 ; k++){
		int x = dx[k] + i;
		int y = dy[k] + j;
		if(x >= 0 && x < N && y >= 0 && y < M && MXO[x][y] == 'O'){
			dfs(x , y);
		}
	}
}
//TUONG TUONG : Xet cac o bien , vi cac o nay se khong duoc loang 
void solve(){
	cin>>N>>M;
	cin.ignore();
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M; j++){
			cin>>MXO[i][j];
		}
	}
	
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			if(i == 0 || i == N - 1 || j == 0 || j == M - 1){
				if(MXO[i][j] == 'O'){
					dfs(i , j);	
				}
			}
		}
	}
	
	cout<<endl;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M; j++){
			if(MXO[i][j] == 'O'){
				MXO[i][j] = 'X';
			}
			else if(MXO[i][j] == '*'){
				MXO[i][j] = 'O';
			}
			cout<<MXO[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	
/*
De bai : Thay the mien bao quanh ki tu O bang ki tu X . Mot mien cac ki tu O bi bao quanh boi cac ki tu X 
neu ki tu X xuat hien o tren tren , ben trai va ben phai  
Input 
5 4 
X X X X 
X O X X 
X O O X 
X O X X 
X X O O 

Output
X X X X
X X X X
X X X X
X X X X 
X X O O 

*/
	//doc da 
	//freopen("input.txt", "r" , stdin);
	//freopen("output.txt", "w" , stdin);
	
	solve();
	return 0;
 } 
