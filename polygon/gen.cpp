/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
#include <bits/stdc++.h>
#include "testlib.h"
#include <unordered_map>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define OO LLONG_MAX
int dx[] { -1, 0, 0, 1, 1, 1, -1, -1 };
int dy[] { 0, -1, 1, 0, 1, -1, 1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void K_K() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifdef Kemo
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
int to_int(char *ch) {
	int x = 0;
	while (*ch != '\0') {
		x = x * 10 + (*ch - '0');
		ch++;
	}
	return x;
}

double next(double l, double r) {
	return rnd.next(0, (int) 1e9) / 1e9 * (r - l) + l;
}

template<typename T>
vector<T> nextArray(int n, T l, T r) {
	vector<T> v(n);
	for (auto &it : v)
		it = next(l, r);
	return v;
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);
	int test_id = to_int(argv[1]); string regx, a, b, c;
	if (test_id <= 10)
        regx = "[a-z]{" + to_string(1)+','+ to_string(6)+'}';
	else if (test_id <= 30)
        regx = "[a-z]{" + to_string(3)+','+ to_string(6)+'}';
    else if (test_id <= 50)
        regx = "[a-z]{" + to_string(5)+','+ to_string(6)+'}';
    else 
        regx = "[a-z]{" + to_string(6)+','+ to_string(6)+'}';
    a = rnd.next(regx); b = rnd.next(regx); c = rnd.next(regx);
    cout << a << ' ' << b << ' '<< c << endl;
}