#include <iostream>
using namespace std;

//Find partition
int find_partition(int A[] , int l , int h)
{
    int pivot = A[l];
    int i = l , j = h;
    do{
        //Find element greater than pivot
        do{i++;}while(A[i] <= pivot);

        //Find element lesser than pivot
        do{j--;}while(A[j] > pivot);

        //If i even less than j so swap A[i] and A[j]
        if(i < j) swap(A[i] , A[j]);
        //do while lap truoc va kiem tra dieu kien sau 
    }while(i < j);
    //Update partition
    swap(A[l] , A[j]);
    return j;
}

void QuickSort(int A[] , int l , int h){
    int index_partition ;

    if(l < h){
     index_partition = find_partition(A , l , h);
     QuickSort(A , l , index_partition);
     QuickSort(A , index_partition+1 , h);
    }
}
void ViewArray(int A[] , int n){
    if(n == 0) return;
    ViewArray(A , n-1);
    cout<<A[n-1]<<" ";
}
int main()
{
    auto n = 10;
    int A[n] =  {11 , 13, 7 , 12 , 16 , 9 , 24 , 5 ,10 , 3 };

	QuickSort(A , 0 , n);
	ViewArray(A , n);

    return 0;
}
