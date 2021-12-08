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
vector<pair<int, int>>arr;
vector<int>sufmn, sufmx;
int main(){
	K_K();
	int n; cin >> n; arr = vector<pair<int, int>>(n);
	for (auto &it : arr)cin >> it.first >> it.second;
	sufmn = sufmx = vector<int>(n); sort(all(arr));
	sufmn[n - 1] = sufmx[n - 1] = arr.back().second;
	for (int i = n - 2; i > -1; i--){
		sufmn[i] = min(arr[i].second, sufmn[i + 1]);
		sufmx[i] = max(arr[i].second, sufmx[i + 1]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		int l = 0, r = 1e9;
		while (l <= r){
			int md = (l + r) >> 1; pair<int, int>p{ arr[i].first + md, -1 };
			int idx = lower_bound(all(arr), p) - arr.begin();
			if (idx == n){
				r = md - 1; continue;
			}
			if (abs(sufmn[idx] - arr[i].second) >= md || abs(sufmx[idx] - arr[i].second) >= md)
				ans = max(ans, md), l = md + 1;
			else
				r = md - 1;
		}
	}
	cout << ans;
}