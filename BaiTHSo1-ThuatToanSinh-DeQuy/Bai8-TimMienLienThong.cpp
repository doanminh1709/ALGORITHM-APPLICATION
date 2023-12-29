#include<iostream>
using namespace std;

bool flag[100][100]={false};
				   
int O[100][100] = {{1 , 1 , 0 , 0 , 0 , 1} ,
				   {1 , 0 , 0 , 0 , 0 , 0} ,
				   {1 , 0 , 0 , 1 , 1 , 0} ,
				   {0 , 1 , 1 , 0 , 0 , 1} ,
				   {0 , 0 , 1 , 0 , 1 , 1}};


void loang(int &cnt , int &i , int &j){
	flag[i][j] = true;
	//loang o ben trai 
	if(j > 0){
		if((O[i][j - 1] == O[i][j]) && (!flag[i][j-1])) {
			 j--;
			 loang(cnt , i , j );cnt=cnt+1;
		}
	}
	//loang o ben tren 
	if(i > 0){
		if((O[i-1][j] == O[i][j]) && (!flag[i-1][j])){
			i--;
			loang(cnt , i , j);	cnt=cnt+1; 
		} 
	}
	//loang o ben phai 
	if(j < 5){
		if((O[i][j+1] == O[i][j]) && (!flag[i][j+1])){
			j++;
		 	loang(cnt , i , j ); cnt=cnt+1;
		}
	}
	//loang o ben duoi 
	if(i < 4){
		if((O[i+1][j] == O[i][j]) && (!flag[i+1][j])){
			i++;
		 	loang(cnt , i , j); cnt=cnt+1; 	
		} 
	}
} 

int main(){
	
	int cnt = 0 , i = 2, j = 2;
	loang(cnt , i , j);
	cout<<"So mien lien thong : "<<cnt<<endl;
	
	return 0;
}
