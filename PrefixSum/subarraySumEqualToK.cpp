// NOLINT

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //print all the subarrays
        vector<vector<int>> res;
        unordered_map<int,vector<int>> map;
        // as there can be multiple indexes that can sum up to same prefixsum! we need to keep track of all
        map[0].push_back(-1);
        int prefixSum=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            if(map.find(prefixSum-k)!=map.end()){
                // find the subarray between index at (prefixSum-k) + 1 till i 
                for(int start: map[prefixSum-k]){
                    vector<int> subarray(nums.begin()+start+1,nums.begin()+i+1);
                    res.push_back(subarray);
                }
            }
            map[prefixSum].push_back(i);
        }

        for(auto &subarray: res){
            cout<<"SUBARRYS FOUND: [";
            for(int i=0;i<subarray.size();i++){
                cout<< subarray[i];
                if(i!=subarray.size()-1) cout<<",";
            }
            cout<<"]"<<endl;
        }

        return 0;
    }
};