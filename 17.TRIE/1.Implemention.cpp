#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];

    int cntEndWith;
    int cntPrefix;

    Node() {
        cntEndWith = 0;
        cntPrefix = 0;

        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    int getEnd() {
        return cntEndWith;
    }

    int getPrefix() {
        return cntPrefix;
    }
};

class Trie {

private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert a word
    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }

            node = node->get(ch);
            node->increasePrefix();
        }

        node->increaseEnd();
    }

    // Search exact word
    bool search(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);
        }

        return node->getEnd() > 0;
    }

    // Check prefix
    bool startsWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);
        }

        return true;
    }

    // Count exact occurrences
    int countWordsEqualTo(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return 0;

            node = node->get(ch);
        }

        return node->getEnd();
    }

    // Count words having given prefix
    int countWordsStartingWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return 0;

            node = node->get(ch);
        }

        return node->getPrefix();
    }

    // Erase one occurrence of word
    void erase(string word) {
        Node* node = root;

        for (char ch : word) {
            node = node->get(ch);
            node->reducePrefix();
        }

        node->deleteEnd();
    }
};

int main() {

    Trie trie;

    trie.insert("apple");
    trie.insert("apple");
    trie.insert("apps");
    trie.insert("app");

    cout << trie.search("apple") << endl;                  // 1
    cout << trie.search("appl") << endl;                   // 0

    cout << trie.startsWith("app") << endl;                // 1

    cout << trie.countWordsEqualTo("apple") << endl;       // 2
    cout << trie.countWordsEqualTo("app") << endl;         // 1

    cout << trie.countWordsStartingWith("app") << endl;    // 4

    trie.erase("apple");

    cout << trie.countWordsEqualTo("apple") << endl;       // 1
    cout << trie.countWordsStartingWith("app") << endl;    // 3

    return 0;
}