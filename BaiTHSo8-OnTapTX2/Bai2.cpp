#include<bits/stdc++.h>
using namespace std;

typedef long double lb;
lb p;
int n;

struct QuatBan{
	
	string tenhang;
	string mausac;
	double giaban;	
	
};
void Init(QuatBan d[]){
	p = 1000000;
	
	d[0] = {"SamSung" , "Xanh" , 150000};
	d[1] = {"Sony" , "Do" , 450000};
	d[2] = {"Panasonic" , "Den" , 200000};
	d[3] = {"Tosypa" , "Trang" , 350000};
	d[4] = {"QPVN" , "Xam" , 240000};
}
void output(QuatBan qb){
	cout<<left<<setw(20)<<qb.tenhang
		<<setw(15)<<qb.mausac
		<<setw(20)<<qb.giaban
		<<endl;
}
//y tuong cua chien luoc tham lam , se sap xep tang dan hoc giam dan theo 1 tieu chi nhat dinh 
void Merge(QuatBan d[] , int l , int r , int mid){
	int i = l , j = mid+1;
	int k = l;
	
	QuatBan dcp[n];
	
	while(i <= mid && j <= r){
		if(d[i].giaban > d[j].giaban){
			dcp[k++] = d[i++];
		}else{
			dcp[k++] = d[j++];
		}
	}
	
	for(; i <= mid ; i++){
		dcp[k++] = d[i]; 
	}
	
	for(; j <= r ; j++){
		dcp[k++] = d[j];
	}
	
	for(int t = l ; t <= r ; t++){
		d[t] = dcp[t];
	}
}
void MergeSort(QuatBan d[] , int l , int r){
	int mid;
	
	if(l < r){
		mid = (l + r)/2;
		MergeSort(d , l , mid);
		MergeSort(d , mid+1 , r);
		Merge(d , l , r , mid);
	}
}
void solve(QuatBan d[]){
	int cnt;
	int i = 0;
	while(p > 0 && i < n){
		if(p >= d[i].giaban){
			cnt++;
			output(d[i]);
			p-=d[i].giaban;
		}	
		i++;
	}
	cout<<"So quat thieu da co the mua : "<<cnt<<endl;
}
int main(){
	
	n = 5;
	
	QuatBan d[n];
	Init(d);
	MergeSort(d , 0 , n - 1);
	solve(d);
	
	return 0;
} 
