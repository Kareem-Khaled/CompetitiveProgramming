/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1665
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
int n, m; vector<vector<double>>adj;
void floyd(){
	for (int k = 0; k < n; k++){
		for (int u = 0; u < n; u++){
			for (int v = 0; v < n; v++)
				adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
		}
	}
}
double dis(int x, int y, int x1, int y1){
	return sqrt(pow(x - x1, 2) + pow(y - y1, 2));
}
int main(){
	K_K();
	while (cin >> n >> m, n || m){
		adj = vector<vector<double>>(n, vector<double>(n, OO));
		for (int i = 0; i < n; i++)adj[i][i] = 0;
		vector<int>x(n), y(n); vector<vector<bool>>vis(n, vector<bool>(n, 0));
		for (int i = 0; i < n; i++)cin >> x[i] >> y[i];
		while (m--){
			int u, v; cin >> u >> v; u--; v--;
			adj[u][v] = adj[v][u] = dis(x[u], y[u], x[v], y[v]);
			vis[u][v] = vis[v][u] = 1;
		}
		floyd(); double ans = 0; int U = -1, V = -1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (vis[i][j])continue;
				double disij = dis(x[i], y[i], x[j], y[j]), sum = 0;
				for (int u = 0; u < n; u++){
					for (int v = 0; v < n; v++){
						double cur = min({ adj[u][v],
							adj[u][i] + disij + adj[j][v],
							adj[u][j] + disij + adj[i][v] });
						sum += (adj[u][v] - cur);
					}
				}
				if (sum>ans){
					ans = sum; U = i + 1, V = j + 1;
				}
			}
		}
		if (!~U)cout << "No road required\n";
		else cout << U << ' ' << V << endl;
	}
}