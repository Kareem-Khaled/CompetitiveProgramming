/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://codeforces.com/contest/449/problem/B
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
vector<vector<pair<pair<int, bool>, int>>>adj;
vector<int>dis;
void dijkistra(){
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
	pq.push({ 0, 0 }); dis[0] = 0;
	while (pq.size()){
		pair<ll, int>u = pq.top(); pq.pop();
		if (dis[u.second] != u.first)continue;
		for (auto v : adj[u.second]){
			if (dis[v.second] > dis[u.second] + v.first.first){
				dis[v.second] = dis[u.second] + v.first.first;
				pq.push({ dis[v.second], v.second });
			}
		}
	}
}
int main(){
	K_K();
	int n, m, k; cin >> n >> m >> k; dis = vector<int>(n, oo);
	adj = vector<vector<pair<pair<int, bool>, int>>>(n);
	while (m--){
		int u, v, c; cin >> u >> v >> c;
		adj[--u].push_back({ { c, 0 }, --v });
		adj[v].push_back({ { c, 0 }, u });
	}
	for (int i = 0; i < k; i++){
		int v, c; cin >> v >> c;
		adj[0].push_back({ { c, 1 }, --v });
		adj[v].push_back({ { c, 1 }, 0 });
	}
	dijkistra(); vector<bool>road(n), train(n);
	for (int u = 0; u < n; u++){
		for (auto v : adj[u]){
			if (dis[v.second] == dis[u] + v.first.first){
				if (v.first.second)
					train[v.second] = 1;
				else
					road[v.second] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++){
		cnt += (train[i] && !road[i]);
	}
	cout << k - cnt;
}