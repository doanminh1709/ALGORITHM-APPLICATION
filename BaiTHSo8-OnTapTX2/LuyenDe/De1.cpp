#include<bits/stdc++.h>
using namespace std;

int n , s , m;
struct TuLanh{
	string tenHang;
	int dienTich;
	int giaTri;
};

void Init(TuLanh d[]){
	d[0] = {"Sony" , 1 , 500000};
	d[1] = {"SamSung" , 2 , 400000};
	d[2] = {"Sony" , 2 , 300000};
	d[3] = {"Sony" , 4 , 540000};
	d[4] = {"Sony" , 5 , 520000};
}
void ShowInfo(TuLanh item){
	cout<<left<<setw(15)<<item.tenHang
	<<setw(13)<<item.dienTich
	<<setw(13)<<item.giaTri<<endl;
}

void Title(){
	cout<<left<<setw(15)<<"TenHang"
	<<setw(13)<<"Dien tich"
	<<setw(13)<<"Gia tri"<<endl;
}
int FindPartition(TuLanh d[] , int l , int r){
	int pivot = d[l].giaTri;
	int i = l , j = r;
	
	do{
		do{i++;}while(d[i].giaTri > pivot);
		do{j--;}while(d[j].giaTri < pivot);
		if(i < j) {
			swap(d[i] , d[j]);
		}
	}while(i < j);
	swap(d[l] , d[j]);
	return j;
} 
void QuickSort(TuLanh d[] , int l , int r){
	int partition;
	if(l < r){
		partition = FindPartition(d , l , r);
		QuickSort(d , l , partition);
		QuickSort(d , partition + 1 , r);
	}
}
void Merge(TuLanh d[] , int l , int r , int mid){
	int i = l , j = mid + 1;
	int k = l;
	TuLanh dcp[r+1];
	
	while(i <= mid && j <= r){
		if(d[i].giaTri > d[j].giaTri){
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
	
	for(int i = l ; i <= r ; i++){
		d[i] = dcp[i];
	}
}
void MergeSort(TuLanh d[] , int l , int r){
	int mid;
	if(l < r){
		mid = (l + r)/2;
		MergeSort(d , l , mid);
		MergeSort(d , mid + 1 , r);
		Merge(d , l , r , mid);
	}
}
void Solve1(TuLanh d[] , double m){
	int i = 0;
	Title();
	while(i < n && m >= d[i].giaTri){
		ShowInfo(d[i]);
		m-=d[i].giaTri;
		i++;
	}
	cout<<"\nMua duoc nhieu nhat : "<<i<<" cai tu lanh"<<endl;
}
void Solve2(TuLanh d[] , int fes[][100], int s){
		
	for(int i = 0 ; i <= s ; i++) fes[0][i] = 0;
	
	//Bat dau tu hang 1 nho khong phai la hang 0 	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= s ; j++){
			//* neu ma khong lay 
			fes[i][j] = fes[i-1][j];
			//Phai kiem tra dieu kien truoc roi voi xet co lay hay khong 
			if(j >= d[i].dienTich){
				//cong gia tri moi voi gia tri max o buoc thu i truoc do 
				int temp = d[i].giaTri + fes[i-1][j - d[i].dienTich];
				//So sanh cap nhat neu thoa man thi lay 
				if(fes[i][j] < temp){//neu ma lay duoc 
					fes[i][j] = temp;
				}
			}
		}
	}
	
	//in ra bang gia tri 
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= s; j++){
			cout<<fes[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Trace(TuLanh d[] , int fes[][100]){
	//Co so de truy vet 
	/*
		F[n][m] la gia tri lon nhat trong n goi hang voi gioi han trong luong la m 
		Neu F[n][m] == F[n-1][m] thi co nghia khong lay goi hang thu n 
		Neu F[n][m] != F[n][m-1] co lay goi hang thu n va truy vet nguoc ve goi hang F[n-1][m - W[n]]
		Tiep tuc truy vet den hang 0
	*/ 
	Title();
	int i = n , j = s;
	while(i != 0){
		//kiem tra duyet nguoc len xem goi hang co thoa man hay khong 
		if(fes[i][j] != fes[i-1][j]){
			ShowInfo(d[i]);
			//neu ma lay thi cap nhat lai thang cot 
			j -= d[i].dienTich;
		}
		i--;
	}
}

int main(){
	
	n = 5 , m = 2000000 , s = 12;
	int fes[n+1][100];
	
	TuLanh d[n];
	Init(d);
//	MergeSort(d , 0 , n - 1);
	QuickSort(d , 0 , n);
	Solve1(d , m);
	
	Solve2(d ,fes, s);
	Trace(d , fes);
	
	return 0;
}
