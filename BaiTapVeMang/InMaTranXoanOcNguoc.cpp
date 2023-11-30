#include <iostream>
#include<vector>
using namespace std;

int main() {

    int N = 4;
    int A[16];
    for (int i = 0; i < 16; i++)
        cin >> A[i];

	vector<int>mt;
	
    int M[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            M[i][j] = 0;
            
    int h1 = 0, c1 = 0, h2 = N-1, c2=N-1;
    int cnt = 0;
	
	//1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
    
    while(h1 <= h2 && c1 <= c2){
    	
	//in ra tu trai sang phai 
	for(int i = c1 ; i <= c2 ; i++){
		M[h1][i] = A[cnt++];
		mt.push_back(M[h1][i]);
	}
	h1++;
	
	//in ra tu tren xuong duoi 
	for(int i = h1 ; i <= h2 ; i++){
		M[i][c2] = A[cnt++];
		mt.push_back(M[i][c2]);
	}
	c2--;
	
	
	//in ra tu phai sang trai 
	if(h1 <= h2){
		for(int i = c2 ; i >= c1 ; i--){
			M[h2][i] = A[cnt++];
			mt.push_back(M[h2][i]);
		}
		h2--;
	}
		
	//in ra tu duoi len tren 
	if(c1 <= c2){
		for(int i = h2 ; i >= h1 ; i--){
			M[i][c1] = A[cnt++];
			mt.push_back(M[i][c1]);
			}
		c1++;
		}
	}

	for(int i = mt.size() - 1 ; i >= 0 ; i--)
		cout<<mt[i]<<" ";

    return 0;
}

