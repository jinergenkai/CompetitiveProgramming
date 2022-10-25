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

int n, m, k;

void testcase() {
    cin >> n >> m >> k; 
    vector<vi> a(n + 7, vi(m + 7, 0));
    for (int i = 1; i <= k; i++) {
        int q,w,e,r; cin >> q >> w >> e >> r; q++, w++;
        a[q][w]++;
        a[q+e+1][w+r+1]++;
        a[q+e+1][w]--;
        a[q][w+r+1]--;
    }
    int sum = 0, mn = inf, mx = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            if (a[i][j] & 1) {
                sum++;
                mn = min(mn, (j-1)*(n+1) + i-1);
                mx = max(mx, (j-1)*(n+1) + i-1);
            }
			cout << a[i][j] << " \n"[j == m+1];
        }
    }
    if (sum==0) cout << "0 -1 -1\n";
    else {
        cout << sum << " " << mn << " " << mx << endl;
    }
}

int32_t main(int32_t argc, char *argv[]) { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        testcase();
}