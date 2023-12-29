#include<iostream>
#include<iomanip>
using namespace std;

struct CongViec{
	string macv;
	string tgbd;
	double tgth;
	
};
void Init(CongViec cvs[]){
	cvs[0] = {"CV001" , "9h 10p" , 20};
	cvs[1] = {"CV002" , "12h 15p" , 15};
	cvs[2] = {"CV003" , "20h 23p" , 30};
	cvs[3] = {"CV004" , "8h 12p" , 40};
	cvs[4] = {"CV005" , "11h 24p" , 50};
	cvs[5] = {"CV006" , "10h 15p" , 22};
	cvs[6] = {"CV007" , "14h 5p" , 45};
	cvs[7] = {"CV008" , "21h 16p" , 49};
}
void Title(){
	cout<<left
		<<setw(15)<<"Ma cv"
		<<setw(15)<<"Tgbh"
		<<setw(15)<<"Tgth"
		<<endl;
}
void ViewInfo(CongViec cv){
	cout<<left<<setw(15)<<cv.macv
		<<setw(15)<<cv.tgbd
		<<setw(15)<<cv.tgth<<endl;
}
void HienThiDaoNguoc(CongViec cvs[] , int l , int r){
	if(l > r){
		return;
	}
	ViewInfo(cvs[r]);
	HienThiDaoNguoc(cvs , l , r - 1);
}
//Lay ra 5 cong viec bang phuong phap sinh , lay ra chinh hop chap K cua n 
void ViewConfig(CongViec cvs[] , int mark[] , int k){
	for(int i = 0 ; i < k ; i++)
//		ViewInfo(cvs[mark[i] - 1]);
		cout<<cvs[mark[i] - 1].macv<<" ";
	cout<<endl;
}

void Generate(CongViec cvs[] , int n, int k , int &cnt ){
//Khoi tao mang bat dau 
	int mark[k];
	for(int j = 0 ; j < k ; j++)
		mark[j] = (j+1);
	
	int i;
	do{
		//In ra cau hinh dau 
		ViewConfig(cvs , mark , k);
		cnt++;
		i = k - 1;
		
		//Kiem tra tu cuoi ve dau xem cau hinh xem no cau hinh cuoi chua  
		while(i >= 0 && mark[i] == n - k + i + 1) i--;
		
		//Neu no chua la cau hinh cuoi 
		
		//Tang no len 1 
		mark[i]++;	
		
		//Chuyen tat ca cac cau hinh phia sau no thanh gioi han tren 
		if(i >= 0){
			for(int j = i + 1 ; j < k ; j++){
				mark[j] = mark[j-1] + 1;
			}
		}
	}while(i >= 0);
}
int main()
{
	int n = 8;
	CongViec cvs[n];
	Init(cvs);
	Title();
	HienThiDaoNguoc(cvs , 0 , n - 1);
	
	int k = 4 , cnt = 0;
	cout<<"\nLay ra 4 phan tu"<<endl;
	Generate(cvs , n , k , cnt);
	
	cout<<"\nCo tong cong : "<<cnt<<" cach"<<endl;
	return 0;
}
