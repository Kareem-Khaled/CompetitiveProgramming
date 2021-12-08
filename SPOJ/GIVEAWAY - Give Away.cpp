/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// https://www.spoj.com/problems/GIVEAWAY/
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
int n; vector<int>arr;
vector<vector<int>>blocks;
int main(){
	K_K();
	cin >> n; arr = vector<int>(n);
	int sqr = ceil(sqrt(n));
	vector<vector<int>>blocks(sqr);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		blocks[i / sqr].push_back(arr[i]);
	}
	for (int i = 0; i < sqr; i++)sort(all(blocks[i]));
	int q; cin >> q;
	while (q--){
		int x; cin >> x;
		if (x){
			int idx; cin >> idx >> x;
			int bidx = --idx / sqr;
			int pos = lower_bound(all(blocks[bidx]), arr[idx]) - blocks[bidx].begin();
			blocks[bidx][pos] = x; sort(all(blocks[bidx])); arr[idx] = x;
		}
		else{
			int l, r; cin >> l >> r >> x;
			int cnt = 0; l--; r--;
			for (int i = l; i <= r;){
				if (i%sqr == 0 && i + sqr - 1 <= r){
					int bidx = i / sqr;
					int pos = lower_bound(all(blocks[bidx]), x) - blocks[bidx].begin();
					cnt += sqr - pos; i += sqr;
				}
				else cnt += (arr[i++] >= x);
			}
			cout << cnt << endl;
		}
	}
}