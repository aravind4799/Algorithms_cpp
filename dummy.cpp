class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //PREFIX SUM
        // psm_i - psm_j = rem => the subarray in between is giving subarray(i,j)%k = rem -> in this case we need to remove a subarray whose sum is a given value.
        // psm_j = (rem - psm_i + p)%p => if it exist .. minimize the subarray size.
        // psm_i - psm_j = 0 => the subarray in between is divisible by k=> subarray(i,j)%k=0; if we encounter same remainder again.   

        int rem=0;
        int n = nums.size();
        unordered_map<int,int> map;
        map[0]=-1; 
        for(auto num: nums){
            // to avoid overflow
            // instead of caluclating sum first then taking the mod -  can potentially cause overflow

            rem = (rem+num)%p;
        }


        if(rem==0) return 0; // no need to perform any subarray deletion

        //else need to remove min subarray whose sum is rem
        int minWindow=n; // fix it to n not 0 since we need to minimize out result.
        int prefixRemI=0;
        int prefixRemJ=0;

        for(int i=0;i<n;i++){
           // instead of calculating the prefixsum then taking remainder do it in one step
           prefixRemI = ((prefixRemI + nums[i])%p+p)%p;
           prefixRemJ = (prefixRemI - rem  + p)%p; // check for any remaider whose complement of prefixRemI is already seen-> then we minimize the ans.
           if(map.find(prefixRemJ)!=map.end()) {
            minWindow = min(minWindow, i - map[prefixRemJ]);
           }


           map[prefixRemI] = i; // this prefixSum is found untill this index => we need to minimize this as we
        }


        return minWindow!=n ? minWindow : -1;




    }
};

