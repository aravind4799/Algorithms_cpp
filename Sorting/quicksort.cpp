#include<bits/stdc++.h>
using namespace std;


void swap(vector<int>& arr,int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int findPartitionIndex(vector<int>& arr,int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){
        // in decending order?
        // while( i<=high && arr[i]>=pivot) i++;
        // while(j>=0 && arr[j]<pivot) j--;

        // in ascending order
        while( i<=high && arr[i]<=pivot) i++;
        while(j>=0 && arr[j]>pivot) j--;
        //swap i and j if they are not passed each other
        if(i<j){
            swap(arr,i,j);
        }
    }
    //when j has crossed i
    //swap pivot with j as now pivot is at its correct location.
    swap(arr,low,j);
    return j;
}
void quicksort(vector<int>& arr,int low,int high){
    
    if(low<high){
    int partitionIndex = findPartitionIndex(arr,low,high);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return;

    quicksort(arr,low,partitionIndex-1);
    quicksort(arr,partitionIndex+1,high);
    }
    
}
int main(){
    vector<int> arr = {2,4,3,1};
    quicksort(arr,0,arr.size()-1);
    cout<<"SORTED ARRAY USING QUICKSORT:"<<endl;
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}