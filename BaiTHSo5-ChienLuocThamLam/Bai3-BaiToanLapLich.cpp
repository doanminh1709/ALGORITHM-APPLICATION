/*
	Bai toan chia viec : 
		Co n cong viec , cong viec j bat dau tai thoi diem sj
		va ket thuc tai thoi diem fj.
		
		Hai cong viec duoc goi la tuong hop neu thoi gian thuc
		hien cua chung khong giao nhau. 
		
		Tim mot tap cuc dai cac cong viec ma chung tuong hop voi nhau. 
	
	INPUT:
	5 
	8 9 10 11 12 
	8.5 11 11.5 12.5 13 	
	
	OUTPUT:
	1 1 0 1 0
	
	Nhin vao vi du tren ta thay , cong viec bd tai td 9 va ket thuc 11 la ok vi no k giao nhau voi cong viec 
	nao truoc do. 
	
	Huong giai quyet , minh se sanh thoi gian bat dau cua cong viec thu 2 so voi tg ket thuc cong viec truoc do ,
	neu thoi gian bat dau ma >= thoi gian ket thuc thi co nghia cong viec day tuong ho nhau. 
*/
#include<iostream>
using namespace std;

#define MAX 100
double s[MAX] , f[MAX];
int n;

void input(){
	cin>>n;
	for(int i = 0 ; i < n ; i++)
		cin>>s[i];
		
	for(int i = 0 ; i < n ; i++)
		cin>>f[i];	
}
void solve(){
	int i = 1 , j = 0 , cnt = 1;
	int jobs[n];
	
	//khoi tao cho cap thu nhat vao vi day la cap dau tien
	jobs[0] = 1;
	
	while(i < n){
		if(s[i] >= f[j]){
			jobs[cnt] = 1;
			j = i;
		}else{
			jobs[cnt] = 0;
		}
		i++;
		cnt++;
	}
	
	//in ra danh sach cap cong viec 
	for(int i = 0 ; i < n ; i++)
		cout<<jobs[i]<<" ";
}
int main()
{
	
	input();
	solve();
	return 0;
}
