class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;  // Stores the root word if this node is the end of the root
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = word;  // Mark the end of the root word
    }

    // Find the shortest root for a given word
    string findRoot(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                break;  // No matching prefix
            }
            node = node->children[c];
            if (!node->word.empty()) {
                return node->word;  // Return the root word found
            }
        }
        return word;  // No root found, return the word itself
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;

        // Insert all dictionary words (roots) into the Trie
        for (const string& root : dictionary) {
            trie.insert(root);
        }

        // Split the sentence into words and replace them
        istringstream iss(sentence);
        string word, result;
        while (iss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.findRoot(word);  // Replace word with its root
        }

        return result;  // Return the modified sentence
    }
};