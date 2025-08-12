/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description

// DFS Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root, string &res){
        if(!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ",";
        dfs(root->left, res);
        dfs(root->right, res);
    }
    string serialize(TreeNode* root) {
        string res = "";
        dfs(root, res);
        return res;
    }

    TreeNode* solve(int &idx, string &data){
        if(idx == data.size()) return NULL;

        int nxt = data.find(',', idx);
        string cur = data.substr(idx, nxt - idx);
        idx = nxt + 1;

        if(cur == "#") return NULL;

        TreeNode* node = new TreeNode(stoi(cur));
        node->left = solve(idx, data);
        node->right = solve(idx, data);

        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return solve(idx, data);
    }
};

// BFS Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // BFS helper for serialization
    void bfs(TreeNode* root, string &res) {
        if (!root) {
            res += "#,";
            return;
        }

        queue<TreeNode*> qu; 
        qu.push(root);

        while (!qu.empty()) {
            auto cur = qu.front(); qu.pop();
            if (cur) {
                res += to_string(cur->val) + ",";
                qu.push(cur->left);
                qu.push(cur->right);
            } 
            else res += "#,";
        }
    }

    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
        string res;
        bfs(root, res);
        return res;
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        string tmp = "";
        vector<string> nodes;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                nodes.push_back(tmp);
                tmp = "";
            } 
            else 
                tmp += data[i];
        }

        if (nodes[0] == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> qu; qu.push(root);

        int idx = 1;
        while (!qu.empty() && idx < nodes.size()) {
            auto cur = qu.front(); qu.pop();

            if (nodes[idx] != "#") {
                cur->left = new TreeNode(stoi(nodes[idx]));
                qu.push(cur->left);
            }
            idx++;

            if (idx < nodes.size() && nodes[idx] != "#") {
                cur->right = new TreeNode(stoi(nodes[idx]));
                qu.push(cur->right);
            }
            idx++;
        }

        return root;
    }
};
