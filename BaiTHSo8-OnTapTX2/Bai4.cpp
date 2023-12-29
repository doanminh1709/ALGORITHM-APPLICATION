#include<bits/stdc++.h>
using namespace std;

typedef long double lb;
int s;
int n = 6;

struct Phone{
	string brand;
	int size;
	int price;
	
};
void Init(Phone d[]){
	
	d[0] = {"SamSung" , 5, 150000};
	d[1] = {"Sony" , 4 , 450000};
	d[2] = {"Panasonic" , 7 , 200000};
	d[3] = {"Tosypa" , 6 , 350000};
	d[4] = {"Nokia" , 1 , 240000};
	d[5] = {"Apple" , 2, 300000};

}
void Solve(Phone d[] , long fes[][100]){
	
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= s ; j++){
			if(i == 0 || j == 0){
				fes[i][j] = 0;
			}else{
					//Neu gia su khong lay
					fes[i][j] = fes[i-1][j];
					//co lay san pham ay 
					if(j - d[i-1].size >= 0){
						fes[i][j] = max(d[i-1].price + fes[i-1][j - d[i-1].size], fes[i-1][j]);
					}
				}			
			}
		}

	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= s; j++){
			cout<<fes[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<fes[n][s]<<endl;
}
void output(Phone p){
		cout<<left<<setw(20)<<p.brand
		<<setw(15)<<p.size
		<<setw(20)<<p.price
		<<endl;
}
void Tv(Phone d[] , long fes[][100]){
	///2 + 1 + 6 + 4 + 5 = 104 
	
	int i = n - 1;
	int j = s;
		
	while(i!=0){
		if(fes[i][j] != fes[i-1][j]){
			j-=d[i].size;
			output(d[i]);
		}
		i--;
	}
}
int main(){
	
	cin>>s;
	
	long fes[n+1][100];
	
	Phone d[n];
	Init(d);
	Solve(d , fes);
	Tv(d , fes);
	
	return 0;
}
