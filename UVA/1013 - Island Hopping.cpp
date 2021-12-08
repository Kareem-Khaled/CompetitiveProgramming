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
int dx[] { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] { 0, 1, 0, -1, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vector<int>par, h;
vector<pair<ll, pair<int, int>>>islands;
int findpar(int u){
	if (u == par[u])return u;
	return par[u] = findpar(par[u]);
}
void join(int u, int v){
	u = findpar(u);
	v = findpar(v);
	if (u != v){
		if (u > v)swap(u, v);
		par[v] = u; h[u] += h[v];
	}
}
double kruskal(){
	double ret = 0;
	sort(all(islands));
	iota(all(par), 0);
	for (int i = 0; i < sz(islands); i++){
		int u = findpar(islands[i].second.first);
		int v = findpar(islands[i].second.second);
		if (u != v){
			if (u>v)swap(u, v);
			if (!u) ret += sqrt(islands[i].first) * h[v];
			join(u, v);
		}
	}
	return ret;
}
int main(){
	K_K();
	int n, t = 0;
	while (cin >> n, n) {
		par = h = vector<int>(n);
		vector<int>x(n), y(n); 
		islands.clear(); ll H = 0;
		for (int i = 0; i < n; i++){
			cin >> x[i] >> y[i] >> h[i]; H += h[i];
		}
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				ll X = x[i] - x[j];
				ll Y = y[i] - y[j];
				islands.push_back({ X*X + Y*Y, { i, j } });
			}
		}
		cout << fixed << setprecision(2);
		cout << "Island Group: " << ++t << " Average " << kruskal() / H << "\n\n";
	}
}