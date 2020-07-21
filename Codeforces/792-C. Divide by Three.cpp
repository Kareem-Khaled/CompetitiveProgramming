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
const int oo = 0x3f3f3f3f, Mod = 1e9 + 7;
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
string s;
int const N = 1e5 + 5;
int dp[N][3][2];
int sol(int idx, int rem, bool take){
	if (idx == sz(s)){
		if (!take || rem)
			return -oo;
		return 0;
	}
	int &ret = dp[idx][rem][take];
	if (~ret)
		return ret;
	int ch1 = sol(idx + 1, rem, take), ch2 = -oo;
	int x = (s[idx] - '0');
	if (take || x)
		ch2 = sol(idx + 1, (rem + x) % 3, 1) + 1;
	return ret = max(ch1, ch2);
}
void build(int idx, int rem, bool take) {
	if (idx == sz(s))
		return;
	int ret = sol(idx, rem, take);
	int ch1 = sol(idx + 1, rem, take), ch2 = -oo;
	int x = (s[idx] - '0');
	if (take || x)
		ch2 = sol(idx + 1, (rem + x) % 3, 1) + 1;
	if (ret == ch1){
		build(idx + 1, rem, take);
	}
	else if (ret == ch2){
		cout << s[idx];
		build(idx + 1, (rem + x) % 3, 1);
	}
}
int main(){
	K_K();
	cin >> s;
	clr(dp, -1);
	if (sol(0, 0, 0) < 0){
		if (s.find('0') != s.npos)
			rt(0);
		rt(-1);
	}
	build(0, 0, 0);
}