#include<iostream>
using namespace std;

void show_config(int arr[] , int n)
{
	for(int i = 0 ; i < n ; i++)
		cout<<arr[i]<<" ";
		cout<<endl;
}
void swap(int &a, int &b){
	int tg = a;
	a = b;
	b = tg;
}
void next_config(int arr[] , int n , int i)
{
	int k = n - 1;
	
	//Tim phan tu dau tien lon hon arr[i] tu cuoi ve dau 
	while(arr[i] > arr[k]){
		k--;
	}

	//Thoat vong while la da tim thay 
	//Doi cho arr[i] va arr[k]
	swap(arr[i] , arr[k]);
	
	//Dao nguoc day tu i+1 den n - 1
	int j = n - 1;
	i++;
	while(i < j){
		swap(arr[j] , arr[i]);
		i++; j--;
	}
}
void generate(int arr[] , int n)
{
	int i, cnt = 0;
	do{
		show_config(arr , n);
		//Khoi tao i 
		i = n - 2;
		while(i >= 0 && arr[i] > arr[i+1]) i--;
		
		//Neu tim thay thi goi ham doi cho va sap xep  
		if(i >= 0){
			next_config(arr , n , i);
		}
		cnt++;
	}while(i >= 0);
	cout<<"Co tat ca : "<<cnt<<" cau hinh"<<endl;
}
int main()
{
	int n = 4;
	int arr[n] = {0, 1, 2 , 3  , 4 , 5};
	generate(arr , n);
	return 0;
}
