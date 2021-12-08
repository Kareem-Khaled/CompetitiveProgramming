/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
Problem Link : https://www.spoj.com/problems/NTICKETS/
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
vector<vector<pair<int, int>>>adj;
vector<vector<int>>anc, mx;
int n; vector<int>dep;
void dfs(int node, int par){
	for (auto child : adj[node]){
		if (child.first == par)continue;
		anc[child.first][0] = node;
		mx[child.first][0] = child.second;
		dep[child.first] = dep[node] + 1;
		for (int i = 1; i < m; i++){
			anc[child.first][i] = anc[anc[child.first][i - 1]][i - 1];
			mx[child.first][i] = max(mx[child.first][i - 1], mx[anc[child.first][i - 1]][i - 1]);
		}
		dfs(child.first, node);
	}
}
pair<int, int> k_anc(int node, int k){
	int mxx = 0;
	for (int i = 0; i < m; i++){
		if (k & (1 << i)){
			mxx = max(mxx, mx[node][i]);
			node = anc[node][i];
		}
	}
	return{ node, mxx };
}
int LCA(int u, int v){
	if (dep[u] < dep[v])swap(u, v);
	int k = dep[u] - dep[v];
	auto mxx = k_anc(u, k);
	u = mxx.first;
	if (u == v)return mxx.second;
	for (int i = m - 1; i > -1; i--){
		if (anc[u][i] != anc[v][i]){
			mxx.second = max({ mxx.second, mx[u][i], mx[v][i] });
			u = anc[u][i]; v = anc[v][i];
		}
	}
	return max({ mxx.second, mx[u][0], mx[v][0] });
}
int main(){
	K_K(); 
	bool flag = 0;
	while (cin >> n, n){
		dep = vector<int>(n); adj = vector<vector<pair<int, int>>>(n);
		anc = mx = vector<vector<int>>(n, vector<int>(m));
		for (int i = 1; i < n; i++){
			int u, v, c; cin >> u >> v >> c;
			adj[--u].push_back({ --v, c });
			adj[v].push_back({ u, c });
		}
		int q; cin >> q; dfs(0, 0);
		while (q--){
			int a, b; cin >> a >> b;
			cout << LCA(--a, --b) << endl;
		}
		if (flag)cout << endl; flag = 1;
	}
}