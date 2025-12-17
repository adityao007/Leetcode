class Solution {
public:
    string simplifyPath(string path) {
        // Use deque to store valid directory names
        deque<string> directoryStack;
      
        // Create stringstream to split path by '/'
        stringstream pathStream(path);
        string token;
      
        // Process each component between '/' delimiters
        while (getline(pathStream, token, '/')) {
            // Skip empty tokens (consecutive slashes) and current directory references
            if (token == "" || token == ".") {
                continue;
            }
          
            // Handle parent directory reference
            if (token == "..") {
                // Go up one level if not already at root
                if (!directoryStack.empty()) {
                    directoryStack.pop_back();
                }
            } else {
                // Add valid directory name to stack
                directoryStack.push_back(token);
            }
        }
      
        // Handle root directory case
        if (directoryStack.empty()) {
            return "/";
        }
      
        // Build the simplified path
        string simplifiedPath;
        for (const auto& directory : directoryStack) {
            simplifiedPath += "/" + directory;
        }
      
        return simplifiedPath;
    }
};