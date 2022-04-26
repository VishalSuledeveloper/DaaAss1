// Design and implement Binary search algorithm using Divide and 
// Conquer method for a given input. Determine the time required to search an element. 
// Determine the time required to search an element for large values of n. 
// Compare the time taken by Binary Search with the time taken by linear search. 
// Modify the binary search by dividing it using a random number in the appropriate range. 
// Show how this Modified algorithm compares with the original algorithm in terms of Performance.


#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
//#include<vector>
using namespace std;
using namespace std::chrono;


int linearSearch(int a[], int n, int val){
	 for(int i=0; i<n ; i++){
	 	if(a[i]==val){
			return i;
		}
	}
	return -1;
}

int binarySearch(int a[], int val, int start, int end){
	while( start <= end){
		
		int mid = start + ((end - start)/2);
		
		if(a[mid]==val){
			return mid;
		}
		if(a[mid] < val){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	return -1;
}


int main(){
	
	int n,val;
	cout<<"\nEnter no. of elements(n) : ";
	cin>>n;
	int a[n];
	for(int i=0; i<n ; i++){
		a[i] = rand()%100000;
	}
	
	sort(a, a + n);
	cout<<"\n Sorted Array Elements : ";
	for(int j=0; j<n ; j++){
		cout<<" "<<a[j];
	}
		
	int s=1;
	while(s!=0){		
		cout<<"\nEnter the value for search :";
		cin>>val;
	
	
		//
		
		
		cout<<"\n------<< Linear Search >>------"<<endl;
	    auto start = high_resolution_clock::now();
		
		int index = linearSearch(a,n,val);
		
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "\nTime taken by function: "<< duration.count() << " nanoseconds";
		
	    if(index==-1){
			cout<<"\nValue not found";
		}else{
			cout<<"\nNumber "<<val<<" is present at position "<<index+1;
		}
		
		
		//
		
		
		
		cout<<"\n\n------<< Binary Search >>------"<<endl;
		 
		 start = high_resolution_clock::now();
		
		int index1 = binarySearch(a , val, 0, n-1);
		
		 stop = high_resolution_clock::now();
		 duration = duration_cast<nanoseconds>(stop - start);
		cout << "\nTime taken by function: "<< duration.count() << " nanoseconds";
		
		if(index1==-1){
			cout<<"\nValue not found";
		}else{
			cout<<"\nNumber "<<val<<" is present at position "<<index+1;
		}
		//
		cout<<"\nTo search again press 1 / to exit press 0 : ";
		cin>>s;
		if(s==0){
			break;
		}
	}
	
	return 0;
}