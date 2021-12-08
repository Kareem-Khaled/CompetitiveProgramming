/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://www.spoj.com/problems/TRSTAGE/
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
int n, m, p, a, b; vector<int>hr;
vector<vector<pair<int, int>>>adj; 
double dp[(1 << 10)][33];
double solve(int mask, int lst){
	if (lst == b) return 0;
	if (mask == (1 << n) - 1)return oo;
	double &ret = dp[mask][lst];
	if (ret != -1)return ret; ret = oo;
	for (auto u : adj[lst]){
		for (int i = 0; i < n; i++){
			if ((mask & (1 << i)))continue;
			ret = min(ret, solve((mask | (1 << i)), u.first) + (1.0 * u.second / hr[i]));
		}
	}
	return ret;
}
int main(){
	K_K();
	while (cin >> n >> m >> p >> a >> b, (n || m || p || a || b)){
		hr = vector<int>(n); for (auto &it : hr)cin >> it;
		adj = vector<vector<pair<int, int>>>(++m);
		for (int i = 0; i < p; i++){
			int u, v, c; cin >> u >> v >> c;
			adj[u].push_back({ v, c });
			adj[v].push_back({ u, c });
		}
		for (int i = 0; i < (1 << 10); i++){
			for (int j = 0; j < 33; j++)
				dp[i][j] = -1;
		}
		double ans = solve(0, a);
		if (ans == oo)cout << "Impossible\n";
		else cout << fixed << setprecision(3) << ans << endl;
	}
}