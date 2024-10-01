#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &v,int start,int end,int mid){
    int i=start;
    int j=mid+1;
    vector<int> temp;

    while(i<=mid && j<=end){
        if(v[i]>v[j]){
            temp.push_back(v[j]);
            j++;
        } 
        else{
            temp.push_back(v[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(v[j]);
        j++;
    }
    //copy from temp into v
    for(int i=0;i<temp.size();i++){
        v[start+i]=temp[i];
    }
}

void mergesort(vector<int> &v,int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        mergesort(v,start,mid);
        mergesort(v,mid+1,end);
        merge(v,start,end,mid);
    }

}
int main(){
    vector<int> v = {-2,0,12,3,1,100,35,-100};
    cout<<"Before Sorting: ";
    for(auto it:v) cout<<it<<" ";
    cout<<endl;
    cout<<"After Sorting: ";          
    mergesort(v,0,v.size()-1);
    for(auto it:v) cout<<it<<" ";
    return 0;
}