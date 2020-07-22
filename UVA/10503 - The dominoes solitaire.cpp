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
bool is_prime(int x){
	if (x < 2)return 0;
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0)
			return 0;
	}
	return 1;
}
int n, m;
vector<pair<int, int>>arr,p;
bool vis[20];
bool sol(int idx, int pre){
	if (idx == n){
		if (pre == p[1].first){
			return 1;
		}
		return 0;
	}
	bool ret = 0;
	for (int k = 0; k < m; k++){
		if (!vis[k] && (pre == arr[k].first || pre == arr[k].second)){
			vis[k] = 1;
			if (pre == arr[k].first)
				ret|=sol(idx + 1, arr[k].second);
			else
				ret|=sol(idx + 1, arr[k].first);
			vis[k] = 0;
		}
	}
	return ret;
}
int main(){
	K_K();
	p.resize(2);
	while (cin >> n&&n){
		cin >> m;
		arr.resize(m);
		for (int i = 0; i < 2; i++)cin >> p[i].first >> p[i].second;
		for (int i = 0; i < m; i++)cin >> arr[i].first >> arr[i].second;
		if (sol(0, p[0].second))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}