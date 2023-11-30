#include<iostream>
using namespace std;

//dem xem co bao nhieu hang ma so luong 1 nhieu hon so luong so 0 
int main(){
	
	//doc tu file ra  
//	freopen("input.txt", "r" , stdin);
//	freopen("output.txt", "w" , stdin);
	
	int t;
	cin>>t;
	
	while(t--){
		int N;
		cin>>N;
		
		int A[N][N];
		int cnt = 0;
		for(int i = 0 ; i < N ; i++){
			int cnt0 , cnt1 ;
			cnt0 = cnt1 = 0;
			for(int j = 0 ; j < N ; j++){
				cin>>A[i][j];
				if(A[i][j] == 0){
					cnt0++;
				}else{
					cnt1++;
				}
			}
			if(cnt1 > cnt0) cnt++;
		}	
		
		cout<<cnt<<endl;
	}

	return 0;
 } 
