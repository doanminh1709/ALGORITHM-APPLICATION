#include<iostream>
using namespace std;

void init(int N , int M[101][101]){
	 for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            M[i][j] = 0;
        }
    }
}
void show(int N , int M[101][101]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool checkCondition(int N , int next_u , int next_v){
	return (next_u >= 0 && next_u < N && next_v  >= 0 && next_v < N); 
}

void Try(int i , int N, int M[101][101],int*X , int*Y, int u , int v , bool &check){

    int next_u , next_v;
    for(int j = 0 ; j < 8 ; j++){
    	
    	next_u  = u + X[j];
    	next_v =  v + Y[j];

    if(M[next_u][next_v] == 0 && checkCondition(N, next_u, next_v)){
    	
   		M[next_u][next_v] = i+1;
    	if(i == N*N - 1) {
        	check = true;
        	return;
    	}else{
        	Try(i+1 ,N, M, X , Y, next_u , next_v , check);
    		if(!check){ M[next_u][next_v] = 0;	} 
        	} 
    	}
	}
}
int main()
{
	int X[8] = {1 , 1 , -1 , -1, 2 , -2,  2 , -2 };
	int Y[8] = {2 ,-2 , -2 ,  2, 1 ,  1, -1 , -1 };
    int N = 7;
   	int u = 2 , v = 0;
	bool check = false;
	int M[101][101];
	init(N , M);
	M[u][v] = 1;
		
    Try(1, N , M , X , Y, u , v , check);
    
	if(check){
    	show(N, M);
    }else{
        cout<<"Khong co loi giai";
    }

    return 0;
}
