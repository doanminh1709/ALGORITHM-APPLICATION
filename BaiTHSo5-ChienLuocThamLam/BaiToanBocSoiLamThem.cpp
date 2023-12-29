/*
Boc soi:
	Ban se tham gia mot tro choi , nhiem vu cua ban se chien thawng may , moi 1 trang dau 
	se co n vien soi , bn duoc boc ra 1 , 2 , 3 , ... , m vien. Moi nguoi boc 1 lan roi den 
	nguoi kia boc. Dau vao dua ban 2 so n, m. Ban duoc di truoc va kiem tra xem ban co luon 
	chien thang duoc khong ?
	
	//Nguoi chien thang la nguoi duoc boc cuoi cung 
	
	kiem tra xem neu so soi con lai ma lon hon m thi se boc toi uu , con khong thi se boc so gan bang m nhat 

*/

#include<iostream>
using namespace std;

int main(){
	
	int n , m; 
	cin>>n>>m;
	
	int i = 1;
	while(n >= m && i++){
		//minh la nguoi duoc choi truoc
		n-=m;
		if(m > n && n > 0){
			n = m;
		} 
	}
	if(i % 2 == 0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}
