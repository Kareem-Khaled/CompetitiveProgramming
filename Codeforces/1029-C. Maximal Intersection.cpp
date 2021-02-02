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
#define allr(v) v.rbegin(),v.rend()
#define rt(s) return cout<<s,0
#define sz(s)	(int)(s.size())
#define OO 0x3f3f3f3f3f3f3f3fLL
const int oo = 1e5, mod = 1e9 + 7;
double EBS = 1e-6;
using namespace std;
typedef long long ll;
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
const int INF = int(1e9);
struct segments{
	int l, r;
};
int main(){
	K_K();
	int n; cin >> n;
	vector<int>preL(n + 1), preR(n + 1), sufL(n + 1), sufR(n + 1);
	vector<segments>arr(n);
	preR[0] = sufR[n] = INF;
	for (auto &it : arr)cin >> it.l >> it.r;
	for (int i = 0; i < n; i++){
		preL[i + 1] = max(preL[i], arr[i].l);
		preR[i + 1] = min(preR[i], arr[i].r);
		sufL[n - i - 1] = max(sufL[n - i], arr[n - i - 1].l);
		sufR[n - i - 1] = min(sufR[n - i], arr[n - i - 1].r);
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		ans = max(ans, min(preR[i], sufR[i + 1]) - max(preL[i], sufL[i + 1]));
	}
	cout << ans;
}