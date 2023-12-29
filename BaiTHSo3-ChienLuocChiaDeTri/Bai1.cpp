#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct HocSinh{
    string ten;
    string hodem;
    int namsinh;
    string diachi;
};
void KhoiTao(HocSinh mhs[]){
    mhs[0] = {"Duc" , "Nguyen Van" , 2002 , "Thanh Hoa"};
    mhs[1] = {"Cuc" , "Bui Thi" , 2004 , "Ha Noi"};
    mhs[2] = {"Binh" , "Tran Van" , 2001 , "Hai Duong"};
    mhs[3] = {"Son" , "Nguyen Bao" , 2003 , "Ninh Binh"};
    mhs[4] = {"Kien" , "Duong Trung" , 2006 , "Nghe An"};
    mhs[5] = {"Chien" , "Nguyen Huu" , 2005 , "Binh Thuan"};
}
void ThongTin(HocSinh hs){
    cout<<left
    <<setw(15)<<hs.ten
    <<setw(20)<<hs.hodem
    <<setw(14)<<hs.namsinh
    <<setw(20)<<hs.diachi
    <<endl;
}
//Su dung thuat toan quick sort hoac merge sort co do phuc tap O(NLogN)
void Merge(HocSinh mhs[] , int l , int r , int mid){
    int i , j , k;
    i = l;
    j = mid+1;
    k = l;
    HocSinh * mshscp = new HocSinh[r+1];

    //Copy 
    //Boi vi day la copy tu i den mid + 1 va j den r nen dieu kien phai la i <= mid && j <= r
    while(i <= mid && j <= r){
        if(mhs[i].ten.compare(mhs[j].ten) < 0){
            mshscp[k++] = mhs[i++];
        }else{
            mshscp[k++] = mhs[j++];
        }
    }

    //Copy remaining 
    for(; i < mid + 1 ; i++){
        mshscp[k++] = mhs[i];
    }

    for(;j <= r ; j++){
        mshscp[k++] = mhs[j];
    }

    //Page reserse 
    for(int j = l ; j <= r ; j++){
        mhs[j] = mshscp[j];
    }
}

void MergeSort(HocSinh mhs[] , int l , int r){
    int mid;
    if(l < r){
        mid = (l+r)/2;
        //Merge sort left 
        MergeSort(mhs , l , mid);
        
        //Merge sort right 
        MergeSort(mhs , mid+1 , r);

        //Merge all array 
        Merge(mhs , l , r , mid);
    }
}
//Su dung thuat toan Quick Sort 
int partition(HocSinh mhs[] , int l , int r){
}

//Su dung thuat toan tim kiem nhi phan 
int TimKiem(HocSinh mhs[] , int l , int r , string ten){

	if(l > r){
		return -1;
	}
    int mid = (l + r)/2;
    if(mhs[mid].ten.compare(ten) == 0){
        return mid;
    }else if(ten.compare(mhs[mid].ten) < 0){
       return TimKiem(mhs , l , mid - 1 , ten);
    }else{
      return TimKiem(mhs, mid + 1 , r , ten);
    }
}
void HienThiTtHS(HocSinh mhs[] , int l , int r){
    if(l > r) return;
    ThongTin(mhs[l]);
    HienThiTtHS(mhs , l + 1 , r);
}

int main()
{
    int N = 6;
    HocSinh *mhs = new HocSinh[N];
    KhoiTao(mhs);
    cout<<"\nTruoc khi sap xep "<<endl;
    HienThiTtHS(mhs , 0 , N - 1);
    
    cout<<"\nSau khi sap xep "<<endl;
    MergeSort(mhs , 0 , N - 1);
    HienThiTtHS(mhs , 0 , N - 1);
    
    string tenhs;
	cout<<"\nhap ten hs can tim : ";
	getline(cin , tenhs);
	
	int pos = TimKiem(mhs , 0, N - 1 , tenhs);
	if(pos != -1){
		ThongTin(mhs[pos]);
	}else{
		cout<<"Khong tim thay hs co ten : "<<tenhs<<endl;
	}

    return 0;
}
