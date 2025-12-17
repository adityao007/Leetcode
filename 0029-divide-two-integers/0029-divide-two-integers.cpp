class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case: divisor is 1, return dividend as is
        if (divisor == 1) {
            return dividend;
        }
      
        // Handle overflow case: INT_MIN / -1 would overflow to INT_MAX + 1
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
      
        // Determine if result should be positive (both same sign)
        bool isPositive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
      
        // Convert both numbers to negative to avoid overflow issues
        // (negative range is larger than positive range for int)
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
      
        int quotient = 0;
      
        // Perform division using bit manipulation and subtraction
        while (dividend <= divisor) {
            int currentDivisor = divisor;
            int currentQuotient = 1;
          
            // Double the divisor using left shift until it exceeds dividend
            // Check for overflow before shifting
            while (currentDivisor >= (INT_MIN >> 1) && dividend <= (currentDivisor << 1)) {
                currentDivisor <<= 1;  // Double the divisor
                currentQuotient <<= 1; // Double the quotient count
            }
          
            // Add current quotient to result
            quotient += currentQuotient;
          
            // Subtract the largest found multiple from dividend
            dividend -= currentDivisor;
        }
      
        // Apply the correct sign to the result
        return isPositive ? quotient : -quotient;
    }
};