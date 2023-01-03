/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://leetcode.com/problems/sum-of-distances-in-tree/
class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>vis;
    vector<int>dis, ans;
    int dfs(int node){
        vis[node] = 1;
        int cnt = 1;
        for(auto child : adj[node]){
            if(!vis[child]){
                int x = dfs(child);
                cnt += x;
                ans[0] += x;
            }
        }
        dis[node] = cnt;
        return cnt;
    }
    void dfs2(int node, int n){
        vis[node] = 1;
        for(auto child : adj[node]){
            if(!vis[child]){
                ans[child] = ans[node] - dis[child] + (n - dis[child]);
                dfs2(child, n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n);
        vis = vector<bool>(n, 0);
        dis = ans = vector<int>(n, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0);
        vis = vector<bool>(n, 0);
        dfs2(0, n);
        return ans;
    }
};