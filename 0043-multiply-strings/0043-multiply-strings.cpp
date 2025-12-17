class Solution {
public:
    string multiply(string num1, string num2) {
        // Handle edge case where either number is zero
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
      
        // Get the lengths of both input strings
        int len1 = num1.size();
        int len2 = num2.size();
      
        // Initialize result array with size len1 + len2 (maximum possible digits in product)
        vector<int> result(len1 + len2, 0);
      
        // Multiply each digit of num1 with each digit of num2
        // Starting from the rightmost digit (least significant)
        for (int i = len1 - 1; i >= 0; --i) {
            int digit1 = num1[i] - '0';  // Convert char to int
          
            for (int j = len2 - 1; j >= 0; --j) {
                int digit2 = num2[j] - '0';  // Convert char to int
              
                // Multiply digits and add to corresponding position
                // Position i + j + 1 corresponds to the result position
                result[i + j + 1] += digit1 * digit2;
            }
        }
      
        // Handle carries from right to left
        for (int i = result.size() - 1; i > 0; --i) {
            result[i - 1] += result[i] / 10;  // Add carry to previous position
            result[i] %= 10;                  // Keep only the last digit
        }
      
        // Skip leading zeros (if any)
        int startIndex = result[0] == 0 ? 1 : 0;
      
        // Build the final result string
        string answer;
        for (int i = startIndex; i < result.size(); ++i) {
            answer += '0' + result[i];  // Convert int to char and append
        }
      
        return answer;
    }
};