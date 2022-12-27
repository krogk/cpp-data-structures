#include <cstddef>
#include <string>
#include <unordered_map>

class Trie {
public:
    // Constructs an empty trie
    Trie() : m_isEndOfWord(false) {}

    // Destructor
    ~Trie() {}

    // Inserts a word into the trie
    void insert(const std::string& word)
    {
        // Start at the root of the trie
        Trie* node = this;

        // Iterate through each character in the word
        for (const char c : word) {
            // Check if the current node contains a pointer to the node for character c
            if (node->m_children.find(c) == node->m_children.end())
                // If not, create a new node for character c
                node->m_children[c] = new Trie();
            // Move to the next node in the trie
            node = node->m_children[c];
        }
        // Mark the current node as the end of a word
        node->m_isEndOfWord = true;
    }

    // Returns true if the trie contains the specified word, false otherwise
    bool contains(const std::string& word) const {
        // Start at the root of the trie
        const Trie* node = this;

        // Iterate through each character in the word
        for (const char c : word) {
            // Check if the current node contains a pointer to the node for character c
            if (node->m_children.find(c) == node->m_children.end())
                // If not, the trie does not contain the word
                return false;
            // Move to the next node in the trie
            node = node->m_children.at(c);
        }
        // Return whether the current node is marked as the end of a word
        return node->m_isEndOfWord;
    }

private:
    bool m_isEndOfWord;                  // Indicates whether the node represents the end of a word
    std::unordered_map<char, Trie*> m_children;   // The children of the node, unordered_map that stores the children of the node, with the keys being the characters and the values being pointers to the child nodes.
};
