/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://leetcode.com/problems/word-search-ii
class Trie{
public: 
    struct Node {
        Node* child[26];
        string word;
        Node(): word("") {
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string& word){
        Node* node = root;
        for(auto &ch : word){
            if(node->child[ch - 'a'] == NULL){
                node->child[ch - 'a'] = new Node();
            }
            node = node->child[ch - 'a'];
        }
        node->word = word;
    }
};

class Solution {
public:
    int n, m;
    vector<string> ans;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    bool valid(int i, int j){
        return i > -1 && j > -1 && i < n && j < m;
    }

    void dfs(int i, int j, vector<vector<char>> &board, Trie::Node *node){
        char c = board[i][j];
        int ch = board[i][j] - 'a';
        if(c == '#' || node->child[ch] == NULL) return;

        node = node->child[ch];
        if(!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';
        for(int k = 0; k < 4; k++){
            int x = dx[k] + i;
            int y = dy[k] + j;
            if(valid(x, y))
                dfs(x, y, board, node);
        }
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();
    	Trie trie = Trie();
        for(auto &it : words){
            trie.insert(it);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i, j, board, trie.root);
            }
        }
        return ans;
    }
};
