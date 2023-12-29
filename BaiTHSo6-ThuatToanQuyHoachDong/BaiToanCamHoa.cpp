#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeBeauty(int n, int k, const vector<vector<int>>& v) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            for (int l = 1; l <= i; ++l) {
                dp[i][j] = max(dp[i][j], dp[i - l][j - 1] + v[i - 1][l - 1]);
            }
        }
    }
    
     for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
    return dp[n][k];
}

int main() {
    int n = 3; // s? l? hoa
    int k = 2; // s? bó hoa
    vector<vector<int>> v = {{1, 2}, 
							{3, 4},
							{5, 6}};

    int result = maximizeBeauty(n, k, v);
    cout << "Tong gia tri tham my lon nhat: " << result << endl;

    return 0;
}

