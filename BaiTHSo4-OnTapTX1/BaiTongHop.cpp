//Lam bai 1 voi cac yeu cau sau 

//Sinh hoan vi to hop , sinh hoan vi to hop chap k , sinh hoan hoan vi 
//Su dung phuong phap quay lui de thuc hien sinh 
//Sap xep su dung quick sort va megre sort 
//Tim kiem 1 phan tu bang phuong phap chia de tri 
//Xuat ra cac phan tu bang de quy 
#include<bits/stdc++.h>
using namespace std;

struct ChuyenBay{
	string sohieu;
	double giave;
	int soghe;
};
void Init(ChuyenBay b[]){
	b[0] = {"VN001" , 700000 , 200};
	b[1] = {"VN003" , 650000 , 100};
	b[2] = {"VN002" , 800000 , 220};
	b[3] = {"VN004" , 400000 , 120};
	b[4] = {"VN005" , 500000 , 330};
	b[5] = {"VN003" , 400000 , 210};
	b[6] = {"VN006" , 750000 , 126};
}
void Info(ChuyenBay cb){
	cout<<left<<setw(15)<<cb.sohieu
		<<setw(15)<<cb.giave
		<<setw(10)<<cb.soghe<<endl;
}
void ShowListCBGreate700(ChuyenBay b[] , int n){
	if(n == 0) return;
	ShowListCBGreate700(b , n - 1);
	ChuyenBay cb = b[n-1];
	if(cb.giave > 700000){
		Info(b[n-1]);
	}
}
double FindMinTicket(ChuyenBay b[] , int l , int r){
	if(l == r){
		return b[l].giave;
	}
	if(r == l + 1){
		return b[l].giave < b[r].giave ? b[l].giave : b[r].giave;
	}else{
		int mid = (l + r)/2;
		double minTicketLeft = FindMinTicket(b , l , mid);
		double minTicketRight = FindMinTicket(b , mid+1 , r);
	
	return minTicketLeft < minTicketRight? minTicketLeft : minTicketRight;
	}
}
void ShowMinTicket(ChuyenBay b[]  , int n){
	double minTicket = FindMinTicket(b , 0 , n - 1);
	for(int i = 0 ; i < n  ; i++)
		if(minTicket == b[i].giave){
			Info(b[i]);
		}
}
//Hien thi tat ca cac phuong an de chon ra 4 chuyen bay tu db b
void ShowConfigTicket(ChuyenBay b[] , int arr[] , int k){
	for(int i = 1 ; i <= k ; i++){
		cout<<b[arr[i] - 1].sohieu<<" ";
		//Boi vi cau hinh bat dau tu 1-> k nen i se chay tu 1 den k   
//		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void Generate(ChuyenBay b[] , int n , int k , int &cnt){
	//Khoi tao 
	int arr[k];
	for(int j = 0 ; j < k ; j++)
		arr[j] = j + 1;
	
	//Kiem tra 
	int i;
	do{
		//In ra cau hinh dau 
		ShowConfigTicket(b , arr , k);
		//Tim phan tu chua dat gioi han tren 
		i = k - 1;
		cnt++;
		
		while(i >= 0 && arr[i] == n - k + i + 1){
			i--;
		}
		//Tang phan tu do len 1 
		arr[i]++;
		//if(i > 0){
			//Cap nhat lai cac phan tu sau bang phan tu truoc cong 1 
			for(int j = i + 1 ; j < k ; j++){
				arr[j] = arr[j-1] + 1;
			}
		//}
	}while(i >= 0);
}
void Try(int i , ChuyenBay b[] , int arr[], bool mark[] , int k , int n){
	//Gia tri in ra se duoc rang buoc tu a[i-1] + 1 den n - k + i
	//Tao 1 mang de check nhung gia tri da di qua 
	for(int j = arr[i - 1] + 1 ; j <= n - k + i ; j++){
		//Neu arr[i] chua duoc kiem tra 
		if(!mark[j]){
			//Danh dau no lai 
			 mark[j] = true;
			 arr[i] = j;
			 //In ra cau hinh 
			 if(i == k){
			 	ShowConfigTicket(b , arr , k);
			 }
			 //Backtracking 
			 else{
			 	Try(i+1 , b , arr , mark , k , n);
			 }
			 //Tra lai vi tri da duoc danh dau de tim cau hinh tiep theo 
			 mark[j] = false;
		}	
	}
}
//Sinh day con nhi phan 

//Liet ke cac hoan vi 
//Su dung phuong phap sinh 

//Su dung phuong phap quay lui 


//Su dung merge sort sap xep tang dan theo tien ve 
void ShowAllList(ChuyenBay b[] , int n){
	if(n == 0) return;
	ShowAllList(b , n - 1);
	Info(b[n-1]);
}
void Merge(ChuyenBay b[] , int l , int r , int mid){
	int i , j , k;
	i = l , j = mid + 1 , k = l;
	ChuyenBay bcp[r+1];
	while(i <= mid && j <= r){
		if(b[i].giave < b[j].giave){
			bcp[k++] = b[i++]; 	
		}else{
			bcp[k++] = b[j++];
		}
	}
	
	//Copy remaining element 
	for(; i <= mid ; i++)
		bcp[k++] = b[i];
		
	for(;j <= r ; j++)
		bcp[k++] = b[j];
		
	//Reverse copy from bcp to b 
	for(int t = l ; t <= r ; t++)
		b[t] = bcp[t];
}	

//Merge 
void MergeSort(ChuyenBay b[] , int l , int r){
	int mid;
	if(l < r){
		mid = (l + r)/2;
		MergeSort(b , l , mid);
		MergeSort(b , mid + 1 , r);
		Merge(b , l , r , mid);
	}
}
//Su dung quick sort sap xep giam dan so ghe 
//Ham tra ve vi tri phan chia day 
int find_partiction(ChuyenBay b[] , int l , int r){
	string pivot = b[l].sohieu;
	int i = l , j = r;
	while(i < j){
		do{
			i++;
		}while(b[i].sohieu.compare(pivot) >= 0);
		
		do{
			j--;
		}while(b[j].sohieu.compare(pivot) < 0);
		
		//Doi vi tri cho b[i] va b[j]
		if(i < j) swap(b[i] , b[j]);
	}
	//Doi vi tri pivot va b[j]
	swap(b[j] , b[l]);
	return j;//j chinh la vi tri chia doi day ra 
} 
void QuickSort(ChuyenBay b[] , int l , int r){
	//Dua ra vi tri chia doi day 
	int practition;
	if(l < r){
	practition = find_partiction(b, l , r);
	//Sort tung nua 1 
	//Sap xep nua trai 
	QuickSort(b , l ,practition);
	//Sap xep nua ben phai 
	QuickSort(b ,practition + 1 , r);
	}
}
// Liet ke ra so hoan vi 
void ShowAllConfig2(ChuyenBay cb[] , int arr[] , int n){
	for(int i = 0 ; i < n ; i++)
		cout<<cb[arr[i]].sohieu<<" ";
	cout<<endl;
}
void NextConfig(int arr[] ,int n , int i){
	int k = n - 1;
	//Tim phan tu vua du lon hon arr[i]
	while(arr[i] > arr[k]){
		k--;
	}
	//Tim thay thi doi phan tu arr[i] cho arr[k]
	swap(arr[i] , arr[k]);
	
	//Dao nguoc day tu i+1 den n 
	int j =  n - 1;
	i++;
	while(i < j){
		swap(arr[i] ,arr[j]);
		i++; j--;
	}
}

void Generate2(ChuyenBay cb[] , int n , int &cnt){
	//Khoi tao cau hinh dau tien 
	int arr[n];
	for(int j = 0 ; j < n ; j++)
		arr[j] = j;
	int i;
	do{
		//In ra cau hinh dau tien 
		ShowAllConfig2(cb , arr , n);
		cnt++;
		i = n - 2;
		//Lap tu cuoi tim day con giam dan dai nhat 
		while(i>= 0 && arr[i] > arr[i+1]){
			i--;
		}
		//Neu tim thay 
		if(i >= 0){
			//Sinh ra cau hinh ke tiep 
			NextConfig(arr , n , i);
		}
		
	}while(i >= 0);
}
//Su dung Quay lui 
void Try2(int i , int arr[], ChuyenBay b[] , bool mark[] , int n , int &cnt){
	for(int j = 0 ; j < n ; j++){
		if(!mark[j]){
			mark[j] = true;
			arr[i] = j;
			if(i == n - 1){
				cnt++;
				ShowAllConfig2(b , arr , n);
			}else{
				Try2(i+1 , arr , b , mark , n , cnt);
			}
			mark[j] = false;
		}
	}
}
//Bai toan sinh cau hinh do dai n 

//Bai toan tim kiem bang thuat toan tim kiem nhi phan 
int searchByCode(ChuyenBay b[] , int l , int r , string sh){
	if(l > r){
		return -1;
	}
	int mid = (l + r)/2;
	if(b[mid].sohieu.compare(sh) == 0){
		return mid;
	}else if(b[mid].sohieu.compare(sh) < 0){
		return searchByCode(b , mid + 1 , r , sh);
	}else{
		return searchByCode(b , l , mid , sh);
	}
}
void Generate3(int n){
	//Khoi tao cau hinh dau 
	int arr[n] = {0};
	int i;
	do{
		//In ra cau hinh dau 
		for(int j = 0 ; j < n ; j++){
			cout<<arr[j]<<" ";
		}
		cout<<endl;
		//duyet tu cuoi ve tim phan tu dau tien bang 0 chuyen thanh 1 
		i = n - 1;
		while(i >= 0 && arr[i] == 1){
			i--;
		}
		//Gap so 0 dau tien thi chuyen no thanh 1  
		//Chuyen cac phan tu phia sau thanh 1 
//		if(i >= 0){
			arr[i] = 1;
		//Chuyen tat ca cac phan tu phia sau no thanh so 0 
		for(int j = i + 1 ; j < n ; j++){
			arr[j] = 0;
//		}
		}
	}while(i >= 0);
}
int main()
{
	
	int n = 7;
	ChuyenBay b[n];
	Init(b);
	
	cout<<"Hien thi cac chuyen bay co gia tren 700000"<<endl;
	ShowListCBGreate700(b , n);
	
	cout<<"\nDanh sach cac chuyen bay co gia ve nho nhat "<<endl;
	ShowMinTicket(b , n);
	
	cout<<"\nCac cau hinh hien co"<<endl;
	int k = 4 , cnt = 0;
//	Generate(b , n , k , cnt);
	
	//Luu y cach de check loi thi minh se in ra cau hinh la so truoc 	
//	cout<<cnt;
	
	bool mark[100] = {false};
	int arr[100] = {0};

	Try(1 , b , arr , mark , k , n);
	
	cout<<"\nTruoc khi sap xep bang merge sort "<<endl;
	ShowAllList(b , n);
	
	cout<<"\nSau khi sap xep bang merge sort"<<endl;
	MergeSort(b , 0 , n - 1);
	ShowAllList(b , n);
		
	cout<<"\nTruoc khi sap xep quick sort "<<endl;
	ShowAllList(b , n);
	
	cout<<"\nSau khi sap xep bang quick sort"<<endl;
	QuickSort(b , 0 , n);
	ShowAllList(b , n);
	
//	cnt = 0;
//	cout<<"Co tong cong "<<endl;
//	Generate2(b , n , cnt);
//	Try2(0 , arr , b , mark , n , cnt);
//	cout<<"Co "<<cnt<<" cach"<<endl;
	
	cout<<"Nhap so nhieu muon tim ";
	string sh;
	getline(cin , sh);
	
	//Luu y doi voi tt nay phai duoc sort truoc 
//	int index = searchByCode(b , 0 , n - 1 , sh);
//	if(index != -1)
//		Info(b[index]);
//	else
//		cout<<"Khong tim thay chuyen bay nao co so hieu : "<<sh<<endl;
	
	Generate3(3);
}
