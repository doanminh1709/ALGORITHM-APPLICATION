#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int n , m;
int M[MAX][MAX];

void Input(){
	cin>>n>>m;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>M[i][j];			
		}
	}
}
void Solve(){
	map<int, int>map;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i == 0){
//				map.insert(make_pair(M[i][j] , 1));
				map[M[i][j]] = 1;
			}else{
//				if(map.count(M[i][j]) > 0){
				if(map[M[i][j]] == i){
					map[M[i][j]]++;
				}			
			}
		}
    }
    int cnt = 0;
    for(auto it : map){
    	if(it.second == n){
    		cnt++;
		}
	}
	cout<<cnt<<endl;
}

int main(){
	
	Input();
	Solve();
	return 0;
}
