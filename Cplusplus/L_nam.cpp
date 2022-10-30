#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 1000111;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;

string x, y, z;
int n, dp[2007][4];

int f(int pos, int cnt) {
    if (pos == 0 && cnt == 0) return 0;
    if (pos == 0 && cnt != 0) return inf;

    int& ans = dp[pos][cnt];
    if (ans + 1) return ans;
    ans = inf;

    int tmp = x[pos]-'0' + y[pos]-'0' + cnt;
    if (tmp%10 == int32_t(z[pos] - '0')) {
        ans = min(ans, f(pos-1, tmp/10));
    }
    ans = min(ans, f(pos - 1, cnt) + 1);
    return ans;
}

void testcase() {
    while(cin >> n) {
        if (n == 0) break;
        cin >> x >> y >> z; x = '@' + x, y = '@' + y, z = '@' + z;
        memset(dp, -1, sizeof dp);
        cout << f(n, 0) << endl;


    }
}

int32_t main() {
int t = 1; 
//cin >> t; 
while(t--) testcase();
}