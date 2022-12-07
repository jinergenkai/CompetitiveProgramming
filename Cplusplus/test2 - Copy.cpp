#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 1000111;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
void print() {cout << endl;return;}
template<typename T, typename... Args>
void print(T a, Args... args) {cout << a << " ";print(args...);}

int node[8000111], sum[8000111], a[1000111], n, q;
int b[1000111];

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int d = 0;
    while(q--) {
        int x; cin >> x;
        if (x == 1) {
            int y; cin >> y;
			d += y;
			d %= n;
        }
        if (x == 2) {
            int y, z, val; cin >> y >> z >> val; y--, z--;

			int l = (y - d + n) % n + 1;
			int r = (z - d + n) % n + 1;

			if (l > r) {
				bool ok =false;
				int tmp1 = *min_element(a + l, a + n + 1);
				int tmp2 = *min_element(a + 1, a + r + 1);
				int tmp = min(tmp1, tmp2);
				for (int i = l; i <= n; i++) {
					if (a[i] == tmp) {
						a[i] = val;
						ok = true;
						break;
					}
				}
				if (!ok) {
					for (int i = 1; i <= r; i++) {
						if (a[i] == tmp) {
							a[i] = val;
							break;
						}
					}
				}
			}
			else {
				int tmp = *min_element(a + l, a + r + 1);
				for (int i = l; i <= r; i++) {
					if (a[i] == tmp) {
						a[i] = val;
						break;
					}
				}
			}

        }
        if (x == 3) {
            int y, z; cin >> y >> z; y--, z--;
			int l = (y - d + n) % n + 1;
			int r = (z - d + n) % n + 1;
			if (l > r) {
				int res =0;
				for (int i = l; i <= n; i++) {
					res += a[i];
				}
				for (int i = 1; i <= r; i++) {
					res += a[i];
				}
				print(res);
			}
			else {
				int res = 0;
				for (int i = l; i <= r; i++) {
					res += a[i];
					// cout << a[i] << " ";
				}
				print(res);
			}
        }
    }

}

int32_t main() {
int t = 1; 
// cin >> t; 
while(t--) testcase();
}