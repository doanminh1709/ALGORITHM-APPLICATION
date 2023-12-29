#include<bits/stdc++.h>
using namespace std;

struct CongViec{
	string macv;
	double tgbd;
	double tgkt;
};
void Init(CongViec mcv[]){
	mcv[0] = {"CV1" , 8.3 , 9.6};
	mcv[1] = {"CV2" , 2.50 , 6.4};
	mcv[2] = {"CV3" , 4.15 , 6.3};
	mcv[3] = {"CV4" , 6.2 , 7.5};
	mcv[4] = {"CV5" , 1.2 , 3.2};
	mcv[5] = {"CV6" , 4.6 , 6.4};	
	mcv[6] = {"CV7" , 5.3 , 7.4};
}
//thuat toan quick sort (sap xep nhanh)
//Y tuong : chia day thanh 2 doan vi , nua be va nua lon 
//,phan tu pivot se nam o giua  , nen minh phai dua duoc 
//phan tu pivot vao dung vi tri 
int find_parivition(CongViec mcv[] , int l , int r)
{
	//Chon vi tri cho phan tu , pivot la gia tri can dua ve dung vi tri  
	int pivot = (mcv[l].tgkt - mcv[l].tgbd);
	int i = l , j = r;
	double left_value;
	double right_value;
	do{
		do{
			left_value = mcv[i].tgkt - mcv[i].tgbd;
			i++;
		}while(left_value > pivot);
		
		do{
			right_value = mcv[j].tgkt - mcv[j].tgbd;
			j--;
		}while(right_value < pivot);
		
		swap(mcv[i] , mcv[j]);
	}while(i < j);
	
	//dua pivot ve dung vi tri cua no 
	swap(mcv[j] , mcv[l]);
	
	return pivot;
}
int find_partition(int A[] , int l , int h)
{
    int pivot = A[l];
    int i = l , j = h;
    do{
        //Find element greater than pivot
        do{i++;}while(A[i] >= pivot);

        //Find element lesser than pivot
        do{j--;}while(A[j] < pivot);

        //If i even less than j so swap A[i] and A[j]
        if(i < j) swap(A[i] , A[j]);
        //do while lap truoc va kiem tra dieu kien sau 
    }while(i < j);
    //Update partition
    swap(A[l] , A[j]);
    return j;
}
void QuickSort(int arr[] , int l , int r){
	if(l < r){
		int particition = find_partition(arr , l , r);
		QuickSort(arr , l ,particition);
		QuickSort(arr , particition + 1 ,r);	 
	}
}

double SumOfAnotherWork(CongViec mcv[] , int n){
	//Neu mang chi co 1 phan tu thi cha ve phan tu dau tien 
	if(n == 1){
		return (mcv[0].tgkt - mcv[0].tgbd);
	}else{
		return (mcv[n - 1].tgkt - mcv[n - 1].tgbd) + SumOfAnotherWork(mcv , n - 1);
	}	
}
double SumOfAntherFor(CongViec mcv[] , int n){
	double sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += (mcv[i].tgkt - mcv[i].tgbd);
	}
	return sum;
}
void ShowData(int arr[] , int index , int n){
	if(index == n ) return;
	cout<<arr[index]<<" ";
	ShowData(arr , index+1 , n);
}
int main()
{
//	CongViec mcv[7];
//	Init(mcv);
//	cout<<SumOfAnotherWork(mcv , 6)<<endl;
//	cout<<SumOfAntherFor(mcv , 6)<<endl;
	
//	int pivot = find_parivition(mcv , 0 , 6);
//	cout<<"Pivot : "<<pivot<<endl;
//	
	int arr[9] = {50 , 70 , 60 , 90 , 40 , 80 , 10 , 20 , 30};
	cout<<"pivot = "<<find_partition(arr , 0 , 10)<<endl;
	for(int i = 0 ;i < 9 ; i ++)
		cout<<arr[i]<<" "<<endl;
		
	
	QuickSort(arr , 0 , 9);
	ShowData(arr , 0 , 9);
	return 0;
}
