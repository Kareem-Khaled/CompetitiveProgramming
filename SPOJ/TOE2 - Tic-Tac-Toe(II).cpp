/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link:https://www.spoj.com/problems/TOE2/
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
int dx[] { 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[] { 0, 1, -1, 0, 1, -1, 1, -1 };
void K_K(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
bool win(string &s){
	bool ok = !count(all(s), '.');
	for (int i = 0; i < 9; i += 3){
		ok |= (s[i] != '.' && s[i] == s[i + 1] && s[i + 1] == s[i + 2]);
	}
	for (int i = 0; i < 3; i++){
		ok |= (s[i] != '.' && s[i] == s[i + 3] && s[i + 3] == s[i + 6]);
	}
	ok |= (s[0] != '.' && s[0] == s[4] && s[4] == s[8]);
	ok |= (s[2] != '.' && s[2] == s[4] && s[4] == s[6]);
	return ok;
}
set<string>valid;
void bfs(){
	queue<pair<string, char>>qu;
	qu.push({ string(9, '.'), 'X' });
	while (sz(qu)){
		pair<string, char>p = qu.front(); qu.pop();
		if (valid.find(p.first) != valid.end())continue;
		valid.insert(p.first);
		if (win(p.first))continue;
		for (int i = 0; i < 9; i++){
			if (p.first[i] == '.'){
				p.first[i] = p.second;
				qu.push({ p.first, p.second == 'X' ? 'O' : 'X' });
				p.first[i] = '.';
			}
		}
	}
}
int main() {
	K_K();
	string e; bfs();
	while (cin >> e && e != "end"){
		cout << (valid.find(e) != valid.end() && win(e) ? "valid" : "invalid") << endl;
	}
}