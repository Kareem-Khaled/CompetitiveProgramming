/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link : https://www.spoj.com/problems/TRYCOMP/
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
class Trie{
private:
	struct node{
		node *child[26];
		int cur, mx;
	};
	node* root;
public:
	Trie(){
		root = create();
	}
	node* getRoot(){
		return root;
	}
	node* create(){
		node* nd = new node();
		for (int i = 0; i < 26; i++)
			nd->child[i] = NULL;
		nd->cur = nd->mx = 0;
		return nd;
	}
	void add(string s){
		node *nd = root;
		for (int i = 0; i < sz(s); i++){
			if (nd->child[s[i] - 'a'] == NULL)
				nd->child[s[i] - 'a'] = create();
			nd = nd->child[s[i] - 'a'];
		}
		nd->cur++;
	}
	void dfs(node *nd){
		nd->mx = nd->cur;
		for (int i = 0; i < 26; i++){
			if (nd->child[i] != NULL){
				dfs(nd->child[i]);
				nd->mx = max(nd->mx, nd->child[i]->mx);
			}
		}
	}
	pair<string, int>ans(string s){
		node *nd = root;
		for (int i = 0; i < sz(s); i++){
			if (nd->child[s[i] - 'a'] == NULL)
				return{ "", -1 };
			nd = nd->child[s[i] - 'a'];
		}
		int mx = nd->mx; string ret = s;
		while (nd->mx != nd->cur){
			for (int i = 0; i < 26; i++){
				if (nd->child[i] != NULL && nd->child[i]->mx == mx){
					ret += (char)(i + 'a');
					nd = nd->child[i];
					break;
				}
			}
		}
		return{ ret, mx };
	}
};

int main(){
	K_K();
	Trie trie = Trie();
	int n; cin >> n;
	while (n--){
		string s; cin >> s; trie.add(s);
	}
	cin >> n; trie.dfs(trie.getRoot());
	while (n--){
		string s; cin >> s; 
		auto ans = trie.ans(s);
		if (~ans.second)cout << ans.first << ' ' << ans.second << endl;
		else cout << "-1\n";
	}
}