#include<bits/stdc++.h>
using namespace std;

char A[100]="ABCDESE" , B[100]="ABDES";
int fes[100][100];

int solve(){
	int n = strlen(A);
	int m = strlen(B);
	
	for(int i = 0 ; i <= n ; i++) fes[i][0] = 0;
	for(int i = 0 ; i <= m ; i++) fes[0][i] = 0;

	for(int i = 1 ; i <= n  ; i++){
		for(int j = 1 ; j <= m ; j++){
		 	if(A[i-1] == B[j-1]){
				fes[i][j] = fes[i-1][j-1] + 1;
			}else{
				fes[i][j] = max(fes[i-1][j] , fes[i][j-1]);
			}
		}
	}
	return fes[n][m];
}
void Trace(){
	int i = strlen(A) , j = strlen(B) , k = 0;
	char xc[200];

	while(fes[i][j] != 0){
		if(A[i - 1] == B[j-1]){
			i--; j--;
			xc[k] = A[i];
			k++;
		}else{
			if(fes[i][j-1] > fes[i-1][j-1]) j--;
			else i--;
		}
	}	
	xc[k] = '\0';
	for(int i = k - 1 ; i >= 0 ; i--)
		cout<<xc[i];
}
int main(){
	
	cout<<solve()<<endl;
	Trace();
	
	return 0;
}
