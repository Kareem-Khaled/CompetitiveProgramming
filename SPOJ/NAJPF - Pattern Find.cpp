/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://www.spoj.com/problems/NAJPF/
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
	int x = 128, p = 1e9 + 7;
	vector<ll>XP(N, 1);
	for (int i = 1; i < N; i++)
		XP[i] = (XP[i - 1] * x) % p;
	int t; cin >> t; bool sp = 0;
	while (t--){
		string a, b; cin >> a >> b; ll h = 0, org = 0;
		for (int i = 0; i < sz(b); i++){
			org = pushBack(org, x, p, b[i]);
		}
		for (int i = 0; i < min(sz(a), sz(b)); i++){
			h = pushBack(h, x, p, a[i]);
		}
		vector<int>ans;
		if (h == org)
			ans.push_back(1);
		for (int i = sz(b); i < sz(a); i++){
			h = popFront(h, XP[sz(b) - 1], p, a[i - sz(b)]);
			h = pushBack(h, x, p, a[i]);
			if (h == org)
				ans.push_back(i - sz(b) + 2);
		}
		if (sp)cout << endl; sp = 1;
		if (sz(ans)){
			cout << sz(ans) << endl;
			for (auto it : ans)cout << it << ' ';
			cout << endl;
		}
		else cout << "Not Found\n";
	}
}