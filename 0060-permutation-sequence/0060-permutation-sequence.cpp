class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        bitset<10> used;  // Track which numbers (1-9) have been used
      
        // Build the permutation digit by digit
        for (int position = 0; position < n; ++position) {
            // Calculate factorial of remaining positions
            // This represents how many permutations exist for remaining digits
            int factorial = 1;
            for (int i = 1; i < n - position; ++i) {
                factorial *= i;
            }
          
            // Try each number from 1 to n
            for (int digit = 1; digit <= n; ++digit) {
                // Skip if this digit has already been used
                if (used[digit]) {
                    continue;
                }
              
                // Check if k-th permutation uses this digit at current position
                if (k > factorial) {
                    // k-th permutation doesn't start with this digit
                    // Skip 'factorial' number of permutations
                    k -= factorial;
                } else {
                    // k-th permutation starts with this digit
                    result += to_string(digit);
                    used[digit] = true;
                    break;
                }
            }
        }
      
        return result;
    }
};