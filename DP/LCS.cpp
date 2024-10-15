class Solution {
public:
    int LCS(string &a,string &b,int i,int j,vector<vector<int>> &dp){
        if(i>a.length()-1 || j>b.length()-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j] = 1+ LCS(a,b,i+1,j+1,dp);
        return dp[i][j] = max(LCS(a,b,i,j+1,dp),LCS(a,b,i+1,j,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n+1;i++) dp[i][0]=0;
        for(int j=0;j<m+1;j++) dp[0][j]=0;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int len = dp[n][m];
        string s ="";
        for(int i=0;i<len;i++) s+="*";
        int i=n;
        int j=m;
        int k=len-1;

        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                s[k]=text1[i-1];
                i--,j--;
                k--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                 i--;
            }
            else j--;
        }
        cout<<"longest common subsequence:"<<s;
        return dp[n][m];


    }
};