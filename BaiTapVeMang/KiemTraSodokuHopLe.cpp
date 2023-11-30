#include<iostream>
#include <set>
#define M 9
using namespace std;

bool checkInRow(char MatrixSoduku[M][M]){
	for(int i = 0 ; i < M ; i++){
		int cnt = 0;
		int F[9];
		set<int> s;
		for(int j = 0 ; j < M ; j++){
			if(MatrixSoduku[i][j] != '.'){
				int t = MatrixSoduku[i][j] - '0';
				F[cnt++] = t;
				s.insert(t);
			}			
		}
		if(s.size() != cnt) return false;
	}
	return true;
}


bool checkInCol(char MatrixSoduku[M][M]){
	for(int i = 0 ; i < M ; i++){
		int cnt = 0;
		int F[9];
		set<int> s;
		for(int j = 0 ; j < M ; j++){
			if(MatrixSoduku[j][i] != '.'){
				int t = MatrixSoduku[j][i] - '0';
				F[cnt++] = t;
				s.insert(t);
			}			
		}
		if(s.size() != cnt) return false;
	}
	return true;
}
bool checkArray3x3(char MatrixSoduku[M][M]){
	// Traverse each block of
    // size 3 * 3 in board[][] array
    for (int i = 0; i < M - 2; i += 3) {
        // j stores first column of
        // each 3 * 3 block
        for (int j = 0; j < M - 2; j += 3) {
 			int cnt = 0;
			int F[9];
			set<int> s;

            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
 
                    int X = i + k;
                    int Y = j + l;

                    if(MatrixSoduku[X][Y] != '.'){
                        int Z = MatrixSoduku[X][Y] - '0';	
                    	F[cnt++] = Z;
                    	s.insert(Z);
					}
                }
            }
        	if(s.size() != cnt) return false;
        }
    }
 	return true;
}
void input(char MatrixSoduku[M][M]){
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < M ; j++){
			cin>>MatrixSoduku[i][j];
		}
	}
}
int main()
{
	
	/*
6..17..2.
..6......
.........
..1......
.67.....9
......81.
.3......7
.....7...
...5...7.

	*/
	//check in row 
	
	int t , cnt = 1;
	cin>>t;
	while(t > 0){
		char MatrixSoduku[M][M];
		input(MatrixSoduku);
		fflush(stdin);		
		
		if(checkInRow(MatrixSoduku) 
		&& checkInCol(MatrixSoduku)
		&& checkArray3x3(MatrixSoduku)){
			
			cout<<"#"<<cnt<<" "<<"1"<<endl;
		}else{
			cout<<"#"<<cnt<<" "<<"0"<<endl;
		}
		
		cnt++;
		t--;
	}
	
	return 0;
}
