/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/contest/1406/problem/C
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl "\n"
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define rt(s) return cout<<s,0
#define sz(s)	(int)(s.size())
#define OO 0x3f3f3f3f3f3f3f3fLL
#define oo 0x3f3f3f3f
using namespace std;
typedef long long ll;
int dx[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] { 0, 0, 1, -1, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vector<vector<int>>adjL;
vector<int>Sz, mx, dep, cent; int n;
void dfs(int node, int par) {
	Sz[node] = 1; dep[node] = dep[par] + 1;
	for (auto ch : adjL[node]){
		if (ch == par) continue;
		dfs(ch, node); Sz[node] += Sz[ch];
		mx[node] = max(mx[node], Sz[ch]);
	}
	mx[node] = max(mx[node], n - Sz[node]);
	if (sz(cent) && mx[node] < mx[cent[0]]) cent.clear();
	if (!sz(cent) || mx[node] == mx[cent[0]]) cent.push_back(node);
}
int main(){
	K_K();
	int t; cin >> t;
	while (t--){
		cin >> n;
		adjL = vector<vector<int>>(n + 1);
		Sz = mx = dep = vector<int>(n + 1);
		for (int i = 1; i < n; i++){
			int u, v; cin >> u >> v;
			adjL[u].push_back(v);
			adjL[v].push_back(u);
		}
		cent.clear(); dfs(1, 0);
		if (sz(cent) == 1)
			cout << "1 " << adjL[1][0] << "\n1 " << adjL[1][0] << endl;
		else {
			int ch = cent[0], par = cent[1];
			if (dep[par] > dep[ch]) swap(ch, par);
			int c = 0;
			for (int t : adjL[ch]) {
				if (t != par && Sz[t] > Sz[c]) c = t;
			}
			cout << ch << ' ' << c << endl << par << ' ' << c << endl;
		}
	}
}