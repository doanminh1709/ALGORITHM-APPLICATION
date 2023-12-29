#include<iostream>
#include<string>
using namespace std;

int findIndex(int startObserve , string str , string target){
	int t = str.length();
	int m = target.length();
	
	int n = t - m;
//	int i = startObserve;
	for(int i = startObserve; i <= n ; i++){
		int j = 0;
		while(j < m && str[i + j] == target[j]){
			j++;
		}
		if(j == m) return i;
	} 
	return -1;	
}

int countAppearSubstring(string str , string target){
	
	//bat dau tu chi so dau tien ma thang substring xuat hien  
	int index = findIndex(0 , str , target);	
	
	//neu tim thay thi minh co the cap nhat lai vi tri cua thang index de tim them cac thang phia sau  
	if(index != -1){
	//luc nay ta da co 1 phan tu 	
	int cnt = 1;
	//tang index len  
	index++;
	
	while(index != -1){
		//tinh lai index moi  
		index = findIndex(index , str , target);
		if(index != -1){
			cnt++;
			//cap nhat index tiep theo  
			index+=target.length();
			}
		}
		return cnt;		
	}
	return 0;
}

void replaceAllWorldChill(string &source , string target , string newWord){

	int targetLength = target.length();
	int sourceLength = source.length();
	
	//tim vi tri dau tien xuat hien cua index  
	int index = findIndex(0 , source , target);	
	
	//neu ma tim thay  
	while(index != -1){
		//xoa di so ki tu cu  
		source.erase(index , targetLength);
		//them tu moi vao  
		source.insert(index , newWord);
		//cap nhat lai vi tri index can tim  
//		index+=targetLength;
        index += newWord.length();

		//tim xem phia sau co chua tiep khong  
		index = findIndex(index , source , target);
	}
}

int main(){
	
	string str = "hello chill , my name is chill. Now, I am chill with chill. I really chill!";
	string target = "chill";
	string newWord = "children";
	
	cout<<"First index of word : "<<findIndex(0 , str , target)<<endl;
	cout<<"Count appear of word : "<<countAppearSubstring(str , target)<<endl;
	replaceAllWorldChill(str , target , newWord);
	
	cout<<"After replace : "<<str<<endl;
	return 0;
} 
