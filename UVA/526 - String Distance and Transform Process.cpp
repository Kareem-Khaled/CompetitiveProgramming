/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=467
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
const int N = 1e2;
string a, b, s; int dp[N][N];
int solve(int i, int j){
	if (i == sz(a)) return sz(b) - j;
	if (j == sz(b)) return sz(a) - i;
	int &ret = dp[i][j];
	if (~ret)return ret; ret = oo;
	if (a[i] == b[j])
		ret = solve(i + 1, j + 1);
	else                 
		ret = min({ ret, solve(i, j + 1) + 1, solve(i + 1, j) + 1, solve(i + 1, j + 1) + 1 });
	return ret;
}
int shift;
vector<string>ans;
void build(int i, int j){
	if (i == sz(a)) {
		for (int k = 0; k < sz(b) - j; k++){
			s = "Insert " + to_string(i + 1 + k + shift) + "," + b[j + k];
			ans.push_back(s);
		}
		shift += sz(b) - j; return;
	}
	if (j == sz(b)){
		for (int k = 0; k < sz(a) - i; k++){
			s = "Delete " + to_string(i + 1 + k + shift--);
			ans.push_back(s);
		}
		return;
	}
	if (a[i] == b[j]){
		build(i + 1, j + 1);
	}
	else{
		int ret = solve(i, j);
		if (ret == solve(i, j + 1) + 1){
			s = "Insert " + to_string(i + 1 + shift++) + "," + b[j];
			ans.push_back(s); build(i, j + 1);
		}
		else if (ret == solve(i + 1, j) + 1){
			s = "Delete " + to_string(i + 1 + shift--);
			ans.push_back(s); build(i + 1, j);
		}
		else{
			s = "Replace " + to_string(i + 1 + shift) + "," + b[j];
			ans.push_back(s); build(i + 1, j + 1);
		}
	}
}
int main(){
	K_K(); bool flag = 0;
	while (getline(cin,a)){
		getline(cin, b);
		if (flag) cout << endl; flag = 1;
		clr(dp, -1); shift = 0; ans.clear();
		cout << solve(0, 0) << endl; build(0, 0);
		for (int i = 0; i < sz(ans); i++){
			cout << i + 1 << ' ' << ans[i] << endl;
		}
	}
}