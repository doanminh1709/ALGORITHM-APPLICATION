#include<bits/stdc++.h>
using namespace std;

float sumOfNumber(float*A, int l , int r){
	//su dung thoat toan chia de tri 
	if(l == r){
		return A[l];
	}else{
		int mid = (l + r)/2;
		float sumLeft = sumOfNumber(A , l , mid);
		float rightLeft = sumOfNumber(A , mid+1 , r);
		return sumLeft + rightLeft;	
	}
}
int main(){
	
	
	int n = 10;
	float a[n] = {2.3 , 2 , 4 , 2.4 , 5.3  , 3.2 , 4.5 , 6.2 , 8 , 9.3};
	
	cout<<sumOfNumber(A , 0 , n-1)<<endl;
	
	return 0;
} 
