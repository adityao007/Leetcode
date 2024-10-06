class Solution {
public:
    string toBinaryString(int num) {
        return bitset<8>(num).to_string().substr(bitset<8>(num).to_string().find('1'));
    }

    int binaryStringToDecimal(const string& binaryStr) {
        return stoi(binaryStr, nullptr, 2);
    }

    int maxGoodNumber(vector<int>& nums) {
        int maxDecimalValue = 0;
        
        sort(nums.begin(), nums.end());
        do {
            string currentBinaryString = "";
            for (int num : nums) {
                currentBinaryString += toBinaryString(num);
            }
            
            int currentDecimalValue = binaryStringToDecimal(currentBinaryString);
            maxDecimalValue = max(maxDecimalValue, currentDecimalValue);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return maxDecimalValue;
    }
};
