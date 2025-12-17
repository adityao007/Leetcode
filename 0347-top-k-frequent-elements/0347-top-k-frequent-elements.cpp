class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency of each number
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }
      
        // Step 2: Use min heap to maintain top k frequent elements
        // Pair: {frequency, number}
        using FreqNumPair = pair<int, int>;
        priority_queue<FreqNumPair, vector<FreqNumPair>, greater<FreqNumPair>> minHeap;
      
        // Step 3: Build heap with size constraint k
        for (const auto& [number, frequency] : frequencyMap) {
            minHeap.push({frequency, number});
          
            // Keep only k most frequent elements in the heap
            if (minHeap.size() > k) {
                minHeap.pop();  // Remove element with smallest frequency
            }
        }
      
        // Step 4: Extract all elements from heap to build result
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
      
        return result;
    }
};