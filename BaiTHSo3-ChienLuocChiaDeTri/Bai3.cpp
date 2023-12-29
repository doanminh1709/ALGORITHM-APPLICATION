#include <iostream>
using namespace std;
//Tim phan tu lon nhat trong mang bang thuat toan chia de tri 
double findMax(double a[] , int l , int r){
	//Neu mang chi con 1 phan tu 
	if(l == r){
		return a[l];
	}
	//Chia day thanh nua trai va nua phai tim max o 2 nua va so sanh 
	if(l + 1 == r){
		return a[l] > a[r] ? a[l] : a[r];
	}else{
		int mid = (l + r)/2;
		double maxLeft = findMax(a , l , mid);
		double maxRight = findMax(a , mid + 1 , r);
		return maxLeft > maxRight ? maxLeft : maxRight;
	}
}

int main(){

	int n = 5;
	double arr[n] = {2.4 , 8.3 , 5.2 , 3.2 , 4};
	double max = findMax(arr , 0 , n - 1);
	cout<<"Max = "<<max<<endl;
}
