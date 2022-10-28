#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 1000111;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;

bool d[100];
int n;

bool check(int x, int k) {
    int cnt = 0;
    while(x) {
        if (d[x%10] == false) return false;
        cnt++;
        x /= 10;
    }
    return cnt == k;
}
 
 int res = 0;

void back(int first, int second) {
    if (100 <= first && first <= 999) {
        if (10 <= second && second <= 99) {
            if (check(first * second, 4) && check(first * (second%10), 3) && check(first * (second/10), 3)) {
                res ++;
                // cout << first * second << endl;
            }
            return;
        }
        for (int i = 1; i <= 9; i++) {
            if (d[i] == false) continue;
            back(first, second * 10 + i);
        }
    }
    else {
        for (int i = 1; i <= 9; i++) {
            if (d[i] == false) continue;
            back(first * 10 + i, second);
        }
    }
}

void testcase() {
     cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        // cout << x << " ";
        d[x] = true;
    }
    back(0, 0);
    cout << res ;
}

int32_t main(int32_t argc, char *argv[]) { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cout << 1;
    testcase();
}