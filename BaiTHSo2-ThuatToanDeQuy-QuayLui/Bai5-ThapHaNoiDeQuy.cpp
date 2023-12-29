#include<iostream>
using namespace std;
void thap_ha_noi(int n , char a , char b , char c)
{
    //Th co so neu chi co 1
    if(n == 1){
        cout<<"Chuyen 1 dia tu "<<a<<" ->"<<b<<endl;
    }else{
    //Th1 : Chuyen n - 1 dia tu A -> B voi C lam cot trung gian
     thap_ha_noi(n - 1 , a , c , b);

    //Th2 : Chuyen 1 dia tu A -> B
    thap_ha_noi(1 , a , b , c);

    //Th3 : Chuyen n - 1 dia tu C -> B voi A la cot trung gian
    thap_ha_noi(n - 1 , c , b , a);
    }

}
int main(){
	thap_ha_noi(3 , 'A' , 'B' , 'C');
	return 0;
} 
