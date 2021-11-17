/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2399
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
const int N = 1e3 + 2;
string s; int dp[N][N];
int solve(int i, int j){
	if (i >= j)return (i == j);
	int &ret = dp[i][j];
	if (~ret)return ret; ret = 0;
	if (s[i] == s[j])ret = solve(i + 1, j - 1) + 2;
	else
		ret = max(solve(i + 1, j), solve(i, j - 1));
	return ret;
}
string dp2[N][N];
string build(int i, int j){
	if (i >= j){
		if (i == j)return string(1, s[i]);
		return "";
	}
	string &ret = dp2[i][j];
	if (ret != "")return ret;
	if (s[i] == s[j])
		return ret = s[i] + build(i + 1, j - 1) + s[j];
	else{
		int ans = solve(i, j);
		int ch1 = solve(i + 1, j), ch2 = solve(i, j - 1);
		if (ans == ch1 && ans == ch2)
			return ret = min(build(i + 1, j), build(i, j - 1));
		else if (ans == ch1)
			return ret = build(i + 1, j);
		else
			return ret = build(i, j - 1);
	}
}
int main(){
	K_K();
	while (cin >> s){
		clr(dp, -1); solve(0, sz(s) - 1); 
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				dp2[i][j] = "";
		}
		cout << build(0, sz(s) - 1) << endl;
	}
}
