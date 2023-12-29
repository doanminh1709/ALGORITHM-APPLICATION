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
//Ham dem so chuyen bay co so ghe lon hon 100 va nho hon 200 bang chia de tri 
int Count(ChuyenBay b[] , int l , int r , int begin , int end){
	if(l == r){
		return b[l].soghe >= begin && b[l].soghe <= end;
	}else{
		int mid = (l + r)/2;
		int countLeft = Count(b , l , mid , begin , end);
		int countRight = Count(b , mid + 1 , r , begin , end);
		return countLeft + countRight;
	}
}
int main()
{
	int n = 7;
	ChuyenBay b[n];
	Init(b);
	cout<<"So ghe thoa man : "<<Count(b , 0 , n - 1 , 100 , 200);
	
	return 0;
}
