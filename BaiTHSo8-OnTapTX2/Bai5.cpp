#include<bits/stdc++.h>
using namespace std;

#define MAXL 100

char str[MAXL][MAXL];
int A[MAXL];
char str_search[MAXL] = {'c', 'h', 'i', 'l' , 'd'};
int n , k;

void Init(){

	n = 5;	
	strcpy(str[0] , "child");
	strcpy(str[1] , "Ho ten toi la : ");
	strcpy(str[2] , "Toi hoc:");
	strcpy(str[3] , "Doan Minh");
	strcpy(str[4] , "Ho ten toi la : ");
	
	//khoi tao mang A 
	for(int i = 0 ; i < n ; i++){
		A[i] = strlen(str[i]);
	}
}
//sort theo do dai giam dan cua sau ki tu 
int find_partition( int l , int h)
{
	int pivot = A[l];
	
    int i = l , j = h;
    do{
        //Find element greater than pivot
        do{i++;}while(A[i] > pivot);

        //Find element lesser than pivot
        do{j--;}while(A[j] < pivot);

        //If i even less than j so swap A[i] and A[j]
        if(i < j){
        	swap(A[i] , A[j]);
			swap(str[i] , str[j]);
		} 
        //do while lap truoc va kiem tra dieu kien sau 
    }while(i < j);
    //Update partition
    swap(A[l] , A[j]);
    swap(str[l] , str[j]);
    return j;
}

void QuickSort(int l , int h){
    int index_partition ;

    if(l < h){
     index_partition = find_partition( l , h);
     QuickSort(l , index_partition);
     QuickSort(index_partition + 1 , h);
    }
}

void SolveA(){
	
	char new_str[MAXL];
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		if(k - A[i] >= 0){
			for(int j = 0 ; j < strlen(str[i]) ; j++){
				new_str[cnt++] = str[i][j];
			}
			k-=A[i];	
		}else{
			continue;
		}
	}
	cout<<new_str<<endl;
}

bool checkSubString(char T[] , char P[]){
	int v = strlen(P);
	char lt = strlen(T);
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
			return true;
		}
		else{
		//duyet trong P xem co su xuat hien cua T[i]
			while(T[i] != P[j] && j > -1){
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
	return false;
}

void SolveB(){
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		if(checkSubString(str[i] , str_search)){
			cnt++;
		}
	}
	cout<<"So xau trong d chua tu child : "<<cnt<<endl;
}

void Z_Algo(const char*s , int*z){
	int n = strlen(s) , left = 0 , right = 0;
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
int countAppear(char s[] , int n, int*z){
	int length = strlen(s);
	
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		if(z[i] == length) cnt++;
	}
	return cnt;
}
void SolveC(){

	for(int i = 1 ; i < n ; i++){
		char tmp[MAXL];
		strcpy(tmp , str[0]);
		strcat(tmp, "$"); 
        strcat(tmp, str[i]);
		int n = strlen(tmp);
		int z[n];
		Z_Algo(tmp , z);
		int cnt = countAppear(str[0] , n , z);
		if(cnt != 0){
			cout<<"Xau d[0] co xuat hien trong xau d["<<i<<"]";
			cout<<"- So lan xuat hien : "<<cnt<<endl;
		}else{
				cout<<"Xau d[0] k xuat hien trong xau d["<<i<<"]"<<endl;
		}	
	} 
}

int main(){
	cout<<"Nhap k : ";
	cin>>k;
	
	Init();
	QuickSort(0 , n  - 1);
	SolveA();
	
	SolveB();
	
	SolveC();
	
	return 0;
}
