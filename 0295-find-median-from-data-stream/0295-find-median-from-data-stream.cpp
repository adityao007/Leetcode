class MedianFinder {
public:
    MedianFinder() {
        // Constructor - no initialization needed as containers are empty by default
    }

    void addNum(int num) {
        // Step 1: Always add the new number to the max heap first
        maxHeap.push(num);
      
        // Step 2: Move the largest element from max heap to min heap
        // This ensures all elements in max heap are <= all elements in min heap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Balance the heaps if necessary
        // Min heap should have at most one more element than max heap
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        // If both heaps have equal size, median is the average of both tops
        // Otherwise, median is the top of the larger heap (min heap)
        return minHeap.size() == maxHeap.size() 
            ? (minHeap.top() + maxHeap.top()) / 2.0 
            : minHeap.top();
    }

private:
    // Max heap to store the smaller half of numbers
    // Top element is the largest in the smaller half
    priority_queue<int> maxHeap;
  
    // Min heap to store the larger half of numbers  
    // Top element is the smallest in the larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */