/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2259
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
int n, m, p; 
const double EPS = 1e-8;
vector<vector<double>>adj;
vector<int>str; vector<double>pr;
double dp[(1 << 14)][14];
void floyd(){
	for (int k = 0; k < n; k++){
		for (int u = 0; u < n; u++){
			for (int v = 0; v < n; v++)
				adj[u][v] = min(adj[u][v], adj[u][k] + adj[k][v]);
		}
	}
}
double solve(int mask, int lst){
	if (mask == (1 << p) - 1)
		return adj[str[lst]][str[0]];
	double &ret = dp[mask][lst];
	if (ret != -OO)return ret; ret = adj[str[lst]][str[0]];
	for (int i = 0; i < p; i++){
		if ((mask & (1 << i)) == 0)
			ret = min(ret, solve((mask | (1 << i)), i) + adj[str[lst]][str[i]] - pr[i]);
	}
	return ret;
}
int main(){
	K_K();
	int t; cin >> t;
	while (t--){
		cin >> n >> m; n++;
		adj = vector<vector<double>>(n, vector<double>(n, OO));
		for (int i = 0; i < n; i++)adj[i][i] = 0;
		while (m--){
			int u, v; double c; cin >> u >> v >> c;
			adj[u][v] = adj[v][u] = min(adj[u][v], c);
		}
		for (int i = 0; i < (1 << 14); i++){
			for (int j = 0; j < 14; j++)
				dp[i][j] = -OO;
		}
		floyd(); cin >> p; p++;
		str = vector<int>(p, 0);
		pr = vector<double>(p, 0);
		for (int i = 1; i < p; i++){
			cin >> str[i] >> pr[i];
		}
		double ans = -solve(1, 0);
		if (ans > EPS)
			cout << fixed << setprecision(2) << "Daniel can save $" << ans << endl;
		else
			cout << "Don't leave the house\n";
	}
}