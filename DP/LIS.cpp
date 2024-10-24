#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>& arr,int current_index,int prev_index,vector<vector<int>> &dp){
    if(current_index==arr.size()) return 0;

    if(dp[current_index][prev_index+1]!=-1) return dp[current_index][prev_index+1];
    // not pick the element at this index
    int len = 0 + lis(arr,current_index+1,prev_index,dp);
    //or pick this element if the condition is satisfied
    //if its prev == -1 => it does not have a previous element .. meaning we can take it

    if(prev_index==-1 || arr[current_index] > arr[prev_index] ){
        len = max( len, 1+lis(arr,current_index+1,current_index,dp) );
        //previous index becomes - current index
    }

    return dp[current_index][prev_index+1]=len;

}
int main(){
    vector<int> arr = {1,2,6,5,7,1,3,5};
    int n = arr.size();
    // dp solution
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    cout<<"length of longest increasing subsequence:"<<lis(arr,0,-1,dp);
}