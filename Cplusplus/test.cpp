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

void testcase() {
	int n; cin >> n;
	vi a(n + 7);
	for (int i = 1; i <= n; i++) {
		char x; cin >> x;
		a[i] = x - '0';
	}
	// if (n == 1 && a[1] == 1) {cout << 0 << endl;return;}
	a[0] = -1; a[n+1] = 1;
	int res = 0;
	bool first = false;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i-1] && first) res++;
		if (a[i] == 1) first = true;
	}
	cout << (res) << endl;

}

int32_t main(int32_t argc, char *argv[]) { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--) {
		testcase();
	}
}