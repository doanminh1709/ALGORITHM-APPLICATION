#include<bits/stdc++.h>
using namespace std;

void generate(int n)
{
    char str[n] = {};
    //Khoi tao cau hinh ban dau
    for(int j = 0 ; j < n ; j++){
        str[j] = 'a';
    }

    int i;
    do{
      // In ra cau hinh ban dau
      for(int j = 0 ; j < n ; j++){
            cout<<str[j];
      }
      i = n - 1;
      cout<<endl;
      // Duyet tu cuoi ve den khi gap cau hinh dau tien bang a
      while(i >= 0 && str[i] == 'b'){
            i--;
      }
      //Doi cau hinh do bang b
      str[i] = 'b';
      //Chuyen tat ca cau hinh o phia sau no bang a
      int j = i + 1;
      for(int k = j ; j < n ; j++){
        str[j] = 'a';
      }
    }while(i >= 0);
}

int main()
{
    generate(4);
    return 0;
}
