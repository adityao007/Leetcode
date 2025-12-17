class Solution {
public:
    int mySqrt(int x) {
        // Binary search to find the integer square root
        // We're looking for the largest integer where mid * mid <= x
        int left = 0, right = x;

        while (left < right) {
            // Calculate mid point, using 1LL to prevent integer overflow
            // Adding 1 before division ensures we round up (upper mid)
            // This is crucial when left and right differ by 1
            int mid = (left + right + 1LL) >> 1;

            // Check if mid^2 > x by comparing mid > x/mid
            // This avoids overflow compared to mid * mid > x
            if (mid > x / mid) {
                // mid is too large, search in lower half
                right = mid - 1;
            } else {
                // mid^2 <= x, this could be our answer or we need larger
                // Search in upper half including mid
                left = mid;
            }
        }

        // When loop exits, left == right, which is our answer
        return left;
    }
};