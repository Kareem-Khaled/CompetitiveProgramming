/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://codeforces.com/contest/1678/problem/B2
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
const int N = 2e5 + 5;
int n, dp[N][2][2]; string s;
int solve(int idx, int lst, int soFar){
    if(idx == n)
        return (soFar ? oo : 0);
    int &ret = dp[idx][lst][soFar];
    if(~ret)return ret; ret = oo;
	for (int cur = 0; cur < 2; cur++) {
		int ch = s[idx] - '0';
		if (!soFar)
			ret = min(ret, solve(idx + 1, cur, 1) + (cur != ch));
		if (lst == cur)
			ret = min(ret, solve(idx + 1, cur, 1 - soFar) + (cur != ch));
	}
	return ret;
}
int dp2[N][2][2];
int build(int idx, int lst, int soFar){
    if(idx == n) return 0;
    int &ret = dp2[idx][lst][soFar];
    if(~ret)return ret;  ret = oo;
    int solv = solve(idx, lst, soFar);
	for (int cur = 0; cur < 2; cur++) {
		int ch = s[idx] - '0';
		if (!soFar && solv == solve(idx + 1, cur, 1) + (cur != ch))
            ret = min(ret, build(idx + 1, cur, 1) + 1);
		if (lst == cur && solv == solve(idx + 1, cur, 1 - soFar) + (cur != ch))
			ret = min(ret, build(idx + 1, cur, 1 - soFar));
	}
	return ret;
}
void clear(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = dp2[i][j][k] = -1;
}
int main() {
	K_K();
    int t; cin >> t;
	while (t--) {
		cin >> n >> s; clear();
		int ans = solve(1, s[0] - '0', 1);
		int mn = build(1, s[0] - '0', 1);
		int tmp = solve(1, 1 - (s[0] - '0'), 1) + 1;
		if (ans > tmp)
			ans = tmp, mn = build(1, 1 - (s[0] - '0'), 1);
		else if (tmp == ans)
			mn = min(mn, build(1, 1 - (s[0] - '0'), 1));
		cout << ans << ' ' << mn + 1 << endl;
	}
}