/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2938
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
vector<vector<int>>adjL, comps;
vector<int>inSt, low, dfn;
stack<int>st; int ndfn, n, m;
void tarjan(int node) {
	low[node] = dfn[node] = ndfn++;
	inSt[node] = 1; st.push(node);

	for (auto child : adjL[node]) {
		if (!~dfn[child]) {// not visited
			tarjan(child);
			low[node] = min(low[node], low[child]);
		}
		else if (inSt[child]) // connected with me in the same call
			low[node] = min(low[node], dfn[child]);
	}

	if (low[node] == dfn[node]) { // root for SCC
		comps.push_back(vector<int>()); int x = -1;
		while (x != node) {
			x = st.top(); st.pop(); inSt[x] = 0;
			comps.back().push_back(x);
		}
	}
}
int main(){
	K_K();
	while (cin >> n >> m && n){
		adjL = vector<vector<int>>(n + 1);
		for (int i = 0; i < m; i++){
			int v, w, p; cin >> v >> w >> p;
			adjL[v].push_back(w);
			if (p == 2)
				adjL[w].push_back(v);
		}
		inSt = low = dfn = vector<int>(n + 1, -1);
		for (int i = 1; i <= n; i++) {
			if (!~dfn[i])
				tarjan(i);
		}
		cout << (sz(comps) == 1) << endl; comps.clear();
	}
}