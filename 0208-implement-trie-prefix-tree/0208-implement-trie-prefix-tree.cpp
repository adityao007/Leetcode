class Trie {
private:
    // Array to store pointers to child nodes (26 for lowercase letters a-z)
    vector<Trie*> children;
    // Flag to mark if current node represents end of a word
    bool isEnd;

    /**
     * Helper function to search for a prefix in the trie
     * @param prefix The string prefix to search for
     * @return Pointer to the node representing the last character of prefix, or nullptr if not found
     */
    Trie* searchPrefix(string prefix) {
        Trie* currentNode = this;
      
        // Traverse through each character in the prefix
        for (char ch : prefix) {
            int index = ch - 'a';  // Convert character to array index (0-25)
          
            // If the child node doesn't exist, prefix not found
            if (!currentNode->children[index]) {
                return nullptr;
            }
          
            // Move to the child node
            currentNode = currentNode->children[index];
        }
      
        return currentNode;
    }

public:
    /**
     * Constructor: Initialize the trie with empty children array and isEnd flag
     */
    Trie() : children(26), isEnd(false) {}

    /**
     * Insert a word into the trie
     * @param word The word to insert
     */
    void insert(string word) {
        Trie* currentNode = this;
      
        // Traverse through each character in the word
        for (char ch : word) {
            int index = ch - 'a';  // Convert character to array index (0-25)
          
            // Create new node if path doesn't exist
            if (!currentNode->children[index]) {
                currentNode->children[index] = new Trie();
            }
          
            // Move to the child node
            currentNode = currentNode->children[index];
        }
      
        // Mark the last node as end of word
        currentNode->isEnd = true;
    }

    /**
     * Search for a complete word in the trie
     * @param word The word to search for
     * @return true if the word exists in the trie, false otherwise
     */
    bool search(string word) {
        Trie* targetNode = searchPrefix(word);
      
        // Word exists only if we found the prefix AND it's marked as end of word
        return targetNode != nullptr && targetNode->isEnd;
    }

    /**
     * Check if any word in the trie starts with the given prefix
     * @param prefix The prefix to search for
     * @return true if any word starts with the prefix, false otherwise
     */
    bool startsWith(string prefix) {
        Trie* targetNode = searchPrefix(prefix);
      
        // Prefix exists if we can find a path for all its characters
        return targetNode != nullptr;
    }
};