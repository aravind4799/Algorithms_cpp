#include<bits/stdc++.h>
using namespace std;

bool countAnySubSequence(int arr[],int n,int sum,vector<int> &ds,int index,int &count,int &sumSoFar){
    if(index == n){
        if(sum == sumSoFar){
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
            count++;
            return true;
        }
        else return false;
    }
    //pick this number
    sumSoFar+=arr[index];
    ds.push_back(arr[index]);
    if(countAnySubSequence(arr,n,sum,ds,index+1,count,sumSoFar)) return true;

    //not pick this number
    sumSoFar-=arr[index];
    ds.pop_back();
    if(countAnySubSequence(arr,n,sum,ds,index+1,count,sumSoFar)) return true;

    return false;
}
void countSubSequenceSum(int arr[],int n,int sum,vector<int> &ds,int index,int &count,int &sumSoFar){
    if(index == n){
        if(sum == sumSoFar){
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
            count++;
        }
        return;
    }
    //pick this number
    sumSoFar+=arr[index];
    ds.push_back(arr[index]);
    countSubSequenceSum(arr,n,sum,ds,index+1,count,sumSoFar);

    //not pick this number
    sumSoFar-=arr[index];
    ds.pop_back();
    countSubSequenceSum(arr,n,sum,ds,index+1,count,sumSoFar);
}
int justCount(int arr[],int n,int sum,int index,int sumSoFar){
    if(index==n){
        if(sumSoFar == sum) return 1;
        else return 0;
    }
    //pick
    sumSoFar+=arr[index];
    int l = justCount(arr,n,sum,index+1,sumSoFar);
    //not pick
    sumSoFar-=arr[index];
    int r = justCount(arr,n,sum,index+1,sumSoFar);
    return l+r;
}
int main(){
    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 2;
    // find the number of subsequences that have the sum = 2 from the given arr
    vector<int> ds;
    int count=0;
    int sumSoFar = 0;
    // countSubSequenceSum(arr,n,sum,ds,0,count,sumSoFar); //PRINT ALL SUBSEQUENCE
    // if(countAnySubSequence(arr,n,sum,ds,0,count,sumSoFar)){ //PRINT ANY SUBSEQUENCE
    //     cout<<"THERE EXIST ATLEAST ONE SUBSEQUENCE WITH THE GIVEN SUM"<<endl;
    // } //PRINT ANY SUBSEQUENCE
    cout<<"number of valid subsequences :"<<justCount(arr,n,sum,0,sumSoFar); //COUNT ALL SUBSEQUENCES

    // cout<<""justCount(arr,n,sum,0,sumSoFar);
    return 0;
}

// Q1 : PRINT ALL SUBSEQUENCES WHOSE SUM = GIVEN SUM
// I NEED TO TRAVERSE ALL POSSIBLE RECURSION TO CHECK AND ADD THE ANS!

// ==> TECHNIQUE TO PRINT ALL ANSWERS

// Q2: PRINT ANY SUBSEQUENCE WHOSE SUM = GIVEN SUM
// THEN I DONT NEED TO TRAVERSE THE ENTIRE RECURSION TREE, IF ANY RECURSION CALL RETURNS TRUE.. THERE IS NO NEED
// GO INSIDE RECURSION CALLS! 

//condition satisfied return a true! - if not return a false and prune the recursive calls accordingly
// ==> TECHNIQUE TO PRINT ONLY ONE ANSWER

// Q3: JUST GIVE ME THE COUNT -- RETURN THE NUMBER OF VALID SUBSEQUENCES! NO NEED TO PRINT

// TEMPLATE FOR THIS PROBLEM

// BASE CASE SATISFIED -> RETURN 1
// ELSE RETURN 0
// L = F()
// R = F()
// RETURN L+R;