/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/contest/447/problem/C
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
#define oo 0x7FFFFFFF
#define OO 0x7FFFFFFFFFFFFFFFLL
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
int main(){
	K_K();
	int n; cin >> n;
	vector<int>arr(n + 2);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	vector<int>pre(n + 2), suf(n + 2);
	pre[1] = suf[n] = 1;
	for (int i = 1; i <= n; i++){
		if (arr[i] > arr[i - 1])
			pre[i] = pre[i - 1] + 1;
		else pre[i] = 1;
	}
	for (int i = n - 1; i > 0; i--){
		if (arr[i] < arr[i + 1])
			suf[i] = suf[i + 1] + 1;
		else suf[i] = 1;
	}
	int mx = max(pre[n], suf[1]);
	for (int i = 1; i <= n; i++){
		if (arr[i + 1] - arr[i - 1] > 1)
			mx = max(mx, pre[i - 1] + suf[i + 1] + 1);
		mx = max(mx, pre[i - 1] + 1);
		mx = max(mx, suf[i + 1] + 1);
	}
	cout << mx;
}