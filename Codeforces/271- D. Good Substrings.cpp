/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://codeforces.com/problemset/problem/271/D
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
ll MOD(ll x, ll y){
	return ((x % y) + y) % y;
}
ll pushBack(ll h, ll x, ll p, char ch){
	return (((h*x) % p) + ch) % p;
}
ll popFront(ll h, ll xp, ll p, char ch){ // xp = XP[len-1]
	return MOD(h - ((xp*ch) % p), p);
}
int main(){
	K_K();
	int x = 128, p = 1e9 + 7, p2 = 1e9 + 9;
	string s; cin >> s; int frq[26];
	for (int i = 0; i < 26; i++){
		char ch; cin >> ch;
		frq[i] = ch - '0';
		frq[i] = 1 - frq[i];
	}
	int n; cin >> n;
	unordered_set<ll>st;
	for (int i = 0; i < sz(s); i++){
		ll h = 0, h2 = 0; int cnt = 0;
		for (int j = i; j < sz(s); j++){
			h = pushBack(h, x, p, s[j]);
			h2 = pushBack(h2, x, p2, s[j]);
			cnt += frq[s[j] - 'a'];
			if (cnt <= n)
				st.insert(h*p2 + h2);
		}
	}
	cout << sz(st);
}