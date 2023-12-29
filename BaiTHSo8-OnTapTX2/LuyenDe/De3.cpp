#include<bits/stdc++.h>
using namespace std;


struct MayTinh{
	string nhanHieu;
	double giaNhap;
	double giaBan;
};
void Init(MayTinh mmt[]){
	mmt[0] = {"SamSung" , 550000 , 750000};
	mmt[1] = {"Dell" , 350000 , 380000};	
	mmt[2] = {"Asus" , 750000 , 850000};	
	mmt[3] = {"Lenovo" , 520000 , 760000};	
	mmt[4] = {"Apple" , 850000 , 950000};	
	mmt[5] = {"Nokia" , 420000 , 650000};			
}
void ShowInfo(MayTinh mt){
	cout<<left<<setw(15)<<mt.nhanHieu
		<<setw(15)<<mt.giaNhap
		<<setw(15)<<mt.giaBan
		<<setw(15)<<(mt.giaBan - mt.giaNhap)
		<<endl;
}
//Cau 1 
void ShowAllInfo(MayTinh mmt[] , int l , int r){
	if(l > r) return;
	else 
		ShowInfo(mmt[l]);
		ShowAllInfo(mmt , l + 1 , r);
}
void Merge(MayTinh mmt[] , int l , int r , int mid){
	int i , j , k;
	i = l , j = mid + 1 , k = l;
	MayTinh mmtcp[r+1];
	
	while(i <= mid && j <= r){
		if((mmt[i].giaBan - mmt[i].giaNhap) > 
		(mmt[j].giaBan - mmt[j].giaNhap)){
			mmtcp[k++] = mmt[i++];
		}else{
			mmtcp[k++] = mmt[j++];
		}
	}
	
	//Copy lai 
	for(; i <= mid ; i++)
		mmtcp[k++] = mmt[i];
		
	for(;j <= r ; j++)
		mmtcp[k++] = mmt[j];
	
	for(int t = l; t <= r ; t++){
		mmt[t] = mmtcp[t];
	}	
}
void MergeSort(MayTinh mmt[] , int l , int r){
	int mid;
	if(l < r){
		mid = (l + r)/2;
		MergeSort(mmt , l , mid);
		MergeSort(mmt , mid+1 ,r);
		Merge(mmt , l , r , mid);
	}
		
}
void GetLeastComputer(MayTinh mmt[] , int n ,  double q){
	int i = 0;
	while(q >= 0 && i < n){
		double tienLai = mmt[i].giaBan - mmt[i].giaNhap;
		if(q - tienLai >= 0){
			ShowInfo(mmt[i]);
			q = q - tienLai;
		}
		i++;
	}
}
void ShowAllConfig(MayTinh mmt[] , int arrIndex[] , int n){
	for(int i = 0 ; i < n ; i++)
		cout<<mmt[arrIndex[i]].nhanHieu<<"  ";
	cout<<endl;
}
void NextConfig(int arrIndex[] , int n , int i){
	int k = n - 1;
	while(arrIndex[i] > arrIndex[k]) k--;
	
	//doi cho a[i] cho a[k]
	swap(arrIndex[i] , arrIndex[k]);
	int j = n - 1;
	i++;
	while(i < j){
		swap(arrIndex[i] , arrIndex[j]);
		i++;
		j--;
	}
	
}

void Generate(MayTinh mmt[] , int n , int &cnt){
	int arrIndex[n];
	for(int j = 0 ; j < n ; j++)
		arrIndex[j] = j;
	int i;
	do{
		ShowAllConfig(mmt , arrIndex , n);
		cnt++;
		i = n - 2;
		//Tim day giam dan dai nhat tu 
		while(arrIndex[i] > arrIndex[i+1]) i--;//a[i] = 2
		if(i >= 0){
			NextConfig(arrIndex , n , i);
		}
	}while(i >= 0);
}
//Cau 2 
// 2 1 8 9    10 4 7 12 
// 2-1 8-9  10-4 7-12 
// 2 1 8 9  10 4 7 12 
// 1-2 8-9  4-10 7-12 
// 1 2 8 9  4 7 10 12 
// 1 2 4 7 8 9 10 12 


//Y tuong sinh hoan vi 
//1 2 3 4 5 6 
//1 2 3 4 6 5
//6 5 4 3 2 1 
int main()
{
	int n = 6 , cnt = 0;
	MayTinh mmt[n];
	Init(mmt);
	cout<<"Truoc khi sap xep "<<endl;
	ShowAllInfo(mmt , 0 , n - 1);
	
	cout<<"Sau khi sap xep"<<endl;
	MergeSort(mmt , 0 , n - 1);
	ShowAllInfo(mmt , 0 , n - 1);
	
	cout<<"Nhap so tien lai : ";
	double q;
	cin>>q;
	GetLeastComputer(mmt,n , q);
		
	cout<<"In ra n cau hinh"<<endl;
	Generate(mmt , n , cnt);
	
	cout<<"\nCo tong cong "<<cnt<<" cach ";
	return 0;
}
 
