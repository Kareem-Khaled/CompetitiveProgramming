/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/contest/1029/problem/D
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define rt(s) return cout<<s,0
#define sz(s)	(int)(s.size())
#define oo 0x7FFFFFFF
#define OO 0x7FFFFFFFFFFFFFFFLL
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
int numOfDig(int x){
	return floor(log10(x)) + 1;
}
ll power(ll x, ll k,int mod){
	ll ret = 1;
	while (k){
		if (k & 1) ret = (ret*x) % mod;
		k >>= 1; x = (x*x) % mod;
	}
	return ret;
}
int main(){
	K_K();
	int n, k; cin >> n >> k;
	vector<int>arr(n); map<int, map<int, int>>mp;
	for (auto &it : arr){
		cin >> it; mp[numOfDig(it)][it%k]++;
	}
	ll ans = 0;
	for (auto it : arr){
		mp[numOfDig(it)][it%k]--;
		for (int j = 1; j < 11; j++){
			int tmp = (power(10, j, k)*(it%k)) % k;
			tmp = k - tmp; tmp %= k;
			if (mp[j].find(tmp) != mp[j].end())
				ans += mp[j][tmp];
		}
		mp[numOfDig(it)][it%k]++;
	}
	cout << ans;
}