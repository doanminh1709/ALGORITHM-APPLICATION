#include<iostream>
#define MAXN 100
using namespace std;

void CheckList(int i , int j , int M , int N, char Map[][MAXN] , int count){
	//check len tren 
	int k = 1;
	while(k <= count && i - k >= 0){
		if(Map[i-k][j] == 'H'){
			Map[i-k][j] = 'Y';	
		}
		k++;
	}
	//check xuong duoi 
	int k1 = 1;
	while(k1 <= count && i + k1 <= M){
		if( Map[i+k1][j] ==  'H'){
			Map[i + k1][j] = 'Y';			
		}
		k1++;
	}
	//check sang phai 
	int k2 = 1;
	while(k2 <= count && j + k2 <= N){
		if(Map[i][j + k2] ==  'H'){
			Map[i][j + k2] = 'Y';
		}
		k2++;
	}
	//check sang trai 
	int k3  = 1;
	while(k3 <= count && j - k3 >= 0){
	if(Map[i][j - k3] ==  'H'){
			Map[i][j - k3] = 'Y';
		}
		k3++;
	}

}

int main()
{
	int t , cnt = 1;
	cin>>t;
	while(t > 0){
		
		int M, N , countX = 0;
		cin>>M>>N;
		
		cin.ignore();
		
		char Map[M][MAXN];
		//nhap du lieu
		for(int i = 0 ; i < M ; i++)
			for(int j = 0 ; j < N ; j++)
				cin>>Map[i][j];		
		
		//xu ly dau vao 
		for(int i = 0 ; i < M ; i++){
			for(int j = 0 ; j < N ; j++){
				if(Map[i][j] == 'A'){
					CheckList(i , j , M , N , Map , 1);
				}else if(Map[i][j]  == 'B'){
					CheckList(i , j , M , N , Map , 2);
				}else if(Map[i][j]  == 'C'){
					CheckList(i , j , M , N , Map , 3);
				}
			}
		}
		
		//dem du lieu thoa man 
		for(int i = 0 ; i < M ; i++)
			for(int j = 0 ; j < N ; j++)
				if(Map[i][j] == 'H')
					countX++;		
//				} 	
//					cout<<Map[i][j]<<" ";
//				}
//				cout<<endl;
//			}				
		cout<<"#"<<cnt<<" "<<countX<<endl;	
		cnt++;
		t--;
	}
	return 0;
}
