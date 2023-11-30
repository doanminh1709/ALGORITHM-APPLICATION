#include<iostream>
#include<set>
#define ll long long 
using namespace std;

set<ll>fibo;

void init(){
	ll f[93];
	f[0] = 0;
	f[1] = 1;
	for(int i = 2 ; i < 93 ; i++){
		f[i] = f[i-1] + f[i-2];
	}
	//insert tat ca so fibonaci vao trong set 
	for(int i = 0 ; i < 93; i++){
		fibo.insert(f[i]);
	}
}
int main()
{
	
	int N , M;
	cin>>N>>M;
	init();
	llW Fes[N][M];
	
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M ; j++){
			cin>>Fes[i][j];
		}
	}
	
	//kiem tra (in ma tran theo chieu doc) 
	int markCol = 0;
	int ans;
	ll sum = 0;
	
	for(int i = 0 ; i < M ; i++){
		ll cnt = 0 , tmp = 0;
		for(int j = 0 ; j < N ; j++){
			//kiem tra phan tu co trong set hay khong ta su dung phuong thuc count cua set 
			if(fibo.count(Fes[j][i]) == 1){
				cnt++;
				tmp+=Fes[j][i];
			}
		}
		if(cnt > maxCount){
			markCol = i;
			ans = cnt;
			sum = tmp;
		}else if(cnt == ans){
			if(sum < tmp){
				markCol = i;
				sum = tmp;
			}
		}
	}
	cout<<markCol+1<<endl;
	
	for(int i = 0 ; i < N ; i++){
		if(fibo.count(Fes[i][markCol]) == 1)
			cout<<Fes[i][markCol]<<" ";
	}
	return 0;
}
