#include<iostream>
using namespace std;

//ky thuat kiem tra toa do 
int dx[8] = {-1 , -1 , -1 , 0 , 1 , 1 , 1 , 0};
int dy[8] = {-1 , 0 , 1   , 1 , 1 , 0 , -1 , -1};

int main(){
	
	int t;
	cin>>t;
	while(t--){
		
		int N , M;
		cin>>N>>M;
		
		int A[500][500];
		
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++)
				cin>>A[i][j];
		}
//Cach 1 : For trau 
//		int B[500][500];
//		for(int i = 0 ; i < N  ; i++){
//			for(int j = 0 ; j < M  ; j++){
//					int sum = 0;
//					for(int t = i - 1 ; t < i + 2 ; t++){
//						for(int k = j - 1 ; k < j + 2 ; k++){
//							if(t >= 0 && t < N && k >= 0 && k < N){
//								sum+=A[t][k];
//							}
//						}
//					}
//					B[i][j] = sum;
//				}
//			}		
//Cach 2 : Tao 1 cai mang moi luu lai su thay doi gom 8 phan tu tren toa do Ox va Oy 
		
		int C[500][500];
		for(int i = 0 ; i < N  ; i++){
			for(int j = 0 ; j < M  ; j++){
				int sum = A[i][j];
				for(int t = 0 ; t < 8 ; t++){
					int x = dx[t] + i; 
					int y = dy[t] + j;
					if(x >= 0 && x < N && y >= 0 && y < M){
						sum+=A[x][y];
					}
				}
				C[i][j] = sum;
			}
		}
		
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++){
//				cout<<B[i][j]<<" ";
				cout<<C[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
} 
