class Solution {
public:
    string countAndSay(int n) {
        // Initialize the first term of the sequence
        string currentSequence = "1";
      
        // Generate the sequence n-1 times to get the nth term
        while (--n) {
            string nextSequence = "";
          
            // Process the current sequence to generate the next one
            for (int i = 0; i < currentSequence.size();) {
                // Find the end position of consecutive identical digits
                int j = i;
                while (j < currentSequence.size() && currentSequence[j] == currentSequence[i]) {
                    ++j;
                }
              
                // Append count of consecutive digits
                nextSequence += to_string(j - i);
                // Append the digit itself
                nextSequence += currentSequence[i];
              
                // Move to the next group of digits
                i = j;
            }
          
            // Update current sequence for next iteration
            currentSequence = nextSequence;
        }
      
        return currentSequence;
    }
};