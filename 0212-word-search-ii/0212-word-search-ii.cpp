class Trie {
public:
    vector<Trie*> children;  // Array of 26 pointers for each lowercase letter
    int wordIndex;            // Index of word in the original words array (-1 if not a word end)

    Trie() : children(26, nullptr), wordIndex(-1) {}

    // Insert a word into the trie with its index in the words array
    void insert(const string& word, int index) {
        Trie* currentNode = this;
        for (char ch : word) {
            int charIndex = ch - 'a';  // Convert character to index (0-25)
            if (!currentNode->children[charIndex]) {
                currentNode->children[charIndex] = new Trie();
            }
            currentNode = currentNode->children[charIndex];
        }
        currentNode->wordIndex = index;  // Mark the end of word with its index
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Build trie from all words
        Trie* root = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            root->insert(words[i], i);
        }
      
        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        // DFS function to search words in the board
        function<void(Trie*, int, int)> dfs = [&](Trie* node, int row, int col) {
            char currentChar = board[row][col];
            int charIndex = currentChar - 'a';
          
            // If current character doesn't exist in trie, return
            if (!node->children[charIndex]) {
                return;
            }
          
            // Move to the child node
            node = node->children[charIndex];
          
            // If we found a complete word, add it to result
            if (node->wordIndex != -1) {
                result.emplace_back(words[node->wordIndex]);
                node->wordIndex = -1;  // Mark as visited to avoid duplicates
            }
          
            // Directions for exploring neighbors (up, right, down, left)
            int directions[5] = {-1, 0, 1, 0, -1};
          
            // Mark current cell as visited
            board[row][col] = '#';
          
            // Explore all four adjacent cells
            for (int k = 0; k < 4; ++k) {
                int newRow = row + directions[k];
                int newCol = col + directions[k + 1];
              
                // Check if the new position is valid and not visited
                if (newRow >= 0 && newRow < rows && 
                    newCol >= 0 && newCol < cols && 
                    board[newRow][newCol] != '#') {
                    dfs(node, newRow, newCol);
                }
            }
          
            // Restore the original character (backtrack)
            board[row][col] = currentChar;
        };

        // Start DFS from every cell in the board
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(root, i, j);
            }
        }
      
        return result;
    }
};