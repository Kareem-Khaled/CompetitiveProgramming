/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link:https://codeforces.com/contest/1301/problem/B
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl "\n"
#define Ceil(x,y) ((x+y-1)/y)
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
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
int n;
vector<int>arr;
ll sol(int m){
	ll ret = 0; bool f1 = 0, f2 = 0;
	for (int i = 1; i < n; i++){
		if (!~arr[i])f1 = 1, arr[i] = m;
		if (!~arr[i - 1])f2 = 1, arr[i - 1] = m;
		ret = max(ret, (ll)(abs(arr[i] - arr[i - 1])));
		if (f1)f1 = 0, arr[i] = -1;
		if (f2)f2 = 0, arr[i - 1] = -1;
	}
	return ret;
}
int main(){
	K_K();
	int t; cin >> t;
	while (t--){
		cin >> n; arr = vector<int>(n);
		for (auto &it : arr)cin >> it;
		int l = 0, r = 1e9, m1, m2;
		while (l <= r){
			m1 = l + (r - l) / 3;
			m2 = r - (r - l) / 3;
			if (sol(m1) > sol(m2))
				l = m1 + 1;
			else
				r = m2 - 1;
		}
		cout << sol(m1) << ' ' << m1 << endl;
	}
}