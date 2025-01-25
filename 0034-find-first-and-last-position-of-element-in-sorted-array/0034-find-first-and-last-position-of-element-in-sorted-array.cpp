class Solution {
public:
    int firstposition(vector<int>& nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int result=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                result=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return result;
    }
    int secondposition(vector<int>& nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int result=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                result=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1); 
        result[0] = firstposition(nums, target);
        result[1] = secondposition(nums, target);
        return result;
    }
};