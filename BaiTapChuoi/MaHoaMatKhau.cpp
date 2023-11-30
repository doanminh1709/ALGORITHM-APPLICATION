//string   Input: 1234555432290 => Output : 10
//lien quan den ki thuat them sua xoa chen phan tu trong mang 
#include<iostream>
#include<string.h>
using namespace std;
#define MAXL 100

int main(){
	
	char S[MAXL];
	
	cin.getline(S , MAXL);
	
	int ls = strlen(S);
	
	int start , end;
	//duyet den ls - 1 vi khi duye den ls thi vi tri ls + 1 se nam ngoai mang 
	for(int i = 0 ; i < ls - 1 ; i++){
		
		if(S[i] == S[i+1]){
			start = i;
			//tang j len i + 1 de tim cap tiep theo xem co bang nhau khong 
			int j = i + 1;
			while(true){
				if(S[j] == S[j+1]){
					j++;
				}else{
					end = j;
					break;
				}	
			}
			//khoang cach tu end - start = end - start + 1
			int kc = end-start+1;
			
			for(int t = end + 1 ; t < ls ; t++){
				S[t - kc] = S[t];
			} 
			//cap nhat lai do dai mang 
			ls = ls - kc;
			//vi khi co 2 phan tu bang nhau thi ta se xoa ca 2 phan tu day nen do dai cua i se giam di 2 
			i-=2;
		}
	}	
	
	for(int i = 0 ; i < ls ; i++)
		cout<<S[i];
	
	return 0;
}

