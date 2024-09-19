/*
██╗  ██╗ █████╗ ██████╗ ███████╗███████╗███╗   ███╗        ██╗  ██╗██╗  ██╗ █████╗ ██╗     ███████╗██████╗
██║ ██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗ ████║        ██║ ██╔╝██║  ██║██╔══██╗██║     ██╔════╝██╔══██╗
█████╔╝ ███████║██████╔╝█████╗  █████╗  ██╔████╔██║        █████╔╝ ███████║███████║██║     █████╗  ██║  ██║
██╔═██╗ ██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██║╚██╔╝██║        ██╔═██╗ ██╔══██║██╔══██║██║     ██╔══╝  ██║  ██║
██║  ██╗██║  ██║██║  ██║███████╗███████╗██║ ╚═╝ ██║███████╗██║  ██╗██║  ██║██║  ██║███████╗███████╗██████╔╝
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝╚═════╝
Believe in yourself ,( try and try and then try ), You can do it
*/
// Problem Link: https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/A
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define endl "\n"
#define clr(arr, x) memset(arr, x, sizeof arr)
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
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
    //freopen("out.txt", "w", stdout);
#endif  !ONLINEJUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
struct node {
    ll val, sum, prfx, sufx, lazy;
    bool is_lazy;

    node() : val(0), sum(0), prfx(0), sufx(0), lazy(0), is_lazy(0) {}

    void change(ll v, int lx, int rx) {
        sum = (rx - lx) * v;
        prfx = max(sum, 0LL);
        sufx = max(sum, 0LL);
        val = max(sum, 0LL);
        lazy = v;
        is_lazy = 1;
    }
};
struct segTree {
    int size;
    vector<node>seg;
    segTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        seg = vector<node>(size * 2, node());
    }

    node merge(node& a, node& b) {
        node ret;
        ret.sum = a.sum + b.sum;
        ret.prfx = max(a.prfx, a.sum + b.prfx);
        ret.sufx = max(b.sufx, b.sum + a.sufx);
        ret.val = max({ a.val, b.val, a.sufx + b.prfx });
        return ret;
    }

    void propagate(int idx, int lx, int rx) {
        if (rx - lx == 1 || !seg[idx].is_lazy) return;

        int m = (lx + rx) >> 1;
        seg[idx * 2 + 1].change(seg[idx].lazy, lx, m);
        seg[idx * 2 + 2].change(seg[idx].lazy, m, rx);

        seg[idx].lazy = 0;
        seg[idx].is_lazy = 0;
    }

    void set(int l, int r, int val, int idx, int lx, int rx) {
        propagate(idx, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            seg[idx].change(val, lx, rx);
            return;
        }
        int m = (lx + rx) >> 1;
        set(l, r, val, idx * 2 + 1, lx, m);
        set(l, r, val, idx * 2 + 2, m, rx);

        seg[idx] = merge(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    void set(int l, int r, int val) {
        set(l, r, val, 0, 0, size);
    }

    node get(int l, int r, int idx, int lx, int rx) {
        propagate(idx, lx, rx);
        if (lx >= r || rx <= l) return node();
        if (lx >= l && rx <= r) return seg[idx];

        int m = (lx + rx) >> 1;
        auto a = get(l, r, idx * 2 + 1, lx, m);
        auto b = get(l, r, idx * 2 + 2, m, rx);

        return merge(a, b);
    }

    node get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

};
int main() {
    K_K();
    int n, q; cin >> n >> q;
    segTree seg(n);
    while (q--) {
        int l, r, val; cin >> l >> r >> val;
        seg.set(l, r, val);
        cout << seg.get(0, n).val << endl;
    }
}
