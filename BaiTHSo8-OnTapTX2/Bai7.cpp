#include<bits/stdc++.h>
using namespace std;

struct Seminor{
	string topic;
	double start_time;
	double end_time;
};
void Init(Seminor seminors[]){
	seminors[0] = {"Hoi thao viec lam" ,8 , 8.5};
	seminors[1] = {"Hoi thao tim kiem tai nang" , 11 , 12.5};
	seminors[2] = {"Hoi thao nang cao ki nang mem" , 9 , 11};
	seminors[3] = {"Hoi thao chia se kinh nghiem" , 12 , 13};	
	seminors[4] = {"Hoi thao bao ve moi truong" , 10 , 11.5};
}
void ShowInfo(Seminor item){
	cout<<left<<setw(35)<<item.topic
		<<setw(15)<<item.start_time
		<<setw(15)<<item.end_time<<endl;
}
void Title(){
	cout<<left<<setw(35)<<"The topic of the seminor"
		<<setw(15)<<"Start time"
		<<setw(15)<<"End time"<<endl;
}

int FindPartition(Seminor seminors[], int l , int r){
	int i = l , j = r;
	double pivot = seminors[l].end_time;
	
	do{
		do{i++;} while(seminors[i].end_time < pivot);
		do{j--;} while(seminors[j].end_time > pivot);
		if(i < j){
			swap(seminors[i] , seminors[j]);
		}
	}while(i < j);
	swap(seminors[l] , seminors[j]);
	
	return j;
}

void QuickSort(Seminor seminors[], int l , int r){
	
	int partition;
	if(l < r){
		partition = FindPartition(seminors , l , r);
		QuickSort(seminors , l , partition);
		QuickSort(seminors , partition + 1 , r);
	}	
}

void Solve(Seminor seminors[], int n){
	Title();
	ShowInfo(seminors[0]);
	
	int i = 0 , j = 1 , cnt = 1;
	while(i < n && j < n){
		if(seminors[i].end_time < seminors[j].start_time){
			cnt++;
			i = j;
			ShowInfo(seminors[i]);	
		}
		j++;
	}
	cout<<"1 hoc sinh co the tham gia nhieu nhat : "<<cnt<<" hoi thao "<<endl;
}
int main(){
	
	int n = 5;
	Seminor seminors[n];
	
	Init(seminors);
	
	QuickSort(seminors , 0 , n);
	
	Solve(seminors , n);
	
	return 0;
}

