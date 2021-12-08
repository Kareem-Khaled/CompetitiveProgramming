/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl "\n"
#define Ceil(x,y) ((x+y-1)/y)
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define rt(s) return cout<<s,0
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define sz(s)	(int)(s.size())
#define OO 0x3f3f3f3f3f3f3f3fLL
#define oo 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
int dx[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] { 0, 0, 1, -1, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vector<int>in, out;
vector<pair<int, pair<int, int>>>ans;
vector<vector<pair<int, int>>>adj;
void bfs(int node){
	queue<pair<int, int>>qu; qu.push({ node, oo });
	while (sz(qu)){
		pair<int, int>cur = qu.front(); qu.pop();
		if (!out[cur.first] && in[cur.first] == 1){
			ans.push_back({ node, { cur.first, cur.second } });
			out[cur.first] = 1;
		}
		for (auto child : adj[cur.first]){
			qu.push({ child.first, min(cur.second, child.second) });
		}
	}
}
int main(){
	K_K();
	int n, p; cin >> n >> p;
	in = out = vector<int>(n + 1, 0);
	adj = vector<vector<pair<int, int>>>(n + 1);
	for (int i = 0; i < p; i++){
		int u, v, c; cin >> u >> v >> c;
		adj[u].push_back({ v, c });
		out[u]++; in[v]++;
	}
	for (int i = 1; i <= n; i++){
		if (!in[i] && out[i] == 1)
			bfs(i);
	}
	cout << sz(ans) << endl;
	for (auto it : ans)cout << it.first << ' ' << it.second.first << ' ' << it.second.second << endl;
}