/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// problem Link : https://codeforces.com/contest/346/problem/B
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
const int N = 1e2 + 2;
vector<int>prfx(N);
string a, b, c;
int getbr(int br, char ch){
	while (br > 0 && ch != c[br])
		br = prfx[br - 1];
	br += (ch == c[br]);
	return br;
}
int dp[N][N][N];
int solve(int i, int j, int br){
	if (br == sz(c))return -oo; // found virus
	if (i == sz(a) || j == sz(b))return 0;
	int &ret = dp[i][j][br];
	if (~ret)return ret; ret = 0;
	if (a[i] == b[j])ret = solve(i + 1, j + 1, getbr(br, a[i])) + 1;
	return ret = max({ ret, solve(i, j + 1, br), solve(i + 1, j, br) });
}
void build(int i, int j, int br){
	if (br == sz(c) || i == sz(a) || j == sz(b))return;
	int ret = solve(i, j, br);
	if (a[i] == b[j] && ret == solve(i + 1, j + 1, getbr(br, a[i])) + 1){
		cout << a[i];
		build(i + 1, j + 1, getbr(br, a[i]));
	}
	else if (ret == solve(i, j + 1, br))
		build(i, j + 1, br);
	else
		build(i + 1, j, br);
}
int main(){
	K_K();
	cin >> a >> b >> c; clr(dp, -1);
	for (int i = 1; i < sz(c); i++)
		prfx[i] = getbr(prfx[i - 1], c[i]);
	if (!solve(0, 0, 0))rt(0);
	build(0, 0, 0);
}