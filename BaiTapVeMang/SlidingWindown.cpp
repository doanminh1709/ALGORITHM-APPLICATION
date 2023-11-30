#include<iostream>
using namespace std;

//Tinh tong lon nhat cua day con co k phan tu lien tiep 

int main(){
	
	int t;cin>>t;
	while(t--){
		int n , k; cin>>n>>k;
		
		int a[1001];
		for(int i = 0 ; i < n ; i++)cin>>a[i];
		
		int sum = 0, id;
		
		//tinh cua so dau tien 
		for(int i = 0 ; i < k ; i++){
			sum+=a[i];
		}
		
		//tinh cac cua so tiep theo , chinh la bang cua truoc no ,
		// tru di phan tu thua va cong phan tu o sau cung 
		int res = sum;
		
		for(int i = k ; i < n ; i++){
			sum = sum - a[i - k] + a[i];
			if(sum > res){
				res = sum;
				id = i - k + 1;
			}
		}
		
		cout<<res<<endl;
		for(int j = 0 ; j < k ; j++){
			cout<<a[j+k]<<" ";
		}	
	}
	return 0;
}
