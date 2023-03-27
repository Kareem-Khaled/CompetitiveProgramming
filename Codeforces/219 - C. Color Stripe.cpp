/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/contest/219/problem/C
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
const int N = 5e5 + 5;
int n, k, dp[N][28]; string s;
int solve(int idx, int pre){
    if(idx == n) return 0;
    int &ret = dp[idx][pre];
    if(~ret) return ret; ret = oo;
    for(int i = 0; i < min(k, 3); i++){
        int ch1 = oo, ch2 = oo;
        if(i != pre)
            ch1 = solve(idx + 1, i) + 1;
            
        if(pre != (s[idx] - 'A'))
            ch2 = solve(idx + 1, s[idx] - 'A');
            
        ret = min({ret, ch1, ch2});
    }
    return ret;
}

void build(int idx, int pre){
    if(idx == n) return;
    int ret = solve(idx, pre);
    for(int i = 0; i < min(k, 3); i++){
        int ch1 = oo, ch2 = oo;
        if(i != pre)
            ch1 = solve(idx + 1, i) + 1;
            
        if(pre != (s[idx] - 'A'))
            ch2 = solve(idx + 1, s[idx] - 'A');
            
        if(ret == ch1){
            cout << char(i + 'A');
            build(idx + 1, i);
            return;
        }
        else if(ret == ch2){
            cout << s[idx];
            build(idx + 1, s[idx] - 'A');
            return;
        }
        
        ret = min({ret, ch1, ch2});
    }
}

int main(){
	K_K(); 
	cin >> n >> k >> s; clr(dp, -1);
	cout << solve(0, 27) << endl;
	build(0, 27);
}