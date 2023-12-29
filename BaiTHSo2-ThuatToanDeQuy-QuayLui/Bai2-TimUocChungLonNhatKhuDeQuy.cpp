#include<iostream>
using namespace std;
int ucln(int a , int b)
{
    while(a != b){
        if(a > b){
            a-=b;
        }else {
            b-=a;
        }
    }
    return a;
}
int main(){
	
	int a = 4 , b = 8;
	cout<<ucln(a , b)<<endl;
	
	return 0;
} 
