class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0;
        int r=n-1;

        while(l<=r){
            int m=l+(r-l)/2;
            int missing=arr[m]-m-1;

            if(missing<k){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return l+k;
    }
};