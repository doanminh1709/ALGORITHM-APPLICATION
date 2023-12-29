#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 15;
	double nums2[n] = {3.2 , 4 , 6 , 2.3 , 6.4 ,
					  5, 7 , 8.2 , 10 , 1.3 ,
					  4.2 , 5 , 8 , 2, 10 };
	n = 12;
	int nums[n] = {1 ,2 ,-3 ,-2, 0 ,4 , 5, 9, 6, 8 , 7 , 11};
	//Khoi tao mang ban dau toan 1 
	int countSubLength[n];
	fill(countSubLength, countSubLength + n, 1);
//	for(int i = 0 ; i < n ; i++)
//		countSubLength[i]=1;	
	//Su dung bai toan quy hoach dong 
	//2th 
	
	//1.Neu tinh phan tu day vao day con tang truoc day 
		
	//2.Neu phan tu day nho hon phan tu truoc day 
	
	for(int i = 1; i < n ; i++){
		//Duyet tu dau den i 
		for(int j = 0 ; j < i ; j++){
			//Kiem tra neu a[j] < a[i]
			
			//1 ,2 ,-3 ,-2, 0 ,4 , 5, 9, 6, 8 , 7 , 11   
			// 1 2 3 4 4 4 5 
			//A[i] < A[i+1] 
			if(nums[i] > nums[j]){
				countSubLength[i] = max(countSubLength[j] + 1 , countSubLength[i]);
			}
		}
	}
	cout<<"Day ban dau : ";
	int maxLength = 1 , index = 0;
	for(int i = 0 ; i < n ; i++){
		cout<<nums[i]<<" ";
		if(maxLength < countSubLength[i]){
			maxLength = countSubLength[i];
			index = i;
		}		
	}
	cout<<endl;
	cout<<"Do dai day con lon nhat : "<<	maxLength<<endl;
	//Truy vet ra day con 
	
	//Lap tu index ve 
	int subArr[maxLength];
	subArr[maxLength-1] = nums[index];
	
	int j = maxLength - 2;
	int i = index-1;
	while(j >= 0 && i >= 0){
			if(countSubLength[i] == j + 1){
				subArr[j] = nums[i];		
				j--;
			}
		i--;
	}
	
	//Ham in day con dai nhat 
	cout<<"Day con lon nhat : ";
	for(int i = 0 ; i < maxLength ; i++)
		cout<<subArr[i]<<" ";
	
	
	return 0;
}
