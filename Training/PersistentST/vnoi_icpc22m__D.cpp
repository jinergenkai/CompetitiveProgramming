//https://oj.vnoi.info/problem/icpc22_mt_d

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

point* build(int l, int r) {
    if (l == r) return new point(0);
    int m = l + r >> 1;
    return new point(build(l, m), build(m+1, r));
}

point* update(point *v, int l, int r, int pos) {
    if (l == r) return new point(v->sum + 1);
    int m = l + r >> 1;
    if (pos <= m) return new point(update(v->l,l,m,pos), v->r);
    else return new point(v->l, update(v->r,m+1,r,pos));
}

int get(point* vl, point* vr, int l, int r, int k) {
    if (l == r) return l;
    int m = l + r >> 1, count = vr->l->sum - vl->l->sum;
    if (k <= count) return get(vl->l, vr->l, l, m, k);
    else return get(vl->r, vr->r, m+1, r, k - count);
}

vector<point*> roots;
int n, q;

int main () {
    ios_base::sync_with_stdio();
    cin.tie (0);
    cout.tie (0);
    cin >> n >> q;
    int tl = 0, tr = 100010;
    roots.push_back(build(tl, tr));
    for (int i = 1; i <= n; ++ i) {
        int a;
        cin >> a;
        roots.push_back(update(roots.back(), tl, tr, a));
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get(roots[l-1], roots[r], tl, tr, (r - l + 2)/ 2) << endl;
    }
}