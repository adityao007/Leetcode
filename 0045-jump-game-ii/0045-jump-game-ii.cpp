class Solution {
public:
    int jump(vector<int>& nums) {
        int  jumps = 0, currentEnd = 0,farest=0;

        for(int i=0;i<nums.size()-1;i++){
            farest=max(farest,i+nums[i]);
            if(i==currentEnd){
                currentEnd=farest;
                jumps++;
            }
        }
        return jumps;
    }
};