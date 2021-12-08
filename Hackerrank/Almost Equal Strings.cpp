/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://www.hackerrank.com/contests/code-cpp-may-2015/challenges/almost-equal-strings/problem
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
const int N = 1e6 + 2;
ll fixMod(ll a, ll m){
	return (a + m) % m;
}
ll pushBack(ll h, ll x, ll p, ll ch){
	return (((h*x) % p) + ch) % p;
}
ll popFront(ll h, ll xp, ll p, ll ch){ // xp=XP[len-1]
	return fixMod(h - ((xp*ch) % p), p);
}
int n; vector<ll>XP(N, 1), pre;
ll get(ll l, ll r, ll p){
	if (!l)return pre[r];
	return popFront(pre[r], XP[r - l + 1], p, pre[l - 1]);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x = 128, p = 1e9 + 7;
	for (int i = 1; i < N; i++){
		XP[i] = (XP[i - 1] * x) % p;
	}
	string s; cin >> n >> s;
	ll h = 0; pre = vector<ll>(n);
	for (int i = 0; i < n; i++){
		h = pushBack(h, x, p, s[i]);
		pre[i] = h;
	}
	int q; cin >> q;
	while (q--){
		int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
		l1--; r1--; l2--; r2--;
		if ((r1 - l1) != (r2 - l2)){
			cout << "DIFFERENT\n"; continue;
		}
		ll fr = get(l1, r1, p), sc = get(l2, r2, p);
		if (fr == sc){
			cout << "SIMILAR\n"; continue;
		}
		int l = 0, r = r1 - l1, ans = -1;
		while (l <= r){
			int md = (l + r) >> 1;
			if (get(l1, l1 + md, p) == get(l2, l2 + md, p)){
				l = md + 1;
			}
			else
				r = md - 1;
		}
		l++;
		if (get(l1 + l, r1, p) == get(l2 + l, r2, p))
			cout << "SIMILAR\n";
		else
			cout << "DIFFERENT\n";
	}
}