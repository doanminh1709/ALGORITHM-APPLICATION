#include<bits/stdc++.h>
using namespace std;

void ShowConfig(int cnt[] , string names[], char*tags, int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		cout<<" : ("<<names[cnt[i]]<<" : "<<tags[cnt[i]]<<") ";
	}
	cout<<endl;
}
//Su dung thuat toan sinh hoan vi
void NextConfig(int a[], string names[] , char*tags , int n , int i){
 	int k = n - 1;
 	
 	while(a[i] > a[k]){
 		k--;
	 }
	swap(a[i] , a[k]);
	 
	 //Sap xep tat ca chuoi o sau tang dan 
	int j = n - 1; i++;
	while(i < j){
    	swap(a[i] , a[j]);
	 	i++; j--;
	}
}
void generate(string names[] , char*tags , int n , int &cnt){	
	//In ra cau hinh cau tien 
	int i;
	int a[n];
	for(int j = 0 ; j < n ; j++){
		a[j] = j;  		
	}
	do{
		cout<<"Cach "<<cnt + 1<<" : ";
		ShowConfig(a , names , tags , n);
		cnt++;
		i = n - 2;
	    //Lap tu cuoi ve dau tim day con giam dan dai nhat 
		while(i >= 0 && a[i] > a[i+1]) i--;
		
		if(i >= 0){
			NextConfig(a , names , tags , n , i);
		}
	}while(i >= 0);
}

//Su dung quay lui 
void Try(string view_names[] ,char*view_tags, string names[], bool mark[] ,
		 char*tags , int n , int k , int &cnt){
	
	//Buoc 1 : Kiem tra neu da du dieu kien in ra duoc 1 cau hinh 
	if(k == n){
		cout<<"Cach "<<cnt + 1;
		ShowConfig(view_names , view_tags , n);
		cnt++;
		return;
	}
	//Tiep tuc kiem tra de in ra cau hinh 
	for(int i = 0 ; i < n ; i++){
		if(!mark[i]){
			mark[i] = true;
			view_names[k] = names[i];
			view_tags[k] = tags[i];
			Try(view_names , view_tags , names , mark , tags , n , k + 1 , cnt);
			mark[i] = false;
		}
	}
}
int main()
{
	int n = 4 , cnt = 0 , cnt2 = 0;
	string names[n] = { "tung", "cuc", "truc","mai" };
	char tags[n] = {'A' , 'B' , 'C' , 'D'};
	
	
	bool mark[n] = {false};
	string view_names[n];
	char view_tags[n];
	
	//cout<<"\nSu dung quay lui de giai "<<endl;
	//Try(view_names ,view_tags , names , mark , tags , n , 0 , cnt);

	//cout<<"\nTong so cach xep : "<<cnt<<endl;
	
	cout<<"\nSu dung phuong phap sinh de giai"<<endl;

	//Before generate need sort array ads 
	generate(names , tags , n , cnt2);
	cout<<"\nTong so cach xep : "<<cnt2<<endl;

	return 0;
}
