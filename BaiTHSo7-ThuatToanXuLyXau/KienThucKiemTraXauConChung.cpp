#include<bits/stdc++.h>
using namespace std;

int checkSubString(const char*a , const char*b){
	int m = strlen(b);
	int n = strlen(a) - m;
	
	//Su dung vet can de kiem tra het tat ca truong hop xem day con b con trong day a
	//co nghia minh se su truot day b o tren day a tu dau den cuoi 
	//kiem tra 1 truong hop neu khong thoa man thi se truot den vi tri tiep theo 
	//Minh se chi can truot n - m lan 
	for(int i = 0 ; i < n ; i++){
		int j = 0;
		while(j < m && b[j] == a[i + j]){
			j++;
		}
		//Neu tra ve vi tri dau tien bat dau cua day con 
		cout<<"j" <<j<<endl;
		if(j == m){
			return i;
		}
	}	
	return -1;
}
int main()
{
	
	const char a[12] = {'A' , 'B' , 'C', 'E' , 'D', 'E' , 'G', 'L', 'O', 'W' , 'K' , 'M'};
	const char b[4] = {'O' , 'W' , 'K' , 'M'};
	
	int index = checkSubString(a , b);
	if(index != -1){
		cout<<"\nB la sau con cua A";
	}else{
		cout<<"\nB khong la sau con cua A";
	}
	return 0;
}
