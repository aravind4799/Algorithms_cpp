// For Input: 
// 4
// 10 20 30 10
// Your Output: 
// 20
// Expected Output: 
// 20

class Solution {
  public:
    int f(vector<int>&height,vector<int>&dp,int n){
        
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int left = f(height,dp,n-1) + abs(height[n]-height[n-1]);
        int right = INT_MAX;
        if(n>1){
            right = f(height,dp,n-2) + abs(height[n]-height[n-2]);
        }
        return dp[n] = min(left,right);
    
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        
        if(n==1) return 0;
        
        f(height,dp,n-1);
        
        return dp[n-1];
        
    }
};
