/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://www.spoj.com/problems/TOE1/
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
bool is_win(string s){
	bool rows =
		(s[0] != '.'&&s[0] == s[1] && s[1] == s[2]) ||
		(s[3] != '.'&&s[3] == s[4] && s[4] == s[5]) ||
		(s[6] != '.'&&s[6] == s[7] && s[7] == s[8]);
	bool col =
		(s[0] != '.'&&s[0] == s[3] && s[3] == s[6]) ||
		(s[1] != '.'&&s[1] == s[4] && s[4] == s[7]) ||
		(s[2] != '.'&&s[2] == s[5] && s[5] == s[8]);
	bool dig =
		(s[0] != '.'&&s[0] == s[4] && s[4] == s[8]) ||
		(s[2] != '.'&&s[2] == s[4] && s[4] == s[6]);
	return rows || col || dig;
}
string bfs(string &st, string &s){
	queue<pair<string, bool>>qu;
	qu.push({ st, 1 });
	while (sz(qu)){
		string cur = qu.front().first;
		bool next = qu.front().second;
		qu.pop();
		if (cur == s)
			return "yes";
		if (is_win(cur))continue;
		for (int i = 0; i < 9; i++){
			if (cur[i] == '.'){
				cur[i] = (next ? 'X' : 'O');
				if (cur[i] == s[i])
					qu.push({ cur, 1 ^ next });
				cur[i] = '.';
			}
		}
	}
	return "no";
}
int main(){
	K_K();
	int t; cin >> t;
	while (t--){
		string s = "", st(9, '.'), ans = "no";
		for (int i = 0; i < 3; i++){
			string x; cin >> x; s += x;
		}
		cout << bfs(st, s) << endl;
	}
}