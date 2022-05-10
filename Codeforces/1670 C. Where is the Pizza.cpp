/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/contest/1670/problem/C
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define endl "\n"
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define rt(s) return cout<<s,0
#define sz(s)	(int)(s.size())
#define OO 0x3f3f3f3f3f3f3f3fLL
#define oo 0x3f3f3f3f
using namespace std;
typedef long long ll;
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void K_K() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
const int N = 1e5 + 3, mod = 1e9 + 7;
int vis[N], a[N], b[N], aa[N], bb[N], id;
ll power(ll x, ll k){
	ll ret = 1;
	while (k){
		if (k & 1) ret = (ret*x) % mod;
		k >>= 1; x = (x*x) % mod;
	}
	return ret;
}
void dfs(int idx, bool flag){
    if(vis[idx] == id) return;
    vis[idx] = id;
    dfs((flag ? bb[a[idx]] : aa[b[idx]]), flag);
}
int main() {
	K_K();
	int t; cin >> t;
	while(t--){
	    int n; cin >> n; id++;
    	for(int i = 0; i < n; i++) {
            cin >> a[i];
            aa[a[i]] = i;
    	}
    	for(int i = 0; i < n; i++) {
            cin >> b[i];
            bb[b[i]] = i;
    	}
    	for(int i = 0; i < n; i++) {
    	    int x; cin >> x; 
    	    if(x == a[i])
    	        dfs(i, 0);
    	    else if (x == b[i])
    	        dfs(i, 1);
    	}
    	int cnt = 0;
    	for(int i = 0; i < n; i++) {
    	    if(vis[i] == id || a[i] == b[i]) continue;
    	    dfs(i, 0); cnt++;
    	}
    	cout << power(2, cnt) << endl;
	}
}