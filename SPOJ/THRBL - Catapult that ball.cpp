/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://www.spoj.com/problems/THRBL/
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
const int N = 1e5 + 2;
int n; vector<int>arr;
int table[N][20];
void buildTable(){
	for (int i = 0; i < n; i++)table[i][0] = arr[i];
	for (int j = 1; (1 << j) <= n; j++){
		for (int i = 0; i + (1 << j) <= n; i++){
			table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int LOG(int x){
	return 31 - __builtin_clz(x);
}
int solve(int l, int r){
	int x = LOG(r - l + 1);
	return max(table[l][x], table[r - (1 << x) + 1][x]);
	// log(n)
	//int x = (r - l + 1), st = l, mx = 0;
	//for (int j = 0; j < 20; j++){
	//	if (x&(1 << j)){
	//		mx = max(mx, table[st][j]);
	//		st += (1 << j);
	//	}
	//}
	//return mx;
}
int main(){
	K_K();
	int q; cin >> n >> q; arr = vector<int>(n);
	for (auto &it : arr)cin >> it;
	buildTable(); int cnt = 0;
	while (q--){
		int l, r; cin >> l >> r;
		if (abs(l - r) <= 1){
			cnt++; continue;
		}
		l--; r -= 2;
		if (l > r)swap(l, r);
		cnt += (solve(l, r) <= arr[l]);
	}
	cout << cnt;
}