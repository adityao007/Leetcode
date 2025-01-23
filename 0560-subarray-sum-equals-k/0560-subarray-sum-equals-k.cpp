class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixSumCount;
        int prefixSum = 0;
        int count = 0;
        
        prefixSumCount[0] = 1;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int remove=prefixSum-k;
            count+=prefixSumCount[remove];
            prefixSumCount[prefixSum]+=1;
        }
        return count;
    }
};
