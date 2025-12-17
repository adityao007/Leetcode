class Solution {
public:
    int getSum(int a, int b) {
        // Iterate until there's no carry left
        while (b != 0) {
            // Calculate carry bits by finding common set bits and shifting left
            // Cast to unsigned to avoid undefined behavior with negative numbers
            unsigned int carry = (static_cast<unsigned int>(a & b)) << 1;
          
            // XOR gives sum without considering carry
            a = a ^ b;
          
            // Update b with carry for next iteration
            b = carry;
        }
      
        // Return final sum when no carry remains
        return a;
    }
};