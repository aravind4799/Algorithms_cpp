class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //PREFIX SUM

        // if we encounter the same remainder again then there exist a 
        // subarray between these indices whose sum is 0.

        int n = nums.size(),res=0;
        //vector max size = k , as remainder can range from 0...k-1
        // initialize with 0
        vector<int> vec(k,0);
        // vec[0]=1 , for the case where a number is divisible by 0
        vec[0]=1;
        int prefixSum=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int rem = prefixSum%k;
            // if prefixsum = negative, convert rem to be positive number
            if(rem<0) rem = rem%k + k;
            // if value is none 0 we have encounter it in previous iterations
            // update ans
            if(vec[rem]!=0)res+=vec[rem];
            //else update the count for this remainder
            vec[rem]++;
        }
        return res;   
    }
};