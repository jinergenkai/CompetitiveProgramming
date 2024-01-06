#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e17 + 7; const int N = 1000111;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;

int n, m, a[104][104];
int xx[] = {0, 1, -1, 0},
	yy[] = {1, 0, 0, -1};
int d[104][104], cc[104][104];

int bfs(int u, int v) {
	// cout << a[u][v] << endl;
	for (int i = 0; i <= n + 1; i++)
	for (int j = 0; j <= m + 1; j++)
		d[i][j] = 0;
	d[u][v] = 1;
	queue<pii> q;
	q.push({u, v});
	int mx = inf;
	int cnt = 1;
	while(!q.empty()) {
		pii t = q.front(); q.pop();
		int x = t.fi, y = t.se;
		if (x == 0 || x == n + 1 || y == 0 || y == m + 1) {
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + xx[i], ny = y + yy[i];
			if (nx < 0 || nx > n+1 || ny < 0 || ny > m+1) continue;
			if (d[nx][ny]) continue;
			if (a[nx][ny] > a[u][v]) {
				mx = min(mx, a[nx][ny]);
				continue;
			}
			d[nx][ny] = 1;
			cnt++;
			q.push({nx, ny});
		}
	}

	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++) {
			if (i==0 || j==0 || i==n+1 || j==m+1) {
				if (d[i][j]) return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == a[u][v] && d[i][j] == 1) {
				cc[i][j] = true;
			}
		}
	}
	return (mx - a[u][v]) * cnt;
	// return d[u][v];
	// cout << a[u][v] << " " << mx << endl;
	// return mx - a[u][v];

}

void testcase() {
	cin >> n >> m;
	int res = 0;
	vector<pair<int, pii>> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			// if (a[i][j] < 0) {
			// 	res+= -a[i][j];
			// 	a[i][j] = 0;
			// }
			t.push_back({a[i][j], {i, j}});
		}
	}
	sort(all(t));

	for (auto c : t) {
		int i = c.se.fi, j = c.se.se;
			if (cc[i][j]) continue;
			res += bfs(i, j);
			// cout << bfs(i, j) << " ";
		}
	cout << res;
}

int32_t main(int32_t argc, char *argv[]) { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		testcase();
}