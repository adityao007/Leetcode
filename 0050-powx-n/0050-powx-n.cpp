class Solution {
public:
    double myPow(double x, int n) {
        // Lambda function for fast exponentiation using binary exponentiation
        auto fastPower = [](double base, long long exponent) {
            double result = 1.0;
          
            // Iterate while exponent is not zero
            while (exponent > 0) {
                // If current bit is 1, multiply result by current base
                if (exponent & 1) {
                    result *= base;
                }
                // Square the base for next bit position
                base *= base;
                // Right shift to process next bit
                exponent >>= 1;
            }
          
            return result;
        };
      
        // Handle positive and negative exponents
        // For negative exponent, calculate reciprocal of positive power
        // Cast n to long long to handle INT_MIN overflow case
        return n >= 0 ? fastPower(x, n) : 1.0 / fastPower(x, -(long long)n);
    }
};