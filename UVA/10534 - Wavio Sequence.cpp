/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1475
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
int n; vector<int>arr, dpL, dpR;
void L(){
	vector<int> tail(n, 0);
	int length = 1; tail[0] = arr[0]; dpL[0] = 1;
	for (int i = 1; i < n; i++) {
		auto it = lower_bound(tail.begin(), tail.begin() + length, arr[i]);
		if (it == tail.begin() + length)
			tail[length++] = arr[i];
		else
			*it = arr[i];
		dpL[i] = length;
	}
}
void R(){
	vector<int> tail(n, 0);
	int length = 1; tail[0] = arr[0]; dpR[0] = 1;
	for (int i = 1; i < n; i++) {
		auto it = lower_bound(tail.begin(), tail.begin() + length, arr[i]);
		if (it == tail.begin() + length)
			tail[length++] = arr[i];
		else
			*it = arr[i];
		dpR[i] = length;
	}
}

int main(){
	K_K();
	while (cin >> n) {
		arr = dpL = dpR = vector<int>(n, 0);
		for (int i = 0; i < n; i++) cin >> arr[i];
		L(); reverse(all(arr)); R(); reverse(all(dpR));
		int ans = 1;
		for (int i = 0; i + 1 < n; i++){
			ans = max(ans, min(dpL[i], dpR[i]) * 2 - 1);
		}
		cout << ans << endl;
	}
}