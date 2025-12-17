class Solution {
public:
    bool isNumber(string s) {
        int length = s.size();
        int index = 0;
      
        // Handle optional leading sign (+/-)
        if (s[index] == '+' || s[index] == '-') {
            ++index;
        }
      
        // String cannot be just a sign
        if (index == length) {
            return false;
        }
      
        // Check if string is just a decimal point or decimal point followed by e/E
        if (s[index] == '.' && (index + 1 == length || s[index + 1] == 'e' || s[index + 1] == 'E')) {
            return false;
        }
      
        int decimalCount = 0;  // Count of decimal points encountered
        int exponentCount = 0; // Count of exponent markers (e/E) encountered
      
        // Iterate through the remaining characters
        for (int j = index; j < length; ++j) {
            if (s[j] == '.') {
                // Decimal point cannot appear after exponent or if already encountered
                if (exponentCount || decimalCount) {
                    return false;
                }
                ++decimalCount;
            } 
            else if (s[j] == 'e' || s[j] == 'E') {
                // Exponent cannot be repeated, at the start, or at the end
                if (exponentCount || j == index || j == length - 1) {
                    return false;
                }
                ++exponentCount;
              
                // Handle optional sign after exponent
                if (s[j + 1] == '+' || s[j + 1] == '-') {
                    ++j; // Skip the sign
                    // Sign cannot be the last character
                    if (j == length - 1) {
                        return false;
                    }
                }
            } 
            else if (s[j] < '0' || s[j] > '9') {
                // Invalid character (not a digit)
                return false;
            }
        }
      
        return true;
    }
};