/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://www.spoj.com/problems/LCA/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <stdio.h>
#include<unordered_map>
#define endl "\n"
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define rt(s) return cout<<s,0
#define sz(s)	(int)(s.size())
#define OO 0x3f3f3f3f3f3f3f3fLL
#define oo 0x3f3f3f3f
typedef long long ll;
using namespace std;
int dx[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] { 0, 0, 1, -1, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
const int m = 20;
vector<vector<int>>adj, anc;
int n; vector<int>dep;
void dfs(int node, int par){
	for (auto child : adj[node]){
		if (child == par)continue;
		anc[child][0] = node;
		dep[child] = dep[node] + 1;
		for (int i = 1; i < m; i++)
			anc[child][i] = anc[anc[child][i - 1]][i - 1];
		dfs(child, node);
	}
}
int k_anc(int node,int k){
	for (int i = 0; i < m; i++){
		if (k&(1 << i))
			node = anc[node][i];
	}
	return node;
}
int LCA(int u, int v){
	if (dep[u] < dep[v])swap(u, v);
	int k = dep[u] - dep[v];
	u = k_anc(u, k);
	if (u == v)return u;
	for (int i = m - 1; i>-1; i--){
		if (anc[u][i] != anc[v][i]){
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return anc[u][0];
}
int main(){
	K_K();
	int t; cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> n; dep = vector<int>(n); adj = vector<vector<int>>(n);
		anc = vector<vector<int>>(n, vector<int>(m));
		for (int u = 0; u < n; u++){
			int m; cin >> m;
			while (m--){
				int v; cin >> v;
				adj[u].push_back(--v);
			}
		}
		cout << "Case " << i << ":\n";
		int q; cin >> q; dfs(0, 0);
		while (q--){
			int u, v; cin >> u >> v;
			cout << LCA(--u, --v) + 1 << endl;
		}
	}
}