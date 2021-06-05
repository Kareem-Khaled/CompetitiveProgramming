/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1567
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
int dx[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] { 0, 0, 1, -1, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int dp[155][155][100];
int solve(int cur, int n1, int n5, int n10){
	if (!cur) return 0;
	int &ret = dp[cur][n5][n10];
	if (~ret)return ret; ret = oo;
	if (n1 - 8 >= 0)
		ret = min(ret, solve(cur - 1, n1 - 8, n5, n10) + 8);
	if (n5 - 2 >= 0)
		ret = min(ret, solve(cur - 1, n1 + 2, n5 - 2, n10) + 2);
	if (n10)
		ret = min(ret, solve(cur - 1, n1 + 2, n5, n10 - 1) + 1);
	if (n5 && n1 - 3 >= 0)
		ret = min(ret, solve(cur - 1, n1 - 3, n5 - 1, n10) + 4);
	if (n10 && n1 - 3 >= 0)
		ret = min(ret, solve(cur - 1,n1 - 3, n5 + 1, n10 - 1) + 4);
	return ret;
}
int main(){
	K_K();
	int t; cin >> t;
	while (t--){
		int c, n1, n5, n10;	cin >> c >> n1 >> n5 >> n10;
		clr(dp, -1); cout << solve(c, n1, n5, n10) << endl;
	}
}