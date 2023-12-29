#include<bits/stdc++.h>
using namespace std;

/*
Phuong phap : Su dung mang prefix 
	- Duyet chuoi i tu 1 den n - 1 (mang bat dau tu 0)
	- Moi vi tri i thi ta se quan ly 1 doan [left -> right] voi right lon nhat co the sao cho 
	  xau con tu left -> right la xau tien to cua S 
	- Ban dau left = right = 0
	- Gia su o i ta co doan [left, right] cua vi tri i - 1 va da tinh duoc nhung gia tri tri z truoc do 
	- So sanh i voi r
	 	Neu i > r
	 		+ Khong co xau tien to nao bat dau truoc i va ket thuc sau i 
	 		Xu ly :
	 			Gan l = r = i;
	 			Kiem tra tu cai doan la tu 0 -> r , r thi se lien tuc tang len va vi tri r - l thi
	 				cung ty le thuan nhu vay 
	 			Neu 2 gia tri nay ma khac nhau thi se cap nhat lai gia tri z[i] va giam r di cho no 
	 			dung tai cai vi tri cuoi cung ma s[r-l] = s[r]
	 	Neu i < r 
	 		Xu ly : 
	 			Th1 : Ta thay xau s[i-l..] va s[i..] giong nhau it nhat o r - i + 1 vi tri nen ta co the 
	 				tan dung tk nay de tinh Z[i] = Z[i-l]
	 			Th2 : Neu Z[i-l] >= right - i + 1 (Co nghia la tai vi tri nay thi gia tri cua cai Z no da lon hon
	 				  cai do dai cua cai gia tri Z da tinh truoc do (co 1 xau tien to khac no lon hon)
	 			
	 				Luc nay da tan dung de tinh duoc nhung gia tri z co the va i  , l < r  , ta tiep tuc 
	 				tang r len de tinh xem cac kha nang tu vi tri r - l so voi vi tri r da tang len va cap nhat
	 				lai gia tri r 
	 				
	 	Sau 
	
	  
*/
void ZAlog(string s , int *z){
	int n = s.length(), left = 0 , r = 0;
	
	int l = r = 0;
	for(int i = 1 ; i < n ; i++){
		if(i > r){
			l = r = i;
			while(r < n && s[r - l] == s[r]){
				r++;
			}	
			z[i] = r - l;
			r--;
		}else if(z[i - l] < r - i + 1){
			z[i] = z[i-l];
		}else{
			l = i;
			while(r < n && s[r - l] == s[r]){
				r++;
			}	
			z[i] = r - l;
			r--;
		}
		
	}
}
int countPrefix(int *Z , int n){
 	int maxPr = Z[0] , cnt = 0;
	for(int i = 0 ; i < n ; i++) maxPr = max(maxPr , Z[i]);
	
	for(int i = 0 ; i < n ; i++)
		if(maxPr == Z[i]) cnt++;
	
	return cnt;
}
int main(){

	string t = "Lorem ipsum dolor sit amet,  Lorem sint occaecat Lorem non proident, sunt in culpa qui officia deserunt Lorem anim id est laborum.";
	string p;
	size_t pos = t.find_first_of(" \t");
	
    if (pos != std::string::npos) {
        p = t.substr(0, pos);   
    }

	int i = 0;
	string s = p + "$" + t;
	int n = s.length();
	int Z[n] = {-1};
	ZAlog(s , Z);
	
    cout<<countPrefix(Z , n);
    
	return 0;
}
