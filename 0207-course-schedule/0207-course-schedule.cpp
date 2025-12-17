class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list graph where edge from 'from' to 'to' means 
        // 'from' is a prerequisite of 'to'
        vector<vector<int>> adjacencyList(numCourses);
      
        // Track in-degree (number of prerequisites) for each course
        vector<int> inDegree(numCourses);
      
        // Build the graph and calculate in-degrees
        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
          
            // Add edge from prerequisite to course
            adjacencyList[prerequisiteCourse].push_back(course);
          
            // Increment in-degree for the course
            ++inDegree[course];
        }
      
        // Initialize queue with all courses that have no prerequisites (in-degree = 0)
        queue<int> processQueue;
        for (int course = 0; course < numCourses; ++course) {
            if (inDegree[course] == 0) {
                processQueue.push(course);
            }
        }
      
        // Process courses using topological sort (Kahn's algorithm)
        while (!processQueue.empty()) {
            // Take a course with no remaining prerequisites
            int currentCourse = processQueue.front();
            processQueue.pop();
          
            // Mark this course as completed
            --numCourses;
          
            // For each course that depends on the current course
            for (int dependentCourse : adjacencyList[currentCourse]) {
                // Decrement its in-degree (one prerequisite completed)
                if (--inDegree[dependentCourse] == 0) {
                    // If all prerequisites are met, add to queue
                    processQueue.push(dependentCourse);
                }
            }
        }
      
        // If all courses were processed, no cycle exists
        return numCourses == 0;
    }
};