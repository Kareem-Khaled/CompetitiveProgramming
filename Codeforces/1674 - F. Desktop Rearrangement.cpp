/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/contest/1674/problem/F
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define endl "\n"
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define rt(s) return cout<<s,0
#define sz(s)	(int)(s.size())
#define OO 0x3f3f3f3f3f3f3f3fLL
#define oo 0x3f3f3f3f
using namespace std;
typedef long long ll;
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void K_K() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int n, m, q; 
vector<int>bit;
void add(int idx, int num){
	for (int i = idx; i <= n * m; i += (i & -i))
		bit[i] += num;
}
int prefixSum(int x){
	int ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += bit[i];
	return ret;
}
int rangeSum(int l, int r){
	return prefixSum(r) - prefixSum(l - 1);
}
int main(){
	K_K();
    cin >> n >> m >> q;
    vector<string>dec(n); int cnt = 0;
    bit = vector<int>(n * m + 1);
    for(int i = 0; i < n; i++){
        cin >> dec[i];
        for(int j = 0; j < m; j++){
            if(dec[i][j] != '*') continue;
            int idx = (j * n) + i + 1;
            add(idx, 1); cnt++;
        }
    }
    while(q--){
        int x, y; cin >> x >> y;
        int idx = ((y - 1) * n) + x;
        x--; y--;
        if(dec[x][y] == '*') {
            add(idx, -1), cnt--;
            dec[x][y] = '.';
        }
        else {
            add(idx, 1), cnt++;
            dec[x][y] = '*';
        }
        cout << cnt - rangeSum(1, cnt) << endl;
    }
}