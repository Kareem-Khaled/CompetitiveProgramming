/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
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
int n, m, x, y;
vector<string>arr;
struct jail{
	int x, y, d, cnt;
	bool operator <(const jail& j)const {
		if (x == j.x){
			if (y == j.y)
				return d > j.d;
			return y < j.y;
		}
		return x < j.x;
	}
};
map<jail, bool>vis;
bool inside(int x, int y){
	return (x >= 0 && y >= 0 && x < n && y < m);
}
int bfs(){
	queue<jail>qu; qu.push({ x, y, 0, 0 }); vis[{x, y, 0, 0}] = 0;
	while (sz(qu)){
		jail cur = qu.front(); qu.pop();
		if (!inside(cur.x, cur.y))return cur.cnt;
		for (int i = 0; i < 4; i++){
			int x = cur.x + dx[i], y = cur.y + dy[i], d = cur.d, cnt = cur.cnt;
			if (inside(x, y)){
				if (arr[x][y] == 'W' || (arr[x][y] == 'D' && !d))continue;
				if (arr[x][y] == 'O')d = 1; if (arr[x][y] == 'C')d = 0;
			}
			if (vis.find({ x, y, d, cnt }) == vis.end()){
				qu.push({ x, y, d, cnt + 1 });
				vis[{ x, y, d, cnt + 1 }] = 1;
			}
		}
	}
	return -1;
}
int main(){
	K_K();
	while (cin >> n >> m && ~n && ~m){
		arr = vector<string>(n);
		for (int i = 0; i < n; i++){
			cin >> arr[i];
			for (int j = 0; j < m; j++){
				if (arr[i][j] == 'H')
					x = i, y = j;
			}
		}
		cout << bfs() << endl; vis.clear();
	}
}