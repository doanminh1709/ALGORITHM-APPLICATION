#include<iostream>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int M , S1 = 0 , S2 = 0;
		cin>>M;
		int A[500][500];
		
		for(int i = 0 ; i < M ; i++){
			for(int j = 0 ; j < M ; j++){
				cin>>A[i][j];
			}
		}
		//Tinh cac phan tu thuoc tam giac duoi 
		for(int i = 0 ; i < M ; i++){
			for(int j = 0 ; j <= i ; j++){
				S1+=A[i][j];
			}
		}
		//Tinh cac phan tu thuoc tam giac tren 
			for(int i = 0 ; i < M ; i++){
			for(int j = i ; j < M ; j++){
				S2+=A[i][j];
			}
		}
		cout<<"Tong tam giac duoi : "<<S1<<endl;	
		cout<<"Tong tam giac tren : "<<S2<<endl;
	}
	
	return 0;
}
