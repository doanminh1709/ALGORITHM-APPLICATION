#include<bits/stdc++.h>
using namespace std;

struct CongViec{
	string macv;
	double tgbd;
	double tgkt;
};
void Init(CongViec mcv[]){
	mcv[0] = {"CV1" , 8.3 , 9.6};
	mcv[1] = {"CV2" , 2.50 , 6.4};
	mcv[2] = {"CV3" , 4.15 , 6.3};
	mcv[3] = {"CV4" , 6.2 , 7.5};
	mcv[4] = {"CV5" , 1.2 , 3.2};
	mcv[5] = {"CV6" , 4.6 , 6.4};	
	mcv[6] = {"CV7" , 5.3 , 7.4};
}
double SumOfAllWork(CongViec mcv[] , int  l , int r){
	double sum = 0;
	if(n == -1) return sum;
	sum = (mcv[n - 1].tgkt - mcv[n - 1].tgbd);
	return sum + SumOfAllWork(mcv , n - 1);
//	if(l > r){
//		return sum;
//	}  
//	sum = (mcv[l].tgkt - mcv[l].tgbd);
//	return sum + SumOfAllWork(mcv ,l + 1 , r);
}
int sumOfArr(int a[] , int n){
	int sum = 0;
	if(n == -1) return sum;
	sum = a[n -1];
	return sum + sumOfArr(a , n-1);
}
int main()
{
	CongViec mcv[7];
	Init(mcv);
	cout<<SumOfAllWork(mcv , 0 , 6);

	int a[4] = {1 , 3 , 2 , 3};
//	cout<<sumOfArr(a , 4);
}
