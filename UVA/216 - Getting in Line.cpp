/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=152
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
int n; vector<pair<int, int>>arr;
double calc(pair<int, int>p1, pair<int, int>p2){
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2)) + 16;
}
double dp[(1 << 13)][13];
double solve(int mask, int lst){
	if (mask == (1 << n) - 1)return 0;
	double &ret = dp[mask][lst];
	if (ret != -OO)return ret; ret = OO;
	for (int i = 0; i < n; i++){
		if (((mask >> i) & 1) == 0)
			ret = min(ret, solve((mask | (1 << i)), i) + calc(arr[lst], arr[i]));
	}
	return ret;
}
void build(int mask, int lst){
	if (mask == (1 << n) - 1)return;
	double ret = solve(mask, lst);
	for (int i = 0; i < n; i++){
		if (((mask >> i) & 1))continue;
		double cur = solve((mask | (1 << i)), i) + calc(arr[lst], arr[i]);
		if (ret == cur){
			cout << "Cable requirement to connect (" << arr[lst].first << ',' << arr[lst].second << ") to (" << arr[i].first << ',' << arr[i].second << ") is " << calc(arr[lst], arr[i]) << " feet.\n";
			build((mask | (1 << i)), i);
		}
	}
}
void clear(){
	for (int i = 0; i < (1 << 13); i++){
		for (int j = 0; j < 13; j++)
			dp[i][j] = -OO;
	}
}
int main(){
	K_K();
	int tc = 1;
	while (cin >> n, n){
		arr = vector<pair<int, int>>(n);
		for (auto &it : arr)cin >> it.first >> it.second;
		int st = -1; double mn = OO;
		for (int i = 0; i < n; i++){
			clear(); double cur = solve((1 << i), i);
			if (mn > cur){
				mn = cur; st = i;
			}
		}
		cout << "**********************************************************\nNetwork #" << tc++ << endl;
		cout << fixed << setprecision(2); clear(); 
		double ans = solve((1 << st), st); build((1 << st), st);
		cout << "Number of feet of cable required is " << ans << ".\n";
	}
}