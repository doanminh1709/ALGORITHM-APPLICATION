#include<iostream>
using namespace std;
#define MAX 1000
#define P 5
int LoaiCham[5] = {16 , 4 , 8 , 12 , 0};
int LoaiSao[5] = {0 , 12 , 8 , 4 , 16};

int main()
{
	int t;cin>>t;
	int count = 1;
	while(t > 0){
		
	int M, N;
	cin>>M>>N;

	int sd = P*M+1 , sc = P*N+1;
	int Cnt[P] = {0 , 0 , 0 , 0 , 0};
	
	char RC[MAX][MAX];
	for(int i = 0 ; i < sd ; i++){
		for(int j = 0 ; j < sc ; j++){
			cin>>RC[i][j];
		}
	}
	int cnt1 = 1 , cnt2 = 1;
	for(int i = 0 ; i < sd - 1; i+=P){
		cnt2 = 1;
		for(int j = 0; j < sc - 1 ; j+= P){
			int demCham = 0 , demSao = 0;
			for(int t = i ; t < P*cnt1 + 1 && t < sd - 1; t++){
				for(int p  = j ; p < P*cnt2 + 1 && p < sc - 1 ; p++){
					if(RC[t][p] == '.'){
						demCham++;
					}
					if(RC[t][p] == '*'){
						demSao++;
					}
				}
			}
			for(int i = 0 ; i < P ; i++){
				if(demCham == LoaiCham[i] && demSao == LoaiSao[i]){
					Cnt[i]++;
				}
			}
			cnt2++;
		}
		cnt1++;
	}
	
	cout<<"#"<<count<<" ";
	for(int i = 0 ; i < P  ; i++){
		if(i < P - 1)
			cout<<Cnt[i]<<" ";
		else
			cout<<Cnt[i];
		}
	cout<<endl;
	t--;
	count++;
	}
	
	return 0;
 } 

