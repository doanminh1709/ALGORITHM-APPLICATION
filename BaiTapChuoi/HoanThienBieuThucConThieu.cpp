#include<iostream>
using namespace std;

//tim vi tri cua dau = 
int indexEqualSign(string s){
	for(int i = 0 ; s.length() ; i++){
		if(s[i] == '=') return i;
	}
	return -1;
}
//tim vi tri cua dau cong 
int indexPlus(string s){
		for(int i = 0 ; s.length() ; i++){
		if(s[i] == '+') return i;
	}
	return -1;
}
//tim vi tri cua chu cai dau tien 
int firtCharacter(string s){
		for(int i = 0 ; s.length() ; i++){
		if(s[i] >= 'a' && s[i] <= 'z') return i;
	}
	return -1;
}

void handle(string s){
	if(s.length() == 0) return;
	
	int ies = indexEqualSign(s);
	int idp = indexPlus(s);
	int fcr = firtCharacter(s);

	//th chi so bat dau cua chu cai > chi so bang 
	int item1 = 0 , item2 = 0;
	if(fcr > ies){
	
		for(int i = 0; i < ies ; i++){
			if(s[i + 1] == '+') break;
			if(s[i]>= '0' && s[i] <= '9')
			item1 = item1*10 + s[i] - '0';
		}
		
		for(int i = idp + 1 ; i < ies ; i++){
			if(s[i+1] == '=') break;
			if(s[i]>= '0' && s[i] <= '9')
			item2 = item2*10 + s[i] - '0';
		}
		cout<<item1<<" + "<<item2 <<" = "<<(item1+item2)<<endl;
	}else{
		
		if(fcr < idp){
			for(int i = idp ; i < ies ; i++){
				if(s[i+1] == '=') break;
				if(s[i]>= '0' && s[i] <= '9')
				item1 = item1*10 + s[i] - '0';
			}
			
			for(int i = ies ; i <= s.length() ; i++){
				if(s[i]>= '0' && s[i] <= '9')
				item2 = item2*10 + s[i] - '0';
			}
			cout<<(item2 -item1)<<" + "<<item1 << " = "<<item2<<endl;
			
		}else{
			
			for(int i = 0 ; i < idp ; i++){
				if(s[i + 1] == '+') break;
				if(s[i]>= '0' && s[i] <= '9')
				item1 = item1*10 + s[i] - '0';
			}
			for(int i = ies ; i <= s.length() ; i++){
				if(s[i]>= '0' && s[i] <= '9')
				item2 = item2*10 + s[i] - '0';
			}
			cout<<item1<<" + "<<item2 - item1 << " = "<<item2<<endl;	
		}	
	}
}
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	cout<<endl;
	while(t>0){
		string s;
		getline(cin , s);
		handle(s);	
		t--;
		cout<<endl;
	}
	return 0;
}
