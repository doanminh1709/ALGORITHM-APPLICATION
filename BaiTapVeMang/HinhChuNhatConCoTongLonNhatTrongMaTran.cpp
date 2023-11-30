#include<bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define endl "\n"
#define MAX 500
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
 
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+2804;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


//thuat toan giup tinh tong day con lien tiep lon nhat voi do phuc tap O(n)
int kadane(int A[] , int n){
	int res = 0 , max_end_here = 0;
	for(int i = 0 ; i < n ; i++){
		max_end_here += A[i];
		res = max(res , max_end_here);
		max_end_here = max(0 , max_end_here);
	}
	return res;
}
void solve(){
	int n , m;
	cin>>n>>m;
	
	int Matrix[n][m];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>Matrix[i][j];
		}
	}
	
	int res = INT_MIN;
	int tmp[n];//luu tong cac phan tu tren cac dong , tmp[i] : tong cac phan tu tren dong thu i 
	for(int l = 0 ; l < m ; l++){
		//reset tat ca du lieu tren dong bang 0 
		memset(tmp , 0);
		//bien r se bien thien theo l duyet tu trai sang phai 
		for(int r = l; r < m ; r++){
			for(int i = 0 ; i < n ; i++){
				tmp[i] += Matrix[i][r];
			}
			res = max(res , kadane(tmp , n));
		}
	}
	cout<<res<<endl;
}

int main(){
	
//read file and write file 
//	freopen("input.txt", "r" , stdin);
//	freopen("output.txt", "w" , stdin);
	
	solve();
	
	return 0;
 } 
