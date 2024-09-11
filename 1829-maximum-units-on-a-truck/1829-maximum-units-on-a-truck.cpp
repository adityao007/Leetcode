class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int maxUnits = 0;     
        for (int i = 0; i < boxTypes.size(); i++) {
            int boxes = boxTypes[i][0];    
            int units = boxTypes[i][1];   
            if (truckSize >= boxes) {
                maxUnits += boxes * units;
                truckSize -= boxes; 
            } 
            else {
                maxUnits += truckSize * units;
                break;  
            }
        }
        return maxUnits;
    }
};
