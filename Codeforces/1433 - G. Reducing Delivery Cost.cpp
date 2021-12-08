/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://codeforces.com/contest/1433/problem/G
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
int dx[] { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] { 0, 1, 0, -1, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vector<vector<int>>dis;
vector<vector<pair<int, int>>>adj;
void dijkistra(int src){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0, src }); dis[src][src] = 0;
	while (sz(pq)){
		pair<int, int>u = pq.top(); pq.pop();
		if (dis[src][u.second] != u.first)continue;
		for (auto v : adj[u.second]){
			if (dis[src][v.second] > dis[src][u.second] + v.first){
				dis[src][v.second] = dis[src][u.second] + v.first;
				pq.push({ dis[src][v.second], v.second });
			}
		}
	}
}
int main(){
	K_K();
	int n, m, k; cin >> n >> m >> k;
	adj = vector<vector<pair<int, int>>>(n);
	dis = vector<vector<int>>(n, vector<int>(n, oo));
	vector<pair<int, int>>edges, delv;
	while (m--){
		int u, v; int c; cin >> u >> v >> c;
		adj[--u].push_back({ c, --v });
		adj[v].push_back({ c, u });
		edges.push_back({ u, v });
	}
	for (int i = 0; i < n; i++){
		dijkistra(i);
	}
	while (k--){
		int u, v; cin >> u >> v;
		delv.push_back({ --u, --v });
	}
	ll ans = OO;
	for (auto ed : edges){
		ll cur = 0;
		for (auto dev : delv){
			cur += min({ dis[dev.first][dev.second],
				dis[dev.first][ed.first] + dis[ed.second][dev.second],
				dis[dev.first][ed.second] + dis[ed.first][dev.second]
			});
		}
		ans = min(ans, cur);
	}
	cout << ans;
}