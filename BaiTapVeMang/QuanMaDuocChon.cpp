#include<iostream>
using namespace std;
#define MAXN 1000

int U[8] = {2 , 2 , -2 , -2 , 1 , 1 , -1 , -1};
int V[8] = {1 , -1 , 1 , -1, 2 , -2 , -2 , 2 };

void Mark(int N , char Chess[][MAXN] , int K , int Kight[],
		  int M , int Remaining[] , int D, int PZ[]){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			Chess[i][j] = 'E';
		}
	}
	
	for(int i = 0 ; i < K*2 ; i+=2){
		Chess[Kight[i]][Kight[i+1]] = 'K';
	}
	for(int i = 0 ; i < M*2 ; i+=2){
		Chess[Remaining[i]][Remaining[i+1]] = 'P';
	}
	for(int i = 0 ; i < D*2 ; i+=2){
			Chess[PZ[i]][PZ[i+1]] = 'N';
	}
}
int countKightKill(int i , int j , int N , char Chess[][MAXN]){
	
	int count = 0;						
	for(int t = 0 ; t < 8 ; t++){
		int x = i + U[t];
		int y = j + V[t];
						
		if((x >= 0 && x < N) && (y >= 0 && y < N) && Chess[x][y] == 'P'){
				count++;
			}
		}
	return count;
}
void Solve(int tc , int K , int Kight[] , int N , char Chess[][MAXN]){
	
	int maxKightKill = 0;
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(Chess[i][j] == 'K'){
				int ckk = countKightKill(i , j , N , Chess);
				if(maxKightKill < ckk){
					maxKightKill = ckk;
				}
			}
		}
	}
	
	for(int i = 0 ; i < K*2 ; i+=2){
		int count = countKightKill(Kight[i] , Kight[i+1], N , Chess);
		if(count == maxKightKill){
			cout<<"#"<<tc<<" "<<Kight[i]<<" "<<Kight[i+1]<<" "<<maxKightKill<<endl;
			return;
		}
	}	
}			

int main()
{
	int tc;
	cin>>tc;
	for(int i = 1 ; i <= tc ; i++){
		int N , K , M , D;
		cin>>N>>K>>M>>D;
		
		char Chess[N][MAXN];
		int Kight[K*2];
		int Remaining[M*2];
		int ProhibitedZone[D*2];
		
		for(int i = 0 ; i < K*2 ; i++){
			cin>>Kight[i];
		}
		
		for(int i = 0 ; i < M*2 ; i++){
			cin>>Remaining[i];
		}
		
		for(int i = 0 ; i < D*2 ; i++){
			cin>>ProhibitedZone[i];
		}
		
		Mark(N ,Chess ,K ,Kight ,M ,Remaining ,D ,ProhibitedZone);
		Solve(i ,K ,Kight, N, Chess);	
	}
	return 0;	
}
