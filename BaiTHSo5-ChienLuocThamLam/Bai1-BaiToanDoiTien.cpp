/*
De bai : lay so dong tien it nhat de duoc menh gia bang n

Phuong phap : Sap xep cac menh gia giam dan , va lay lan luot tu dong tien lon nhat tro ve 
*/

#include<iostream>
using namespace std;

int find_partition(int A[] , int l , int h){
	int pilot = A[l];
	int i = l , j = h;
	
	do{
		do{ i++; }while(A[i] > pilot);
		do{ j--; }while(A[j] < pilot);
		if(i < j) swap(A[i] , A[j]);
	}while(i < j);
	swap(A[l] , A[j]);
	
	return j;
}
void quickSort(int A[] , int l , int h){
	int partition;
	if(l < h){
		partition =  find_partition(A , l , h);
		quickSort(A , l , partition);
		quickSort(A , partition + 1 , h);
	}	
}

void solve(int coins[] , int n , int m){
	int i = 0 , cnt = 0;
	while(m >= 0){
		if(m >= coins[i]){
			cout<<coins[i]<<" ";
			m -= coins[i];
			cnt++;
		}else{
			i++;
			if(i == n - 1 && m < coins[i]){
				break;
			}
		}
	}
	cout<<"\nSo dong tien toi da co the lay : "<<cnt<<endl;
}

int main()
{
	
	int n, m;
	cin>>n>>m;
	
	int coins[n];
	for(int i = 0 ; i < n ; i++)
		cin>>coins[i];
		
	quickSort(coins , 0 , n );
	solve(coins , n , m);
	
	return 0;
}
