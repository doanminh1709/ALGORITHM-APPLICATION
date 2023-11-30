#include<iostream>
using namespace std;
#define MAX 100

int Matrix[MAX][MAX];
int n , m;

void Input(){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>Matrix[i][j];
		}
	}
}
void Solve(){
	
	int h1 = 0 , h2 = n - 1 , c1 = 0 , c2 = m - 1;
		
	while(h1 < h2 && c1 < c2){
		int pre = Matrix[h1+1][c1];
		//duyet hang dau 
		for(int i = c1 ; i <= c2 ; i++){
			int curr = Matrix[h1][i];
			Matrix[h1][i] = pre;
			pre = curr;
		}		
		h1++;//sau khi duyet xong hang dau 

		//duyet tiep tu tren xuong duoi 
		for(int i = h1 ; i <= h2 ; i++){
			int curr = Matrix[i][c2];
			Matrix[i][c2] = pre;
			pre = curr;
		}
		c2--;
		//duyet hang cuoi 
		if(c1 <= c2){
		for(int i = c2 ; i >= c1 ; i--){
			int curr = Matrix[h2][i];
			Matrix[h2][i] = pre;
			pre = curr;	
		}
		h2--;
	}
	//duyet tu duoi len tren 
	if(h1 <= h2){
		for(int i = h2 ; i >= h1 ; i--){
			int curr = Matrix[i][c1];
			Matrix[i][c1] = pre;
			pre = curr;				
		}
		c1++;
		}		
	}
	cout<<endl;
}
void Output(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout<<Matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
//xoay ma tran k lan 
//	freopen("input.txt", "r" , stdin);
//	freopen("output.txt", "w" , stdin);

	Input();
	
	int k;
	cin>>k;
	
	for(int i = 1; i <= k ; i++){
		Solve();	
	}
	Output();
	
	return 0;
 } 
