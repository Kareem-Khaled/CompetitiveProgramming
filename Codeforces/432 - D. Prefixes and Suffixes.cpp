/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://codeforces.com/problemset/problem/432/D
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
vector<int>prfx, z;
void buildPrifx(string s){
	prfx = vector<int>(sz(s), 0);
	int border = 0;
	for (int i = 1; i < sz(s); i++){
		while (border> 0 && s[i] != s[border])
			border = prfx[border - 1];
		if (s[i] == s[border]) border++;
		prfx[i] = border;
	}
}
vector<pair<int, int>>ans;
void buildZ(string s){
	z = vector<int>(sz(s), 0);
	priority_queue<int>pq;
	int l = 0, r = 0, cnt = 0;
	for (int i = 1; i < sz(s); i++){
		int k = i - l;
		if (i >= r || i + z[k] >= r){
			l = i; r = max(r, i);
			while (r < sz(s) && s[r - l] == s[r])r++;
			z[i] = r - l;
		}
		else
			z[i] = z[k];
		if (z[i])pq.push(z[i]);
		if (z[i] + i == sz(s)){
			while (sz(pq) && pq.top() >= z[i]){
				cnt++; pq.pop();
			}
			ans.push_back({ z[i], cnt + 1 });
		}
	}
}
int main(){
	K_K();
	string s; cin >> s; buildZ(s);
	ans.push_back({ sz(s), 1 }); sort(all(ans));
	cout << sz(ans) << endl;
	for (int i = 0; i < sz(ans); i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
}