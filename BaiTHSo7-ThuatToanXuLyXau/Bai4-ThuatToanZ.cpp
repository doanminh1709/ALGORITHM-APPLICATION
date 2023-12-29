#include<bits/stdc++.h>
using namespace std;

//thuat toan z 
void ZAlog(string s , int *Z){
	
	//khoi tao l = r ban dau = 0 
	int l = 0, r = 0;
	int n = s.length();
	//duyet tu 1 -> n 
	for(int i = 1 ; i < n ; i++){
		//Khong co xau con nao bat dau truoc i va ket thuc sau i 
		//truong hop r < i 
		if(i > r){
			l = r = i;
			while(r < n && s[r - l] == s[r]){
				r++;
			}
			Z[i] = r - l;
			r--;
		}
		//Z[i-l..] giong voi Z[i..] n - i + 1 ki tu
		//truong hop r > i , voi th i - l < r - i + 1 ki tu thi co the tinh z[i] theo z[i-l]  
		else if(Z[i - l] < r - i + 1){
			Z[i] = Z[i-l];
		}
		//Neu ma Z[i-l] >= n - i + 1 thi gan lai l va di tim doan [left , right] moi 
		else{
			//truong hop con lai i - l > r - i + 1
			l = i;
			while(r < n && s[r - l] == s[r]){
				r++;
			}
			Z[i] = r - l;
			//sau khi gan xong thi phai giam r di 1 don vi de tinh cai vi tri ban dau 
			r--;
		}
	}
}
int countPrefix(int *Z , int n){
 	int maxPr = Z[0] , cnt = 0;
	for(int i = 0 ; i < n ; i++){
		maxPr = max(maxPr , Z[i]);
		cout<<Z[i]<<" ";		
	}
	cout<<endl;
	
	for(int i = 0 ; i < n ; i++)
		if(maxPr == Z[i]) cnt++;
	
	return cnt;
}
//lay ra tu dau tien 
string firstWord(string t){
	
	int lastIndex;
	for(int i = 0 ; i < t.length() ; i++){
		if((int)t[i] == 32){
			lastIndex = i; break;
		}
	}
	return t.substr(0 , lastIndex);
}
int main(){

	string t = "Lorem ipsum dolor sit amet,  Lorem sint Lorem occaecat Lorem non Lore proident, sunt in Lorem anim id est laborum.";
	string p = firstWord(t);
	string s = p + "$" + t;
	int n = s.length();
	int Z[n] = {-1};

	ZAlog(s , Z);
    cout<<"Tu '"<<p<<"'"<<" xuat hien "<<countPrefix(Z , n)<<" lan trong chuoi t"<<endl;
    
	return 0;
}
