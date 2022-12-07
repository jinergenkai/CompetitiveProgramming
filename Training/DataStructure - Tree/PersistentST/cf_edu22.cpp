// https://codeforces.com/problemset/problem/813/E
#include<bits/stdc++.h>
using namespace std;
 
struct point {
    point *l, *r;
    int sum = 0;
 
    point(int val): l(nullptr), r(nullptr), sum(val) {}
    point(point *l, point *r): l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
 
int n, k;
 
point* build(int l, int r) {
    if (l == r) return new point(0);
    int m = l + r >> 1;
    return new point(build(l, m), build(m+1, r));
}
 
point* update(point *v, int l, int r, int pos, int val) {
    if (l == r) return new point(min(v->sum + val, k));
    int m = l + r >> 1;
    if (pos <= m) return new point(update(v->l,l,m,pos, val), v->r);
    else return new point(v->l, update(v->r,m+1,r,pos, val));
}
 
int get(point* vertex, int l, int r, int u, int v) {
    if (u > r || l > v) return 0;
    if (u <= l && r <= v) return vertex->sum;
    int m = l + r >> 1;
    return get(vertex->l, l, m, u, v) + get(vertex->r, m+1, r, u, v);
}
 
int a[100011];
vector<point *> roots(100010, nullptr);
queue<int> backup[100010];
 
int main () {
    ios_base::sync_with_stdio();
    cin.tie (0);
    cout.tie (0);
    cin >> n >> k;
    int tl = 0, tr = 100010;
 
    roots[n+1] = (build(tl, tr));
 
 
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
 
    for (int i = n; i >= 1; i--) {
        backup[a[i]].push(i);
        roots[i] = (update(roots[i + 1], tl, tr, i, 1));
        if (backup[a[i]].size() > k)  {
            roots[i] = update(roots[i], tl, tr, backup[a[i]].front(), -1);
            backup[a[i]].pop();
            // cout << i << " ";
        }
    }
 
    int q; cin >> q;
    int last = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = ((l + last) % n) + 1;
        r = ((r + last) % n) + 1;
        if (l > r) swap(l, r);
        // cout << l << " " << r << endl;
        last = get(roots[l], tl, tr, l, r);
        cout << last << endl;
    }
}