#include<bits/stdc++.h>
using namespace std;

//m la so tien can doi 
//n la so to tien 

//Kiem tra xem neu so tien f(i) (i <= m) thi co the doi duoc it nhat bao nhieu to 

//De duoc so tien la i co cach de tao thanh so tien do khi chung ta them 1 to la 
// i - c[k1] , i - c[k2] , ... , i - c[kj] , kj la so thoa man c[kj] < i   

//So tien toi uu nhat can tim trong cac f(i - c[k1]) + 1 , f(i-c[k2]) + 1, ... , f(i-c[kj]) + 1
 
int main(){
	
	int n = 5;//so to tien 
	int m = 9;//so menh gia 
	
	int a[n] = { 1 , 2 , 3 , 5 , 10};
	
	int f[n] , min;
	int s[100];
	f[0] = 0;
	//kiem tra tung gia tri tu 1 den m 
	for(int i = 1 ; i <= m ; i++){
		min = INT_MAX;
		//duyet tat ca cac to tien co de lay ra so to tien toi uu cho tung gia tri i 
		for(int j = 0 ; j < n ; j++){
			//chi kiem tra nhung to tien nao ma gia tri cua no nho hon gia tri dang kiem tra 
			if( a[j] <= i && f[i - a[j]] + 1 < min){
				//moi mot so tien i ta se tim so to tien it nhat co the lay 
				min = f[i - a[j]] + 1;
				//j la to tien thoa man
				s[i] = j;	
			}
		}
		f[i] = min;
		cout<<s[i]<<" - ";
	}
	//s la mang chua dung loai tien nao can dung cuoi cung de dat duoc so tien i 
	//truy vet cac loai tien can dung bang mang s
	int j = s[m-1];// 3
	cout<<endl<<f[m-1];
	int i = m;//9 
	cout<<"\nDung to : ";
	while(j != 0){
		cout<<a[j]<<" ";
		i = i - j;
		j = s[i];
	}
		
	cout<<endl<<min;
	return 0;
}
