#include<bits/stdc++.h>
using namespace std;

struct ChuyenBay{
	
	string so_hieu_cb;
	double gia_ve;
	int so_ghe;
};

void init(ChuyenBay cbs[]){
	cbs[0] = {"VN001" , 730000 , 120};
	cbs[1] = {"VN002" , 540000 , 220};
	cbs[2] = {"VN003" , 860000 , 156};
	cbs[3] = {"VN004" , 570000 , 410};
	cbs[4] = {"VN005" , 930000 , 250};
	cbs[5] = {"VN006" , 230000 , 100};
	cbs[6] = {"VN007" , 900000 , 110};
}

void title(){
	cout<<left
	<<setw(15)<<"So hieu cb"
	<<setw(15)<<"Gia ve"
	<<setw(15)<<"So ghe"<<endl; 	
}
void view_info(ChuyenBay cb){
	cout<<left
	<<setw(15)<<cb.so_hieu_cb
	<<setw(15)<<cb.gia_ve
	<<setw(15)<<cb.so_ghe<<endl; 	
}

void dequy(ChuyenBay cbs[] , int l , int r){
	if(l > r){
		return;
	}else{
	if(cbs[l].gia_ve > 700000){
		view_info(cbs[l]);
	}
	dequy(cbs , l+1 , r);
	}
}
//Tim min bang phuong phap chia de tri
//Ham tim min  
double min(ChuyenBay cbs[] , int l , int r){

	//truong hop base
	if(l == r){
		return cbs[l].gia_ve;
	}
	else{
		int mid = (l + r)/2;
		//De quy tim thang nho nhat phia ben tay trai 
		double minLeft = min(cbs , l , mid);
		//De quy tim thang nho nhat phia ben tay phai 
		double minRight = min(cbs , mid + 1 , r);
		
		if(minLeft > minRight){
			return minRight;
		}else if(minLeft < minRight){
			return minLeft;
		}else{
			return minLeft;
		}
	}
} 

void TimViTriNn(ChuyenBay cbs[] , int n){
	double gia_ve_nn = min(cbs , 0 , n-1);
	
	for(int i = 0 ; i < n ; i++){
		if(cbs[i].gia_ve == gia_ve_nn)
			view_info(cbs[i]);
	}
}
void HienThiCachChon(ChuyenBay cbs[] , int arr[] , int k){
	for(int i = 1 ; i <= k ; i++)
		cout<<cbs[arr[i] - 1].so_hieu_cb<<"  ";
	cout<<endl;
}
//Hien thi tat ca cac cach chon 4 phuong an su dung quay lui : to hop chap k 
void Thu(ChuyenBay cbs[] , bool mark[] , int arr[] , int n , int k , int i , int &cnt){
	for(int j = arr[i - 1] + 1 ; j <= n - k + i ; j++){
		//Neu vi tri chua duoc chon 
		if(!mark[j]){
			mark[j] = true;
			arr[i] = j;
			if(i == k){
				cnt++;
				HienThiCachChon(cbs , arr , k);
			}else{
				Thu(cbs , mark , arr , n , k , i+1 , cnt);
			}
			mark[j] = false;
		}
	}
} 

int main()
{
	int n = 7;
	ChuyenBay cbs[n];
	init(cbs);
	
	title();
	dequy(cbs , 0 , n - 1);
	
	//Tim vi tri nho nhat 
	cout<<"\nThong tin vi tri nho nhat"<<endl;
	title();//
	TimViTriNn(cbs , n);
	
	//Lay ra 4 vi tri 
	bool mark[100] = {false};
	int arr[100] = {0};
	int k = 4;
	int cnt = 0;
	cout<<"\nCac cach chon"<<endl;
	Thu(cbs , mark , arr , n , k , 1 , cnt);
	
	cout<<"\nVay co tong cong : "<<cnt<<" cach chon";
	return 0;
}
