/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it 💗
*/
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
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
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
ll gcd(ll a, ll b) {
	return b == 0 ? abs(a) : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
int v[10][10];
const int mx = 8;
int ithrow[mx][mx];
bool col[mx], rdig[2 * mx + 1], ldig[2 * mx + 1];
vector<pair<int, int>>vp;
void solve(int r = 0){
	if (r == 8){
		for (int i = 0; i < mx; i++){
			for (int j = 0; j < mx; j++){
				if (ithrow[i][j])
					vp.push_back({ i, j });
			}
		}
		return;
	}
	for (int c = 0; c < 8; c++){
		if (!col[c] && !rdig[c + r] && !ldig[mx + c - r]){
			ithrow[r][c] = 1;
			col[c] = 1; rdig[c + r] = 1; ldig[mx + c - r] = 1;
			solve(r + 1);
			col[c] = 0; rdig[c + r] = 0; ldig[mx + c - r] = 0;
			ithrow[r][c] = 0;
		}
	}
}
 
int main(){
	K_K();
	int t;
	cin >> t;
	solve();
	while (t--){
		pair<int, int>p;
		cin >> p.first >> p.second;
		p.first--;p.second--;
		bool flag = 0;
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";
		int c = 1;
		set<vector<ll>>sv;
		vector<ll>vv;
		for (int i = 0; i < sz(vp); i++){
			if (i % 8 == 0){
				if (flag){
					sv.insert(vv);
				}
				flag = 0;
				vv.clear();
			}
			if (p.second == vp[i].first&&p.first == vp[i].second)
				flag = 1;
			vv.push_back(vp[i].second + 1);
		}
		if (flag)
			sv.insert(vv);
 
		for (auto it : sv){
			cout << setw(2) << c++ << setw(7) << it[0];
			for (int i = 1; i < sz(it); i++)
				cout << " " << it[i];
			cout << endl;
		}
		if (t)
			cout << endl;
	}
}
