#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int Building[n];
	
	for(int i = 0 ; i < n ; i++)
		cin>>Building[i];
		
	int count = 0;
	int hightest = 0;
	
	for(int i = 1 ; i < n - 2 ; i++){
		int a = Building[i-2];
		int b = Building[i-1];
		int c = Building[i+1];
		int d = Building[i+2];
		
		int hightest = max(max(a , b) , max(c,d));
		if(Building[i] >= hightest + 2){
			count += (Building[i] - hightest);
		}
	}
	cout<<count<<endl;
	
	return 0;
}
