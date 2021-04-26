/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://codeforces.com/contest/221/problem/D
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl "\n"
#define Ceil(x,y) ((x+y-1)/y)
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define rt(s) return cout<<s,0
#define sz(s)	(int)(s.size())
#define oo 0x7FFFFFFF
#define OO 0x7FFFFFFFFFFFFFFFLL
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
int main(){
	K_K();
	int n, m; cin >> n >> m;
	vector<int>arr(n), nums;
	map<int, int>frq;
	for (auto &it : arr){
		cin >> it;
		if (it <= n)
			frq[it]++;
	}
	for (auto it : frq){
		if (it.second >= it.first)
			nums.push_back(it.first);
	}
	vector<vector<int>>prefx(sz(nums), vector<int>(n + 1));
	for (int i = 0; i < sz(nums); i++){
		for (int j = 1; j <= n; j++){
			prefx[i][j] = prefx[i][j - 1] + (arr[j - 1] == nums[i]);
		}
	}
	while (m--){
		int l, r; cin >> l >> r; int ans = 0;
		for (int i = 0; i < sz(nums); i++)
			ans += (prefx[i][r] - prefx[i][l - 1] == nums[i]);
		cout << ans << endl;
	}
}