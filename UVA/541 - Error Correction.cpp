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
//x = xDegrees*3.14159265 / 180;
//ef1tn=(( (n / 2)*( (n / 2) + 1) / 2) * 2);
//of1tn=(n * (n + 1) / 2 - 2 * ((n / 2) * (n / 2 + 1) / 2));
int dx[] { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] { 0, 0, 1, -1, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main(){
	K_K();
	int n;
	while (cin >> n&&n){
		vector<vector<int>>arr(n, vector<int>(n));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		}
		pair<int, int>ans;
		int cnt = 0;
		for (int i = 0; i < n; i++){
			int sum = 0;
			for (int j = 0; j < n; j++){
				sum += arr[i][j];
			}
			if (sum & 1){
				ans.first = i + 1;
				cnt++;
			}
		}
		if (cnt>1){
			cout << "Corrupt\n";
			continue;
		}
		cnt = 0;
		for (int i = 0; i < n; i++){
			int sum = 0;
			for (int j = 0; j < n; j++){
				sum += arr[j][i];
			}
			if (sum & 1){
				ans.second = i + 1;
				cnt++;
			}
		}
		if (cnt>1){
			cout << "Corrupt\n";
			continue;
		}
		else if (!cnt)
			cout << "OK\n";
		else
			cout << "Change bit (" << ans.first << ',' << ans.second << ")\n";
	}
}