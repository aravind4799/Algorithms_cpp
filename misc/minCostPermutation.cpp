#include<bits/stdc++.h>
using namespace std;
int main(){
    // consider an array of length n. the cost of the array is defined as the sum of number  of distinct elements over all prefixes of the array.
    // find the min cost among all permutaions of arr.

    // eg:
    // n=5 arr=[2,2,3,1,1]
    // ans: 9
    vector<int> nums = {2,2,3,1,1};
    // need to sort nums as: {1,1,2,2,3}
    // order nums 1) give the freq first preference
    //            2) give the vale second preference if the freq is the same

    unordered_map<int,int> map;
    for(auto num: nums) map[num]++;
    vector<pair<int,int>> ordered(map.begin(),map.end());
    sort(ordered.begin(),ordered.end(),[](pair<int,int> p1,pair<int,int> p2){
        if(p1.second==p2.second){
            //same freq
            //return the smallest value first
            return p1.first < p2.first; 
        }
        // default behaviour put the most frequent element in the front
        // as doing so we greedily have the least distinct element at the front in all prefix
        return p1.second > p2.second;
    });

    int count = 0;
    unordered_set<int>seen;
    for(auto &[val,freq]: ordered){
        for(int i=0;i<freq;i++){
            seen.insert(val);
            count+=seen.size();
        }
    }
    cout<<"MIN COST ARRAY:"<<count;
    return 0;
}