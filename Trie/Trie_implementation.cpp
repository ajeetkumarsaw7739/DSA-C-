#include<iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;

        // Initialize all children with NULL
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

        // Initially, node is not the end of any word
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        // Root node represents the starting point
        root = new TrieNode('\0');
    }

    // INSERT WORD INTO TRIE
    void insertuntil(TrieNode* root, string word) {

        // Base case: complete word has been inserted
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Convert uppercase character into index (A=0, B=1, ...)
        int index = word[0] - 'A';
        TrieNode* child;

        // If character already exists, reuse its node
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // Otherwise, create a new node
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Process the remaining characters recursively
        insertuntil(child, word.substr(1));
    }

    void insertword(string word) {
        insertuntil(root, word);
    }

    // SEARCH WORD IN TRIE
    bool searchuntil(TrieNode* root, string word) {

        // Base case: word exists only if its last node is terminal
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;
        // If character exists, search the remaining word
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else{
            //absent 
            return false;
        }

        //recursion call
        return searchuntil(child,word.substr(1));
    }

    bool searchword(string word) {
        return searchuntil(root, word);
    }

    // CHECK WHETHER A NODE HAS ANY CHILDREN
    bool hasChildren(TrieNode* node) {
        for(int i = 0; i < 26; i++) {
            if(node->children[i] != NULL) {
                return true;
            }
        }

        return false;
    }

    // DELETE WORD RECURSIVELY
    bool removeuntil(TrieNode* root, string word, int depth = 0) {

        // Safety check: node does not exist
        if(root == NULL) {
            return false;
        }

        // Base case: reached the end of the word
        if(depth == word.length()) {

            // Word is not present as a complete word
            if(!root->isTerminal) {
                return false;
            }

            // Mark the word as deleted
            root->isTerminal = false;

            // Delete this node only if it has no children
            return !hasChildren(root);
        }

        // Find the index of the current character
        int index = word[depth] - 'A';
        TrieNode* child = root->children[index];

        // Character not found, so nothing to delete
        if(child == NULL) {
            return false;
        }

        // Recursively delete the remaining characters
        bool shouldDelete = removeuntil(child, word, depth + 1);

        // Delete node only when it is no longer needed
        if(shouldDelete) {
            delete child;
            root->children[index] = NULL;

            // Keep the current node if it is terminal
            // or has other children
            return !root->isTerminal && !hasChildren(root);
        }

        return false;
    }

    void removeword(string word) {
        removeuntil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    t->insertword("ARM");
    t->insertword("DO");
    t->insertword("TIME");

    cout << "TIME present: " << t->searchword("TIME") << endl;

    t->removeword("TIME");

    cout << "TIME present: " << t->searchword("TIME") << endl;
    cout << "ARM present: " << t->searchword("ARM") << endl;

    return 0;
}