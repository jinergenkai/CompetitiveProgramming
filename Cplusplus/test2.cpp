#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
// #define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 1000111;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;

const int maxk = 30;
int n, m, k;
int x[maxk], y[maxk], xx[maxk], yy[maxk];
int ans = 0;
int mx = 0, mn = inf;

long long calc(int i, int x1, int y1, int x2, int y2, int oper, int even) {
    if (i == k) {
        if (x1 > x2 || y1 > y2) return 0;
        if (even) ans += (x2 - x1 + 1) * (y2 - y1 + 1);
        else {
            mn = min(mn, y1 * (n + 1) + x1);
            mx = max(mx, y2 * (n + 1) + x2);
        }
        return oper * ((x2 - x1 + 1) * (y2 - y1 + 1)) * ((even & 1) ? 1 : 2);
    }
    long long res = calc(i + 1, x1, y1, x2, y2, oper, even);
    res += calc(i + 1, max(x1, x[i]), max(y1, y[i]), min(x2, x[i] + xx[i]), min(y2, y[i] + yy[i]), -oper, even + 1);
    return res;
}

void testcase() {
    cin >> n >> m >> k; 
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i] >> xx[i] >> yy[i];
    }
    cout << calc(0, 0, 0, n, m, -1, 0) + 2* ((n+1) * (m+1)) << " ";
    cout << mn << " " << mx << endl;
    // cout << ans;
}
int32_t main(int32_t argc, char *argv[]) { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    testcase();
}