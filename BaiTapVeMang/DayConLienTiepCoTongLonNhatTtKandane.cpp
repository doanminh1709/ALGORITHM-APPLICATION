#include<iostream>
using namespace std;

#define ll long long
//Y tuong cua thuat toan la quy hoach dong 
//cu cong don tat ca day con , neu no < 0 thi reset no ve 0 
//ta se dung 2 bien , 1 la sum1 la de tinh tong con ket thuc tai i, con sum2 de luu lai ki luc 
int cnt[1000001] = {0};
int n;

ll max(ll a , ll b){
	return a < b ? b : a;
}

int main()
{
	
	cin>>n;
	for(int i = 0 ; i < n ; i++)
		cin>>cnt[i];
		
	ll sum1 = 0 , sum2 = -1e18;
	for(int i = 0 ; i < n ; i++){
		sum1+= cnt[i];
		sum2 = max(sum2 , sum1);
		if(sum1 < 0) sum1 = 0;
	}
	
	cout<<sum2<<endl;
	return 0;
}
