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
int n, m;
vector<int>par, sum, szz, id;
int findpar(int u){
	if (u == par[u])return u;
	return par[u] = findpar(par[u]);
}
void join(int u, int v){
	u = findpar(id[u]);
	v = findpar(id[v]);
	if (u != v){
		par[v] = u;
		szz[u] += szz[v];
		sum[u] += sum[v];
	}
}
void move(int u, int v){
	int a = findpar(id[u]);
	int b = findpar(id[v]);
	if (a != b){
		szz[a]--;
		sum[a] -= u;
		id[u] = ++n;
		szz.push_back(1);
		sum.push_back(u);
		par.push_back(n);
		join(u, v);
	}
}
int main(){
	K_K();
	while (cin >> n >> m){
		par = sum = szz = id = vector<int>(n + 1, 1);
		iota(all(par), 0); iota(all(sum), 0); iota(all(id), 0);
		while (m--){
			int t, u, v; cin >> t >> u;
			if (t == 1){
				cin >> v; join(u, v);
			}
			else if (t == 2){
				cin >> v; move(u, v);
			}
			else{
				u = findpar(id[u]);
				cout << szz[u] << ' ' << sum[u] << endl;
			}
		}
	}
}