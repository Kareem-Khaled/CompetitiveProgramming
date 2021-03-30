/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// problem Link:https://www.hackerrank.com/challenges/maximum-palindromes/problem
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl "\n"
#define Ceil(x,y) ((x+y-1)/y)
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
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
const int M = 1e9 + 7;
ll power(ll x, ll k){
	ll ret = 1;
	while (k){
		if (k & 1) ret = (ret*x) % M;
		k >>= 1; x = (x*x) % M;
	}
	return ret;
}
vector<ll>fact, mmi;
vector<vector<int>>frq;
void initialize(string s) {
	fact = mmi = vector<ll>(s.size() + 1);
	fact[0] = mmi[0] = 1;
	for (int i = 1; i <= s.size(); i++){
		fact[i] = (fact[i - 1] * i) % M;
		mmi[i] = power(fact[i], M - 2);
	}
	frq = vector<vector<int>>(26, vector<int>(s.size() + 1));
	for (int i = 1; i <= s.size(); i++){
		frq[s[i - 1] - 'a'][i]++;
	}
	for (int i = 0; i < 26; i++){
		for (int j = 1; j <= s.size(); j++)
			frq[i][j] += frq[i][j - 1];
	}
}

int answerQuery(int l, int r) {
	int even = 0, odd = 0; ll ans = 1;
	for (int i = 0; i<26; i++){
		int value = frq[i][r] - frq[i][l - 1];
		odd += (value & 1);
		even += value / 2;
		ans = (ans*mmi[value / 2]) % M;
	}
	ans = (ans*fact[even]) % M;
	if (odd != 0)
		ans = (ans*odd) % M;
	return ans;
}
int main(){
	K_K();
	string s; cin >> s;
	initialize(s);
	int n; cin >> n;
	while (n--){
		int l, r; cin >> l >> r;
		cout << answerQuery(l, r) << endl;
	}
}
