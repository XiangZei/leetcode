/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Trie {
public:
    struct Node{
        Node *next[26];
        bool isEnd;
        Node(bool end):isEnd(end){
            for(int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    }*root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int loca = 0;
        Node* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            loca = word[i]-'a';
            if(tmp->next[loca]==NULL){
            tmp->next[loca] = new Node(false);

            }
            tmp = tmp->next[loca];
        }
        tmp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int loca = 0;
        Node* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            loca = word[i] - 'a';
            if(tmp->next[loca] == NULL) {
                return false;
            }
            tmp = tmp->next[loca];
        }
        return tmp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int loca = 0;
        Node* tmp = root;
        for(int i = 0; i < word.size(); i++) {
            loca = word[i] - 'a';
            if(tmp->next[loca] == NULL) {
                return false;
            }
            tmp = tmp->next[loca];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

