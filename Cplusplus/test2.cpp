#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e9 + 7;
#define int long long
#define endl '\n'

string a, b;
ll dp[200111][2][2];
double trace[200111][2][2];

ll f(int pos, int l, int r) {

    if (pos == a.size()+1) {
        trace[pos][l][r] = 0;
        return 1;
    }

    ll &ans = dp[pos][l][r];
    double &tr = trace[pos][l][r];
    if (ans + 1) return ans;


    tr = -inf;

    int u = (l == true) ? a[pos-1] - '0' : 0;
    int v = (r == true) ? b[pos-1] - '0' : 9;

    for (int i = u; i <= v; i++) {
        ll tmp_f = f(pos + 1, i==u&&l, i==v&&r) * i % inf;

        double tmp_t = trace[pos + 1][i==u&&l][i==v&&r] + log2(i);
        if (i == 0) tmp_t = -inf;

        if (tr < tmp_t) {
            tr = tmp_t;
            ans = tmp_f;
        }
    }
    return ans;
}

int32_t main() {
    freopen("input.txt", "r",stdin);
    freopen("sai.txt", "w",stdout);
    cin >> a >> b;
    while(a.size() < b.size()) a = '0' + a;
    while(b.size() < a.size()) b = '0' + b;

    memset(dp, -1, sizeof dp);
    memset(trace, -inf, sizeof trace);
    // cout << b.size() << endl;
    int tmp = -inf, val = -inf;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            int k = f(1, i, j);
            if (val < trace[1][i][j]) {
                tmp = k;
                val = trace[1][i][j];
            }
        }
    }
    tmp = f(1, 1, 1);
    val = trace[1][1][1];

    if (tmp <= -1 || val <= 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << tmp << endl;
    // cout << 1 + log2(0) << " ";
}
