/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/contest/447/problem/D
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
int const N = 1e6 + 2;
ll row[N], col[N];
int main(){
	K_K();
	int n, m, k, p; cin >> n >> m >> k >> p;
	vector<vector<int>>arr(n, vector<int>(m));
	priority_queue<int>tmp;
	for (int i = 0; i < n; i++){
		int sum = 0;
		for (int j = 0; j < m; j++){
			cin >> arr[i][j]; sum += arr[i][j];
		}
		tmp.push(sum);
	}
	ll cur = 0;
	for (int i = 1; i <= k; i++){
		int t = tmp.top(); tmp.pop(); 
		cur += t; row[i] = cur;
		t -= p*m; tmp.push(t);
	}
	while (sz(tmp))tmp.pop();

	for (int j = 0; j < m; j++){
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i][j];
		tmp.push(sum);
	}
	cur = 0;
	for (int i = 1; i <= k; i++){
		int t = tmp.top(); tmp.pop();
		cur += t; col[i] = cur;
		t -= p*n; tmp.push(t);
	}
	ll ans = -OO;
	for (ll i = 0; i <= k; i++){
		ans = max(ans, (row[i] + col[k - i] - i*(k - i)*p));
	}
	cout << ans;
}