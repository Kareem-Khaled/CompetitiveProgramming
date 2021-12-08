/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://codeforces.com/problemset/problem/1473/D
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <stdio.h>
#include<unordered_map>
#define endl "\n"
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define rt(s) return cout<<s,0
#define sz(s)	(int)(s.size())
#define OO 0x3f3f3f3f3f3f3f3fLL
#define oo 0x3f3f3f3f
typedef long long ll;
using namespace std;
int dx[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] { 0, 0, 1, -1, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
const int N = 2e5 + 2;
int n; vector<int>arr;
pair<int, int> table[N][20];
void buildTable(){
	for (int i = 0; i < n; i++)table[i][0] = { arr[i], arr[i] };
	for (int j = 1; (1 << j) <= n; j++){
		for (int i = 0; i + (1 << j) <= n; i++){
			table[i][j].first = min(table[i][j - 1].first, table[i + (1 << (j - 1))][j - 1].first);
			table[i][j].second = max(table[i][j - 1].second, table[i + (1 << (j - 1))][j - 1].second);
		}
	}
}
int LOG(int x){
	return 31 - __builtin_clz(x);
}
int solve(int l, int r, int ch){
	int x = LOG(r - l + 1);
	if (ch)	return min(table[l][x].first, table[r - (1 << x) + 1][x].first);
	return max(table[l][x].second, table[r - (1 << x) + 1][x].second);
}
int main(){
	K_K();
	int t; cin >> t;
	while (t--){
		int q; cin >> n >> q; arr = vector<int>(++n);
		for (int i = 1; i < n; i++){
			char ch; cin >> ch;
			arr[i] = arr[i - 1] + (ch == '+' ? 1 : -1);
		}
		buildTable();
		while (q--){
			int l, r; cin >> l >> r;
			int lmn = solve(0, l - 1, 1), lmx = solve(0, l - 1, 0);
			int rmn = oo, rmx = -oo;
			if (r + 1 < n){
				int dif = arr[r] - arr[l - 1];
				rmn = solve(r + 1, n - 1, 1) - dif;
				rmx = solve(r + 1, n - 1, 0) - dif;
			}
			cout << max(lmx, rmx) - min(lmn, rmn) + 1 << endl;
		}
	}
}