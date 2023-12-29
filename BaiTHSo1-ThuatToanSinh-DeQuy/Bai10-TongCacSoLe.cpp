#include<iostream>
using namespace std;

int n, arr[100];
void KhoiTao() {
	n = 6;
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 2;
	arr[3] = 5;
	arr[4] = 6;
	arr[5] = 9;
}
int TongCacSoLe(int n) {
	int sum = 0;
	if (arr[n - 1] % 2 == 1) sum = arr[n - 1];
	if (n == 0) return sum;
	else return sum + TongCacSoLe(n - 1);
}

int main() {
	KhoiTao();
	cout << TongCacSoLe(n) << endl;
	return 0;
}

