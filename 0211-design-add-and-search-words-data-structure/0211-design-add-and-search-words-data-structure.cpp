/**
 * Trie (Prefix Tree) Node Implementation
 * Used to store words character by character in a tree structure
 */
class TrieNode {
public:
    // Array to store pointers to child nodes (26 for lowercase English letters)
    vector<TrieNode*> children;
    // Flag to mark if this node represents the end of a word
    bool isEndOfWord;
  
    // Constructor initializes children array and end flag
    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        isEndOfWord = false;
    }
  
    // Insert a word into the trie starting from this node
    void insert(const string& word) {
        TrieNode* currentNode = this;
      
        // Traverse each character in the word
        for (char ch : word) {
            // Convert character to index (0-25)
            int index = ch - 'a';
          
            // Create new node if path doesn't exist
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
            }
          
            // Move to the child node
            currentNode = currentNode->children[index];
        }
      
        // Mark the last node as end of word
        currentNode->isEndOfWord = true;
    }
};

/**
 * Design a data structure that supports adding new words and finding if a string matches
 * any previously added string. Supports wildcard '.' that can match any single character.
 */
class WordDictionary {
private:
    TrieNode* root;  // Root node of the trie
  
    /**
     * Depth-first search helper function to handle wildcard matching
     * @param word - The word pattern to search
     * @param index - Current position in the word being processed
     * @param currentNode - Current trie node being examined
     * @return true if pattern matches, false otherwise
     */
    bool dfsSearch(const string& word, int index, TrieNode* currentNode) {
        // Base case: reached end of word
        if (index == word.size()) {
            return currentNode->isEndOfWord;
        }
      
        char currentChar = word[index];
      
        // Case 1: Regular character (not wildcard)
        if (currentChar != '.') {
            int childIndex = currentChar - 'a';
            TrieNode* childNode = currentNode->children[childIndex];
          
            // Continue search if child exists
            if (childNode != nullptr && dfsSearch(word, index + 1, childNode)) {
                return true;
            }
        }
        // Case 2: Wildcard character '.'
        else {
            // Try all possible children
            for (TrieNode* childNode : currentNode->children) {
                if (childNode != nullptr && dfsSearch(word, index + 1, childNode)) {
                    return true;
                }
            }
        }
      
        return false;
    }
  
public:
    // Constructor initializes the root node
    WordDictionary() : root(new TrieNode()) {}
  
    /**
     * Add a word to the data structure
     * @param word - The word to be added (contains only lowercase letters)
     */
    void addWord(string word) {
        root->insert(word);
    }
  
    /**
     * Search if there is any word in the data structure that matches the given pattern
     * @param word - The pattern to search (may contain '.' as wildcard)
     * @return true if pattern matches any word, false otherwise
     */
    bool search(string word) {
        return dfsSearch(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */