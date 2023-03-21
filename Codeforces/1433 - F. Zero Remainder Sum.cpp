/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/contest/1433/problem/F
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
int n, m, k; 
const int N = 77;
int dp[N][N][N][N];
vector<vector<int>>arr;
int solve(int i, int j, int cur, int rem){
    if(i == n){
        return (!rem ? 0 : -oo);
    }
    int &ret = dp[i][j][cur][rem];
     if(~ret) return ret; ret = -oo;
    int ch1 = -oo, ch2 = -oo, ch3 = -oo;
    if(j < m){
        if(cur) ch1 = solve(i, j + 1, cur - 1, (rem + arr[i][j]) % k) + arr[i][j];
        ch2 = solve(i, j + 1, cur, rem);        
    }
    else{
        ch3 = solve(i + 1, 0, m / 2, rem);
    }
    return ret = max({ret, ch1, ch2, ch3});
}


void build(int i, int j, int cur, int rem){
    if(i == n) return;
    int ret = solve(i, j, cur, rem);
    int ch1 = -oo, ch2 = -oo, ch3 = -oo;
    if(j < m){
        if(cur) ch1 = solve(i, j + 1, cur - 1, (rem + arr[i][j]) % k) + arr[i][j];
        ch2 = solve(i, j + 1, cur, rem);  
    }
    else{
        ch3 = solve(i + 1, 0, m / 2, rem);
    }
    if(ret == ch1){
        cout << arr[i][j] << ' ';
        build(i, j + 1, cur - 1, (rem + arr[i][j]) % k);
    }
    else if(ret == ch2){
        build(i, j + 1, cur, rem);  
    }
    else{
       build(i + 1, 0, m / 2, rem);
    }
}

int main(){
	K_K(); 
	cin >> n >> m >> k; clr(dp, -1);
	arr = vector<vector<int>>(n, vector<int>(m));
	for(auto &it : arr){
    	for(auto &itt : it)
    	    cin >> itt;
	}
	cout << solve(0, 0, m / 2, 0) << endl;
	build(0, 0, m / 2, 0);
}