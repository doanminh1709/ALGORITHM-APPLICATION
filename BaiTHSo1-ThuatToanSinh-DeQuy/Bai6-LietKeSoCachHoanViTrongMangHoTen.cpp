#include<iostream>
using namespace std;

void show_config(string persons[], int comberation[], int n)
{
	for (int i = 0; i < n; i++)
		cout << persons[comberation[i]] << " ";
	cout << endl;
}
void next_config(int comberation[], int n, int i)
{
	int k = n - 1;
	//Lap tu cuoi ve dau tim phan tu vua lon hon arr[i]
	while (comberation[i] > comberation[k]) {
		k--;
	}
	swap(comberation[k], comberation[i]);

	//Dao nguoc day
	i++;
	int j = n - 1;

	while (i < j) {
		swap(comberation[i], comberation[j]);
		i++; j--;
	}

}
void generate_config(string persons[], int n) {
	int comberation[100];
	for (int index = 0; index < n; index++) {
		comberation[index] = index;
	}

	int i, cnt = 0;
	do {
		show_config(persons, comberation, n);
		//Init for value i 
		i = n - 2;

		while (i >= 0 && comberation[i] > comberation[i + 1]) i--;

		if (i >= 0) {
			next_config(comberation, n, i);
		}
		cnt++;
	} while (i >= 0);
	cout << "Co tat ca : " << cnt << " cau hinh" << endl;
}

int main()
{
	int n = 6;
	string persons[100] = { "Trang" , "Cong", "Trung" , "Binh" , "Hoan" , "Mai" };
	generate_config(persons, n);
	return 0;
}
