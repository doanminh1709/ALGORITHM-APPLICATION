#include<iostream>
using namespace std;
#define NMAX 100

int n;
void input(int Matrix[][NMAX]){

	for(int i = 0; i < n; i++)
		for(int j = 0 ; j < n ; j++)
			cin>>Matrix[i][j];
}
bool findRoad(int start , int Matrix[][NMAX]){
	
	int currentCol = start;
	int currentRow = 0;
	
	while(currentCol < n && currentRow < n){
		
		bool checkRight = false, checkLeft = false, checkDown = false;
		
		int k1 = 1;
		while(currentCol + k1 < n && Matrix[currentRow][currentCol + k1] != 0){
			if(Matrix[currentRow][currentCol + k1]  == 2){
				return true;
			}
			k1++;
			checkRight = true;
		}
		if(checkRight) currentCol = currentCol + k1 - 1;
		
		int k3 = 1;
		while(currentRow + k3 < n && Matrix[currentRow + k3][currentCol] != 0){
			if(Matrix[currentRow+k3][currentCol] == 2){
				return true;
			}
			k3++;
			checkDown = true;
		}
		if(checkDown) currentRow = currentRow + k3 - 1;
		
		int k2 = 1;
		while(currentCol - k2 >= 0 && Matrix[currentRow][currentCol - k2] != 0){
			if(Matrix[currentRow][currentCol - k2] == 2){
				return true;
			}
			k2++;
			checkLeft = true;
		}
		if(checkLeft) currentCol = currentCol - k2 - 1;
		
		if(!checkLeft && !checkRight && !checkDown){
			return false;
		}
	}
	return false;
}
void solve(int tc , int Matrix[][NMAX]){
	
	int validIndex = 0;
	
	for(int i = 0 ; i < n ; i++){
		if(Matrix[0][i] != 0){
			if(findRoad(i , Matrix)){
			validIndex = i;
			break;	
			}
		} 
	}
	cout<<"#"<<tc<<" "<<validIndex<<endl;
}

int main()
{
	for(int i = 1 ; i <= 10; i++){
		
		int tc; 
		cin>>tc;
		cin>>n;
				
		int Matrix[n][NMAX];
		input(Matrix);
		solve(i , Matrix);
	}
	
	return 0;	
}
