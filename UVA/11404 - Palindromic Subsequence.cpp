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
const int N = 1e3 + 5;
string s;
int dp[N][N];
string dp1[N][N];
int sol(int l, int r){
	if (l >= r)
		return (l == r ? 1 : 0);

	int &ret = dp[l][r];
	if (~ret)
		return ret;
	ret = 0;
	int ch1 = 0, ch2 = 0, ch3 = 0;
	if (s[l] == s[r])
		ch1 = sol(l + 1, r - 1) + 2;
	else{
		ch2 = sol(l + 1, r);
		ch3 = sol(l, r - 1);
	}
	return ret = max({ ch1, ch2, ch3 });
}
string build(int l, int r){
	if (l >= r)
		return (l == r ? string(1, s[l]) : string());

	string &ret = dp1[l][r];
	if (sz(ret))
		return ret;

	int rt = sol(l, r);
	int ch1 = 0, ch2 = 0, ch3 = 0;
	if (s[l] == s[r]){
		ch1 = sol(l + 1, r - 1) + 2;
	}
	else{
		ch2 = sol(l + 1, r);
		ch3 = sol(l, r - 1);
	}
	if (rt == ch1)
		return ret = s[l] + build(l + 1, r - 1) + s[r];

	if (ch2 == ch3)
		return ret = min(build(l + 1, r), build(l, r - 1));

	if (ch2 > ch3)
		return ret = build(l + 1, r);

	return ret = build(l, r - 1);
}
int main(){
	K_K();
	while (cin >> s){
		clr(dp, -1);
		cout << build(0, sz(s) - 1) << endl;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++)
				dp1[i][j].clear();
		}
	}
}