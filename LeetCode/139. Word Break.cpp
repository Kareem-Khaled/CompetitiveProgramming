/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://leetcode.com/problems/word-break/?envType=problem-list-v2

class Trie{
public:
    struct Node{
        Node* child[26];
        bool leaf;
        Node(): leaf(0) {
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string &word){
        auto cur = root;
        for(auto &it : word){
            if(cur->child[it - 'a'] == NULL){
                cur->child[it - 'a'] = new Node();
            }
            cur = cur->child[it - 'a'];
        }
        cur->leaf = 1;
    }

    bool search(int idx, Trie::Node* cur, string &word, vector<int> &dp){
        if(idx == word.size()) return 1;
        if(~dp[idx]) return dp[idx];

        for(int i = idx; i < word.size(); i++){
            int ch = word[i] - 'a';
            
            if(!cur->child[ch]) break;
            cur = cur->child[ch];

            if(cur->leaf && search(i + 1, root, word, dp))
                return dp[idx] = 1;
        }

        return dp[idx] = 0;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie = Trie();
        for(auto &it : wordDict){
            trie.insert(it);
        }
        vector<int> dp(s.size(), -1);
        return trie.search(0, trie.root, s, dp);
    }
};
