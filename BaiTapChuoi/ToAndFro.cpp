#include<iostream>
using namespace std;


int main()
{
	
	int col;
	do{
		cin>>col;
		cin.ignore();
		if(col == 0) break;
		
		string str;
		getline(cin , str);
		
		int sl = str.length();
		int row = sl / col;
		
		//in ra theo ma tran hang cheo 
		char s[row][col];
		
		int cnt = 0;
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < col ; j++){
				if(i % 2 == 0){
					s[i][j] = str[cnt];
				}else{
					s[i][col - 1 - j] = str[cnt];;
				}
				cnt++;
			}
			if(cnt == row*col) break;
		}
		
		for(int i = 0 ; i < col ; i++){
			for(int j = 0 ; j < row  ; j++){
				cout<<s[j][i];
			}
		}
		cout<<endl;
	}while(true);
	
	return 0;
}
