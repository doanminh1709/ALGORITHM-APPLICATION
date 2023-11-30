#include<iostream>
#include<string.h>
#define N 10
#define M 1000
using namespace std;

int countSubString(char s1[] , char s2[]){
     int ls1 = strlen(s1);
     int ls2 = strlen(s2);
    
     int m = ls2 - ls1;
    
     int cnt = 0;
     for(int i = 0 ; i <= m ; i++){
     	 int k  = 0;
         for(int j = 0 ; j < ls1 ; j++){
			if(s1[j] == s2[i+j]) k++;
			else break;
         }
         if(k == ls1){
             cnt++;
         }
     }
     return cnt;    
 }
int main() {

	int cnt = 1;
    while (cnt < 11) {
    	int stt;
    	cin>>stt;
		cin.ignore();
		
		if(stt > 10) break;
		
        char s1[N];
        char s2[M];

        cin.getline(s1, N);
        cin.getline(s2, M);

        cout << "#" << stt << " " << countSubString(s1, s2) << endl;
    	cnt++;
	}
}

/*
#include<iostream>
#include<string.h>
#define N 10
#define M 1000
using namespace std;

void computeLPSArray(char s1[], int lps[], int ls1) {
    int length = 0;
    int i = 1;
    lps[0] = 0;

    while (i < ls1) {
        if (s1[i] == s1[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int countSubString(char s1[], char s2[]) {
    int ls1 = strlen(s1);
    int ls2 = strlen(s2);

    int lps[ls1];
    computeLPSArray(s1, lps, ls1);

    int cnt = 0;
    int i = 0, j = 0;

    while (i < ls2) {
        if (s1[j] == s2[i]) {
            j++;
            i++;
        }

        if (j == ls1) {
            cnt++;
            j = lps[j - 1];
        } else if (i < ls2 && s1[j] != s2[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return cnt;
}

int main() {
	int cnt = 1;
    while (cnt < 11) {
        int stt;
        cin >> stt;
        cin.ignore();

        if (stt > 10) break;

        char s1[N];
        char s2[M];

        cin.getline(s1, N);
        cin.getline(s2, M);

        cout << "#" << stt << " " << countSubString(s1, s2) << endl;
    	cnt++;
	}

    return 0;
}


*/
