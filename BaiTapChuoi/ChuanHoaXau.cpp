/*
Cài dat chuong trinh thuc hien 
-Khoi tao 1 doan tieng anh khong co qua 50 tu 
-Cho biet co bao nhieu tu child tren doan van nhap vao bang chien luoc ven can 
- Thay the tat ca tu child trong doan van bang tu children*/

#include<bits/stdc++.h>
using namespace std;

int countWord(string s , string t){
	
	int cnt = 0;
	
	int lengthS = s.length();
	int lengthT = t.length();
	
	int n = lengthS - lengthT;
	
	for(int i = 0  ; i < n ; i++){
		
		int j = 0;
		while(j < lengthT && s[i+j] == t[j]){
			j++;
		}
		if(j == lengthT){
			cnt++;
		}
		i+=j;

	}
	return cnt;
}

int main(){
	
	string s = "hello cac em nho den tu vung cao nguyen child cac chill den tu nhung ngoi nha tren nui cac em la child cua dat nuoc";
	string t = "child";
	
	cout<<countWord(s , t)<<endl;
	return 0;
}
