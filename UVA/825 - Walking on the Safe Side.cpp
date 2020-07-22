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
int n, w;
int const N = 1e3;
vector<vector<char>>arr;
bool valid(int i, int j){
	return i > 0 && j > 0 && i <= n&&j <= w&&arr[i][j] != 'X';
}
int sol(int i, int j){
	if (!valid(i, j))
		return 0;
	if (i == n && j == w)
		return 1;
	int ret = 0;
	ret += sol(i + 1, j);
	arr[i][j] = 'X';
	ret += sol(i, j + 1);
	arr[i][j] = '*';
	return ret;
}
int main(){
	K_K();
	int t;
	cin >> t;
	bool flag = 0;
	arr.resize(N, vector<char>(N));
	while (t--){
		cin >> n >> w;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= w; j++){
				arr[i][j] = '*';
			}
		}
		int x;
		string s;
		cin.ignore();
		for (int i = 0; i < n; i++){
			getline(cin, s);
			vector<int>v;
			stringstream r(s);
			while (r >> x){
				v.push_back(x);
			}
			for (int i = 1; i < sz(v); i++)
				arr[v[0]][v[i]] = 'X';
		}
		if (flag)cout << endl << endl;
		cout << sol(1, 1);
		flag = 1;
	}
	cout << endl;
}