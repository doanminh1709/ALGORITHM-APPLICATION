#include<iostream>
#include <iterator>
#include<string>
using namespace std;
/*
	Ý tuong cua thuat toan BoyerMooreHorpool 
		- So sanh nguoc tu ky tu cuoi cua P tro ve dau 
		- Gia su vi tri bat dau so sanh trong T la i , vi tri cua cung 
		  cua P la P[v] = (v = strlen(P) - 1) 
		- So sanh T[i] va P[v] va dich chuyen ve dau 
		- Neu viec khop tung ky tu vuot qua duoc P[0] thi co nghia P co mat trong T 
		Nguoc lai T[i] != P[v] 
			+ Neu T[i] khong xuat hien trong P thi i = i + v
			+ Nguoc lai (T[i] co trong P) : goi x la vi tri xuat hien dau tien cua T[i] trong P 
			(T[i] = P[x]) , thi i = i + v - x - 1; 
*/

int algoBoyer(int start , string s , string target){
	
	int v = target.length();
	int n = s.length();
	int i = start;
	
	while(i < n){
		int j = v - 1;
		
		while(j >= 0  && s[i] == target[j]){
			j--;
			i--;
		}
		if(j == -1) return i+1;
		while(j >= 0 && s[i] != target[j]){
			j--;
		}
		if(j == -1) i = i + v;
		else i = i + v - j - 1;
	}
	return -1;
}

bool isTrulyWord(int index , string s , string target){
	
	int lt = target.length();	
	if(index == 0){
		int tmp = index + lt;
		if((int)s[lt] == 32 || (int)s[lt] == 0){
			return true;
		}
	}else{
		if((int)s[index-1] == 32 && 
		((int)s[index + lt] == 32 || (int)s[index+lt] == 0)){
			return true;
		}
		return false;
	}
	return false;
}
int countAllWord(string s , string target){
	int cnt = 0;
	int lt = target.length();
	int index = algoBoyer(lt - 1, s, target);

	while(index != -1){
		if(index != - 1 && isTrulyWord(index , s , target)){
		    cnt++;
		}
		index = algoBoyer(index + lt , s, target);
	}
	return cnt;
}

void replaceAllWord(string &s , string target , string newWord){
	
	int lt = target.length();
	int index = algoBoyer(lt - 1, s, target);
		
	while(index != -1){
		//kiem tra neu dung la tu can tim thi se thay the 
		if(isTrulyWord(index , s , target)){
			s.erase(index , lt);
		    s.insert(index , newWord);
		}
		//cap nhat lai cai vi tri index co nghia la cai vi tri ma bat dau kiem tra 
		//chinh la cai bang chi so index cong vi do dai chuoi lt 
		index = algoBoyer(index + lt , s, target);
	}
}

int main(){

	string s = "toi co 1000 , Nam co 21000 , Dong co 1000 va 1000";	
	string target = "1000";
	string newWord = "mot nghin";
	
	cout<<countAllWord(s , target)<<endl;
	
	cout<<algoBoyer(target.length() - 1 , s , target)<<endl;
	
	replaceAllWord(s , target , newWord);
	cout<<s<<endl;
	
	return 0;
} 
