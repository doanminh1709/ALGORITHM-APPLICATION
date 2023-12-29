#include<iostream>
using namespace std;

#define MAXA 100
#define MAXVL 1e8
#define MINVL -1e8

int M[MAXA][MAXA];
int A[MAXA];
int N , K;

void input(){
	cin>>N>>K;
	for(int i ; i < K ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cin>>M[i][j];
		}
	}
}

int findMinId(int A[]){
	int min_id = MAXVL;
	for(int i = 0 ; i < N ; i++){
		min_id = min_id > A[i] && A[i] != 0 ? A[i] : min_id;		
	}
	return min_id;
}

int findIndexMin(int A[]){
	int min = findMinId(A);
	for(int i = 0 ; i < N ;i++){
		if(min == A[i]) return i;
	}
	return -1;
}

void AddFile(int id , int size){
																		
	int first_index = 0;
	int last_index = 0;
	int check = false;

	for(int i = 0 ; i < N ; i++){
		if(A[i] == 0){
			int cnt = 1;
			for(int j = i + 1 ; j < N ; j++){
					if(A[j] == 0) cnt++;
					else break;
			}
			if(cnt >= size){
				first_index = i;
				last_index = i + size;
				check = true;
				break;
			}else{
				i += cnt;
			}
		}	
	}
	if(check){
		for(int i = first_index ; i < last_index ; i++){
			A[i] = id;
		}		
	}else{

		int first_index_min = findIndexMin(A);
		int B[MAXA] = {0};
		int j = 0;

		int start = first_index_min - 1;
		while(A[start] == 0 && start > 0){
			start--;
		}
		start++;	
		B[j++] = A[first_index_min];
				
		for(int i = start ; i < start + size ; i++){
			int curr = A[i];
			int next_curr = A[i+1];
			if(curr != 0 && next_curr != 0 && curr != next_curr){
				B[j] = next_curr;
				j++;
			}
		}		
		
		int index = 0;
		for(int i = start ; i < N && index < j ; i++){
		 if(A[i] != 0 && A[i] != B[index]){
			index++;
		}else if(A[i] != 0 && A[i] == B[index]){
			A[i] = 0;
			}
		}	
		for(int i = start ; i < start + size ; i++){
			A[i] = id;
		}	
	}	
}
int maxInAAboutB(int a , int b){

	int B[MAXA] = {0};
	for(int i = a ; i <= b ; i++){
		if(B[A[i]] == 0){
			B[A[i]] = 1;
		}else{
			B[A[i]]++;
		}
	}
	int temp = MINVL; 
	int maxId = 0;
	for(int i = 0 ; i < MAXA ; i++){
		if(temp < B[i]){
			temp = B[i];
			maxId = i;
		}
	}
	return maxId;
}
void solve(int tc){
	int C[MAXA] , cnt = 0;
	for(int i = 0 ; i < K ; i ++){
		for(int j = 0 ; j < 3 ; j++){
			if(M[i][0] == 0){
				int id = M[i][1];
				int size = M[i][2];
				AddFile(id , size);
				break;
			}else{
				int a = M[i][1];
				int b = M[i][2];
				int res = maxInAAboutB(a , b);
				C[cnt++] = res;
				break;
			}
		}
	}
	
	cout<<"#"<<tc<<" ";
	for(int i = 0 ; i < cnt ; i++){
		cout<<C[i]<<" ";	
	}
}
/*
1
20 7
0 1 13
0 4 5
0 2 7
0 5 3
1 3 9
0 8 12
1 8 18

Ouput : #1 2 4  
*/
//0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//1 1 1 1 1 1 1 1 1 1 1 1 1 4 4 4 4 4 0 0 
//2 2 2 2 2 2 2 0 0 0 0 0 0 4 4 4 4 4 0 0
//2 2 2 2 2 2 2 5 5 5 0 0 0 4 4 4 4 4 0 0
//8 8 8 8 8 8 8 8 8 8 8 8 0 4 4 4 4 4 0 0
//a -> b : 2 2 2 2 0 0
int main(){
	
	int t;
	cin>>t;
	for(int i = 1 ; i <= t ; i++){
		input();
		solve(i);
	}
	
	return 0;
}
