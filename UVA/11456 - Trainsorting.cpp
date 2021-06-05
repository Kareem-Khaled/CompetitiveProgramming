/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2451
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
int dx[] { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] { 1, 0, -1, 0, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
const int N = 2e3 + 2;
int n, dpL[N], dpR[N], arr[N];
int LIS(int idx){
	if (idx == n)return 0;
	int &ret = dpL[idx];
	if (~ret)return ret; ret = 1;
	for (int i = idx + 1; i < n; i++){
		if (arr[i] > arr[idx])
			ret = max(ret, LIS(i) + 1);
	}
	return ret;
}
int LDS(int idx){
	if (idx == n)return 0;
	int &ret = dpR[idx];
	if (~ret)return ret; ret = 1;
	for (int i = idx + 1; i < n; i++){
		if (arr[i] < arr[idx])
			ret = max(ret, LDS(i) + 1);
	}
	return ret;
}
int main(){
	K_K();
	int t; cin >> t;
	while (t--){
		clr(dpL, -1); clr(dpR, -1); cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, LIS(i) + LDS(i) - 1);
		cout << ans << endl;
	}
}