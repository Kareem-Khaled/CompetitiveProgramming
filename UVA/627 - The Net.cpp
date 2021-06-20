/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link:https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=568&mosmsg=Submission+received+with+ID+26487896
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
int dx[] { 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[] { 0, 1, -1, 0, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int n;
vector<vector<int>>adjL;
void bfs(int s, int d){
	vector<int>mem(n + 1, oo), per(n + 1, -1);
	queue<pair<int, int>>qu; qu.push({ s, 0 });
	mem[s] = 0;
	while (sz(qu)){
		pair<int, int>cur = qu.front(); qu.pop();
		bool ok = 0;
		for (auto child : adjL[cur.first]){
			if (mem[child] == oo){
				per[child] = cur.first;
				mem[child] = cur.second + 1;
				qu.push({ child, mem[child] });
				if (child == d){
					ok = 1; break;
				}
			}
		}
		if (ok)break;
	}
	vector<int>path;
	while (d != -1){
		path.push_back(d);
		d = per[d];
	}
	if (sz(path) == 1){
		cout << "connection impossible\n"; return;
	}
	cout << path[sz(path) - 1];
	for (int i = sz(path) - 2; i > -1; i--)
		cout << ' ' << path[i];
	cout << endl;
}
int main() {
	K_K();
	while (cin >> n){
		adjL = vector<vector<int>>(n + 1);
		for (int i = 0; i < n; i++){
			int u; cin >> u;
			string s; getline(cin, s);
			stringstream r(s);
			char ch; int v;
			while (r >> ch >> v)
				adjL[u].push_back(v);
		}
		cout << "-----\n";
		int m; cin >> m;
		while (m--){
			int s, e; cin >> s >> e;
			bfs(s, e);
		}
	}
}