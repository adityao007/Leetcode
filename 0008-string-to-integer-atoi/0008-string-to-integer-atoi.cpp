class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int length = s.size();
      
        // Step 1: Skip leading whitespaces
        while (index < length && s[index] == ' ') {
            ++index;
        }
      
        // Step 2: Check for sign character
        int sign = 1;  // Default to positive
        if (index < length && (s[index] == '-' || s[index] == '+')) {
            sign = (s[index] == '-') ? -1 : 1;
            ++index;
        }
      
        // Step 3: Convert digits to integer
        int result = 0;
        while (index < length && isdigit(s[index])) {
            int digit = s[index] - '0';
          
            // Step 4: Check for overflow/underflow before multiplication
            // If result > INT_MAX / 10, then result * 10 would overflow
            // If result == INT_MAX / 10, check if adding digit would overflow
            if (result > INT_MAX / 10 || 
                (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                // Return INT_MAX for positive overflow, INT_MIN for negative overflow
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
          
            // Update result with current digit
            result = result * 10 + digit;
            ++index;
        }
      
        // Step 5: Apply sign and return final result
        return result * sign;
    }
};