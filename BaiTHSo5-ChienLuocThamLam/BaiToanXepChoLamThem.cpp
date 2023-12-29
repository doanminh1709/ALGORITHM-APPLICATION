/*
Bai toan:
	Cho xau ki tu s[] do dai n , va so tu nhien d 
	Hay sap dat lai cac ki tu trong sau s[] sao cho 2
	ki tu giong nhau deu dat giong nhau 1 khoang la d 
	Neu bai toan co nhieu nghiem dua ra cach giai dau tien 
	Neu khong in ra dong chu "NO SOLUTION";
	
	Y tuong bai toan : Su dung tham lam minh se di sap xep cac ki tu 
	ma co so lan xuat hien nhieu nhat len truoc
	
	Input :
	3
	ABB 2
	AAA 2
	GEEKSFORGEEKS 3
	
	Ouput:
	BAB
	NO SOLUTION
	EGKEGKESFESFO
	*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
int d , k = 0;
int cnt[256] = {0};
int cntAAppear[MAX];
char character[MAX];
char str[MAX];

void input(){
	cin>>str;
	cin>>d;
}	
void countAppearOfCharacter(){
	int n = strlen(str);
	
	for(int i = 0 ; i < n ; i++){
		cnt[(int)str[i]]++;
	}
	
	
	for(int i = 0 ; i < 256 ; i++){
		if(cnt[i] != 0){
			cntAAppear[k] = cnt[i];
			character[k] = (char)i;
			k++;
		}
	}
}
void merge(int A[], char S[], int l , int r , int mid){
	
	int i = l , j = mid + 1;
	int t = l;
	int Acp[r+1];
	char Scp[r+1];
	
	while(i <= mid && j <= r){
		if(A[i] > A[j]){
			Acp[t] = A[i];
			Scp[t] = S[i];
			t++;
			i++; 
		}else{
			Acp[t] = A[j];
			Scp[t] = S[j];
			t++;
			j++; 
		}
	}
	
	for(; i <= mid ; i++){
		Acp[t] = A[i];
		Scp[t] = S[i];
		t++;
	}
		
		
	for(; j <= r ; j++){
		Acp[t] = A[j];
		Scp[t] = S[j];
		t++;
	}
	
	for(int i = l ; i <= r ; i++){
		A[i] = Acp[i];
		S[i] = Scp[i];
	}	
}
void mergeSort(int A[] , char S[] , int l , int r){
	int mid;
	if(l < r){
		mid = (l + r)/2;
		mergeSort(A , S , l ,  mid);
		mergeSort(A , S , mid+1 , r);		
		merge(A , S , l , r , mid);
	}
}
void ouput(int A[] , char S[] , int n){
		
	for(int i = 0 ; i < n ; i++)
		cout<<S[i]<<" - "<<A[i]<<endl;
}
void solve(){
	//neu khong xep duoc vao tat ca cac vi tri thi dua ra NO SOLUTION 
	int l = strlen(str);
	char F[l];
	for(int i = 0 ; i < l ; i++)
		F[i] = ' '; 
		
	mergeSort(cntAAppear , character , 0 , k - 1);
	ouput(cntAAppear , character , k);	
	
	for(int i = 0 ; i < k ; i++){
		for(int j = i ; j < l ; j+=d){
			F[j] = character[i];
		}
	}
	bool check = true;
	for(int i = 0 ; i < k ; i++){
		cout<<F[i]<<" - "<<endl;
		if(!isalpha(F[i])){
			check = false;
		}
	}
	if(check == false) {
		cout<<"NO SOLUTION"<<endl;	
	}
	else{
//		cout<<F<<endl;	
	} 
}
int main(){

	input();
	countAppearOfCharacter();
	solve();
	
	return 0;
}


