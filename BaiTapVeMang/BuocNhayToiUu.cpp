#include<iostream>
using namespace std;

#define K 8
#define MIN 1e6

int U[8] = {1 , -1 , 0 ,  0 , -1 , -1 , 1 ,  1 };
int V[8] = {0 ,  0 , 1 , -1 ,  1 , -1 , 1 , -1};

int countingJump(int F[][100] , int N , int x , int y){

	int count = 0;	
	for(int t = 0 ; t < N ; t++){
		for(int j = 0 ; j < N ; j++){
			bool check = false;
			int min = MIN;
			int ddx , ddy;
			for(int i = 0 ; i < K ; i++){
				int item1 = x + U[i];
				int item2 = y + V[i]; 
				if((item1 >= 0 || item1 < N) && (item2 >= 0 || item2 < N)
				&& F[x][y] < F[item1][item2]){
					if(F[item1][item2] < min){
						min = F[item1][item2];
						ddx = item1;
						ddy = item2;
						check = true;
					}
				}
			}
			if(!check){
				return count;
			}else{
				x = ddx;
				y = ddy;
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int t , cnt = 1;
	cin>>t;
	while(t > 0){
		
	int M , x , y;
	cin>>M>>x>>y;
	
	int F[M][100];
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < M ; j++){
			cin>>F[i][j];
		}
	}
	cout<<"#"<<cnt<<" "<<countingJump( F , M , x , y)<<endl;
	cnt++;
	t--;
	}
	return 0;
}
