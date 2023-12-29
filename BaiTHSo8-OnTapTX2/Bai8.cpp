#include<bits/stdc++.h>
using namespace std;

int n;
struct Laptop{
	string brand;
	string config;
	double price;
};
void Init(Laptop d[]){
	n = 4;
	d[0] = {"HP" , "CPU 2.8GHz RAM 16GB-SSD 512GB" , 320000};
	d[1] = {"ACER" , "CPU 2.5GHz 3.5GHz-RAM 8GB-HDD 2TB" , 250000};
    d[2] = {"DELL", "CPU 2.8GHz 4.0GHz-RAM 16GB-SSD 256GB", 150000};  
    d[3] = {"MACBOOK", "CPU 2.6GHz 3.6GHz-RAM 8GB-SSD 256GB", 350000}; 
}

void Title(){
	cout<<left<<setw(15)<<"The brand"
		<<setw(40)<<"Information config"
		<<setw(10)<<"The price"<<endl;
}

void ShowDetail(Laptop item){
	cout<<left<<setw(15)<<item.brand
		<<setw(40)<<item.config
		<<setw(10)<<item.price<<endl;
}

int BMP(string T , string P){
	
	int cnt = 0;
	
	int v = P.length();
	int lt = T.length();
	int i = v - 1;
	
	while(i < lt){
		bool check = false;
		int j = v - 1;
		
		while(T[i] == P[j] && j > - 1){
			i--;
			j--;
			check = true;
		}
		if(j == -1){
			cnt++;
			break;
		}
		else{
		//duyet trong P xem co su xuat hien cua T[i]
			while(T[i]  != P[j] && j > -1){
				j--;
			}
			//kiem tra neu j == - 1 co nghia ki tu T[i] khong ton tai trong j
			if(!check && j == -1){
				i = i + v;
			}else{
				i = i + v - j - 1;
				}
			}			
		}
	return cnt;
}

void SolveA(Laptop d[]){
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		if(BMP(d[i].config , "RAM 16GB") != 0) cnt++;
	}
	cout<<"Co "<<cnt<<" laptop co RAM 16GB"<<endl;
}

void Z_Algo(string s , int*z){
	int n = s.length() , left = 0 , right = 0;
	for(int i = 1 ; i < n ; i++){
		if(i > right){
			left = right = i;
			while(right < n && s[right-left] == s[right])
				right++;
			z[i] = right - left; 
			right--;
		}else if(z[i-left] < right - i + 1){
			z[i] = z[i-left];
		}else{
			left = i;
			while(right < n && s[right - left] == s[right])
				right++;
				z[i] = right - left; right--;
		}
	}	
}

void SolveB(Laptop d[]){
	
	cout<<"Danh sach cac laptop co o cung la SSD "<<endl;
	Title();
	for(int i = 0 ; i < n ; i++){
	  string type = "SSD$";
	  int length = type.length();
	  string tmp = type.append(d[i].config);
	  int m = tmp.length();
	  int z[m];
	  Z_Algo(tmp , z);
	
	  for(int j = 0 ; j < m ; j++){
	  	if(z[j] == length - 1){
	  		ShowDetail(d[i]);
	  		break;
		  }
	  }		
	}	
}
int main()
{
	
	Laptop d[4];
	Init(d);
	
	SolveA(d);
	
	SolveB(d);
	
	return 0;
}
