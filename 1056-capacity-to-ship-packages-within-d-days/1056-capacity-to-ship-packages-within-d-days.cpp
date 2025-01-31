class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int D) {
        int days = 1, currentLoad = 0;
        for (int i=0;i<weights.size();i++) {
            if (currentLoad + weights[i] > capacity) {
                days++;
                currentLoad = weights[i];
            }else{
                currentLoad += weights[i];
            }
        }
        return days <= D;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low<high){
            int mid=low+(high-low)/2;
            if(canShip(weights, mid, days)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;

    }
};