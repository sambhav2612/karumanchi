#include "../headers.hpp"

class TrieNode
{
    char *data;
    int end_of_string;
    TrieNode *child[];

  public:
    TrieNode()
    {
        this->data = nullptr;
        this->end_of_string = 0;
        *this->child = nullptr;
    }
    TrieNode(char *word)
    {
        this->data = word;
    }
};

class Trie
{
  public:
    TrieNode *insert(Trie *root, char *word);
    TrieNode *subNode(Trie *root, char c);
    int search(Trie *root, char *word);
}

TrieNode *
Trie::insert(Trie *root, char *word)
{
    if (word == nullptr)
        return;
    if (root == nullptr)
    {
        TrieNode newNode = new TrieNode(word);
        for (int i = 0; i < 26; ++i)
            newNode->child[i] = nullptr;
        if (!*(word + 1))
            newNode->end_of_string = 1;
        else
            newNode->child[*word] = insert(newNode->child[*word], word + 1);
        return newNode;
    }
    root->child[*word] = insert(root->child[*word], word + 1);
    return root;
}

TrieNode *Trie::subNode(Trie *root, char c)
{
    if (chaild != nullptr)
        for (int i = 0; i < 26; ++i)
            if (root.child[i]->data == c)
                return root;
    return nullptr;
}

int Trie::search(Trie *root, char *word)
{
    if (root == nullptr)
        return -1;
    if (*word == nullptr)
        if (root->end_of_string)
            return 1;
        else
            return -1;
    if (root->data == *word)
        return search(root->child[*word], word + 1);
    else
        return -1;
}