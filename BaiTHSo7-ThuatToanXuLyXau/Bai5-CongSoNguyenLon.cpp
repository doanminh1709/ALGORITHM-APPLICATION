#include<bits/stdc++.h>
using namespace std;

int main(){
	
	char m[200] = "1234643654545";
	char n[200] =  "567854534656";
	//output : 	   1802498189201

	int ml = strlen(m);
	int nl = strlen(n);
	
	int t[201]={0};
	int mt = 200;
	int k = mt;
	
	int i = ml - 1 , j = nl - 1;	
	int maxlength = ml > nl ? ml : nl;

	//Ban dau thi bien nho se bang 0 nen se nho tu vi tri thu 2 tu cuoi tro len 
	int bn = 0;
	while(maxlength--){
		
		int mi = 0 , nj = 0;
		
		if(i != -1) mi = m[i] - '0';
		if(j != -1) nj = n[j] - '0';
		
		//gia tri sau khi cong 2 gia tri tren 2 cot va gia tri bien nho 
		int bc = mi + nj + bn;
		
		//neu no lon hon 10 thi chi lay so hang don vi va gan lai bien nho 
        if (bc >= 10) {
        	bc %= 10;
            bn = 1;
        } else {
            bn = 0;
        }
        t[k--] = bc;
		i--; j--;
	}
	for(int i = k+1 ; i <= mt ; i++)
		cout<<t[i];			
	
	return 0;
}  	
