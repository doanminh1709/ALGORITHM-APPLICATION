//cho 1 so tu 0 ~ 99999 
//thay doi day theo de bai yeu cau theo cac cau lenh 

//I(insert) : x , y , s : them y so vao truoc vi tri x trong day ban dau , s la danh sach y so can them 
//D(delete) : x ,y : Xoa y so dang sau vi tri x 
/*
Test
Input:
	A[] = 
	10
	5 9 4 6 7 8 1 3 2 0
	4
	D 3 3 
	D 1 4 
	I 2 3 6 9 8 
	I 4 1 1

Output:
B1:	5 9 4 1 3 2 0
B2: 5 2 0
B3: 5 2 6 9 8 0
B4: 5 2 6 9 1 8 0
*/

#include<iostream>
using namespace std;

int main(){
	
	int N;//so phan tu cua mang 
	cin>>N;
	
	int Fes[N+1000];
	
	for(int i = 0 ; i < N ; i++)
		cin>>Fes[i];
	
	int Q;cin>>Q;
	for(int i = 1 ;i <= Q ; i++){
		char c; 
		cin>>c;
		int x , y;
		cin>>x>>y;
		if(c == 'I'){
			int Insert[y];
			for(int i = 0 ; i < y ; i++){
				cin>>Insert[i];	
			}
		
			//Them y so dang truoc vi tri x 
			for(int i = N ; i >= x; i --){
				Fes[i + y] = Fes[i]; 
			}
			
			//Chen vao
			N += y;
			int j = 0; 
			for(int i = x ; i < x + y ; i++){
				Fes[i] = Insert[j];
				j++;
			}
		}
		
		if(c == 'D'){
			//Xoa Y so dang sau vi tri x 
			for(int i = x ; i < N ; i++){
				Fes[i]  = Fes[i+y];
			}
			//cap nhat lai N
			N -= y;
		}
	}
	
	for(int i = 0 ; i < N ; i++)
		cout<<Fes[i]<<" ";	
	cout<<endl;
	
	return 0;
}
