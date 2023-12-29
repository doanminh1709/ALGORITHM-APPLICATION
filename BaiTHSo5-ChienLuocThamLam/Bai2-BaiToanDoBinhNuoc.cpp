/*
De bai : 1 binh chua day nuoc vs 1 luong nuoc huu han la n. Cho m chiec chai rong 
(dung tich cac trai khac nhau) de chiet nuoc tu binh chua vao day cac chai. Hay cho
biet so luong chai toi da co the duoc do day nuoc. 

Input  : Dong thu nhat chua hai so nguyen n va m. 
	    Dong thu 2 chua m so nguyen la dung tich cua cac chai. 

Output : Mot so nguyen la so chai toi da duoc do , day nuoc. 	
*/

#include<iostream>
using namespace std;

int find_partition(int bottles[] , int l , int h){
	
	int pivot = bottles[l];
	int i = l , j = h;
	
	do{
		do{i++;}while(bottles[i] < pivot);
		do{j--;}while(bottles[j] > pivot);
		if(i < j) swap(bottles[i] , bottles[j]);
	}while(i < j);
	swap(bottles[l] , bottles[j]);
	
	return j;
}

void quickSort(int bottles[] , int l , int h){
	int partition;
	if(l < h){
		partition = find_partition(bottles , l , h);
		quickSort(bottles , l , partition);
		quickSort(bottles , partition + 1 , h);
	}
}
void solve(int bottles[] , int n , int m){
	int i = 0;
	while(bottles[i] < n && i <= m - 1){
		n-=bottles[i];
		i++;
	}
	cout<<i<<endl;
}
int main()
{
	
	int n , m;
	cin>>n>>m;
	
	int bottles[m];
	for(int i = 0 ; i < m ; i++)
		cin>>bottles[i];
		
	quickSort(bottles , 0 , m);
	solve(bottles , n , m);
	
	return 0;
}
