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
ll n, T;
vector<pair<ll, ll>>arr;
ll sol(int idx, ll V){
	if (idx == n){
		if (V > 0)
			return OO;
		return 0;
	}
	ll ch1 = sol(idx + 1, V);
	ll ch2 = sol(idx + 1, V - (arr[idx].first*T)) + arr[idx].second;
	return min(ch1, ch2);
}
int main(){
	K_K();
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)cin >> arr[i].first >> arr[i].second;
	ll t, V, c = 1, ans;
	cin >> t;
	while (t--){
		cin >> V >> T;
		ans = sol(0, V);
		cout << "Case " << c++ << ": ";
		if (ans != OO)cout << ans << endl;
		else cout << "IMPOSSIBLE\n";
	}
}
 
Close
Sphere Research Labs. Ideone is powered by Sphere Engine™
home api faq credits desktop mobile
terms of service privacy policy gdpr info

Feedback & Bugs
popular languages:

bash pascal c perl c# php c++ python c++14 python3 haskell ruby java sqlite objective-c swift vb.net
list of all supported programming languages

 Not using Hotjar yet?
Select an element on the page.
