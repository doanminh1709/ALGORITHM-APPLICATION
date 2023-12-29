#include<bits/stdc++.h>
using namespace std;

int TtBoyerMooreHorspool(char s[], char t[]) {
    int ls = strlen(s);
    int lt = strlen(t);

    int i = lt - 1;
    int cnt = 0;

    while (i < ls) {
        int j = lt - 1;

        while (s[i] == t[j] && j > -1) {
            i--;
            j--;
        }
        if (j == -1) {
        	if(i > 0 && !(s[i] >= '0' && s[i] <= '9')){
        		cnt++;	
			}
			i = i + lt*2;
        } else {
            while (s[i] != t[j] && j > -1) {
                j--;
            }
            if (j == -1) {
                i = i + lt;
            } else {
                i = i + lt - j - 1;
            }
        }
    }
    return cnt;
}

void replaceOccurrences(char s[], char t[], const char replacement[], int shiftAmount) {
    int ls = strlen(s);
    int lt = strlen(t);
    int lr = strlen(replacement);

    for (int i = 0; i < ls; i++) {
        if (strncmp(s + i, t, lt) == 0) {
		    int lastIdx = ls - 1;
            for (int j = 0; j < shiftAmount && lastIdx - shiftAmount + j < ls; j++) {
                s[lastIdx - shiftAmount + j + lr] = s[lastIdx - shiftAmount + j];
            }
            strncpy(s + i, replacement, lr);
            i += lr - 1;
        }
    }
    cout<<s<<endl;
}
int main() {
    char s[100] = {"toi co 1000, Nam co 1000, Dong co 1000 va 500"};
    char t[100] = {"1000"};

    cout << TtBoyerMooreHorspool(s, t) << endl;

	replaceOccurrences(s, t, "mot nghin",9);

    return 0;
}
