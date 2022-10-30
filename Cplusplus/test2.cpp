#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 1000111;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;

string a, b;
int dp[100011][4][4];
double save[100011][4][4];
 
int f(int pos, int l, int r) { 
    if (pos == a.size()+1) {
        save[pos][l][r] = 0;
        return 1;
    } 
 
    int &ans = dp[pos][l][r];
    double &val = save[pos][l][r];

    if (ans + 1) return ans;
 
    
    ans = 0;
    val = 0;

    int u = (l == true) ? a[pos-1] - '0' : 1;
    int v = (r == true) ? b[pos-1] - '0' : 9;
 
    for (int i = u; i <= v; i++) {
        int newa = f(pos+1, i==u&&l, i==v&&r) * i % inf;
        double newb = save[pos+1][i==u&&l][i==v&&r] + log2(double(i));
        // cout << newb << endl;

        if (newb > val) {
            ans = newa;
            val = newb;
        }
        // ans = max(ans, f(pos+1, i==u&&l, i==v&&r) *i);
    }
    return ans;
}

 
int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    while(a.size() < b.size()) a = '0' + a;
    while(a.size() > b.size()) b = '0' + b;
    // cout << a << " " << b;
    memset(dp, -1, sizeof dp);
    cout << f(1, 1, 1) % inf;
}