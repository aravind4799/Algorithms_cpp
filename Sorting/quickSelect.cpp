#include<bits/stdc++.h>
using namespace std;

void swapp(vector<int>& arr,int i,int j){
    if(arr[i]!=arr[j]){
    arr[i] = arr[i] + arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] = arr[i] - arr[j];
    }
}
int partition(vector<int>& arr,int low,int high,int k){
    int i = low;
    int pivot = arr[high];
    //index i keeps track of elements that are greater than pivot on the left half
    //index j is iterator

    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            swapp(arr,j,i);
            //or
            // swap(arr[j],arr[i]); - std::swap()
            i++;
        }
    }
    //swap pivot and i
    swapp(arr,i,high);
    return i;
}
int qs(vector<int>& arr,int low,int high,int k){
    if(low==high) return arr[low];
    int partitionIndex = partition(arr,low,high,k);
    if(partitionIndex == k) return arr[partitionIndex];
    else if(partitionIndex>k) return qs(arr,low,partitionIndex-1,k);
    else return qs(arr,partitionIndex+1,high,k);
}
int main(){
    vector<int> arr = {-100,2,12,4,5,2,-90,0};
    // find the kth smallest element in the given unsorted array
    // quickselect - divide and conq - o(n) - avg time complexity - worst case n^2
    int k = 4;
    cout<<k<<"th: "<<"smallest element in arr: "<<qs(arr,0,arr.size()-1,k-1);
    return 0;
}