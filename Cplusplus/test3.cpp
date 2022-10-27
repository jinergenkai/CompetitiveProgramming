//https://lqdoj.edu.vn/problem/nothighestelement
//nqhoang11_cukuin
//tao@gmail.com

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define endl '\n'

const int inf = 1e17 + 7;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAX_N = 4000111;

int a[MAX_N], b[MAX_N], dp[MAX_N], n;
pair<int, pii> cost[MAX_N];

int version[MAX_N], nodemax[2][MAX_N], nodedp[MAX_N], noderes[2][MAX_N];
int lazy[2][MAX_N];
bool Lock[MAX_N];
int trans[MAX_N], inver[MAX_N];

int maxb(int id1, int id2) {
	if (b[id1] > b[id2]) return id1;
	return id2;
}

void update(int k) {
	int& ver = version[k];
	int& ver1 = version[2 * k + 0];
	int& ver2 = version[2 * k + 1];

	nodemax[ver][k] = maxb(nodemax[ver1][2 * k], nodemax[ver2][2 * k + 1]);
	noderes[ver][k] = max(noderes[ver1][2 * k], noderes[ver2][2 * k + 1]);

	nodemax[ver^1][k] = maxb(nodemax[ver1^1][2 * k], nodemax[ver2^1][2 * k + 1]);
	noderes[ver^1][k] = max(noderes[ver1^1][2 * k], noderes[ver2^1][2 * k + 1]);

	nodedp[k] = max(nodedp[2 * k], nodedp[2 * k + 1]);
}

void build(int k, int l, int r) {
	int& ver = version[k];

	if (l > r) return;
	if (l == r) {
		Lock[k] = 0;
		trans[k] = 0;
		inver[k] = 0;
		ver = 1;
		nodemax[1][k] = nodemax[0][k] = 0;
		noderes[1][k] = noderes[0][k] = -inf;
		nodedp[k] = -inf;
		return;
	}
	int mid = l + r >> 1;
	build(2 * k + 0, l, mid + 0);
	build(2 * k + 1, mid + 1, r);

	Lock[k] = 0;
	trans[k] = 0;
	inver[k] = 0;
	ver = 1;
	nodemax[1][k] = nodemax[0][k] = 0;
	lazy[1][k] = lazy[0][k] = 0;
	noderes[1][k] = noderes[0][k] = -inf;
	nodedp[k] = -inf;
}

void down(int k) {
	int& ver = version[k];
	int& ver1 = version[2 * k + 0];
	int& ver2 = version[2 * k + 1];
	
	int x = 2 * k + 0;
	int y = 2 * k + 1;

	if (trans[k] + inver[k] >= 2) {
		Lock[k] = true;
		return;
	}

	if (trans[k]) {
		int& val = lazy[ver][k];

		if (trans[k] < 2) {
			ver1 ^= 1;
			ver2 ^= 1;
		}
		
		lazy[ver1][x] = val;
		nodemax[ver1][x] = val;
		noderes[ver1][x] = nodedp[x] + a[val];

		lazy[ver2][y] = val;
		nodemax[ver2][y] = val;
		noderes[ver2][y] = nodedp[y] + a[val];

		val = 0; lazy[ver^1][k] = 0;
		trans[x] += trans[k];
		trans[y] += trans[k];
		trans[k] = 0;
	}
	
	if (inver[k] || trans[k] > 1) {
		int& val = lazy[ver^1][k];

		lazy[ver1^1][x] = val;
		nodemax[ver1^1][x] = val;
		noderes[ver1^1][x] = nodedp[x] + a[val];

		lazy[ver2^1][y] = val;
		nodemax[ver2^1][y] = val;
		noderes[ver2^1][y] = nodedp[y] + a[val];

		val = 0; lazy[ver][k] = 0;
		inver[x] = inver[k];
		inver[y] = inver[k];
		inver[k] = 0;

	}


}
////////////////////////////////////////////////////////////////////
void upleft(int k, int l, int r, int u, int v, int val) {
	int& ver = version[k];

	if (l > v || u > r) return;
	if (u <= l && r <= v) {
		inver[k] = 1;
		lazy[ver^1][k] = val;
		nodemax[ver^1][k] = val;
		noderes[ver^1][k] = nodedp[k] + a[val];	
		return;
	}
	down(k);
	// if(Lock[k]) return;

	int mid = l + r >> 1;
	upleft(2 * k + 0, l, mid + 0, u, v, val);
	upleft(2 * k + 1, mid + 1, r, u, v, val);
	update(k);
}

void upright(int k, int l, int r, int u, int v, int val) {
	int& ver = version[k];
	
	if (l > v || u > r) return;
	if (u <= l && r <= v) {
		trans[k]++;
		ver ^= 1;
		lazy[ver][k] = val;
		nodemax[ver][k] = val;
		noderes[ver][k] = nodedp[k] + a[val];
		return;
	}
	down(k);
	// if (Lock[k]) return;

	int mid = l + r >> 1;
	upright(2 * k + 0, l, mid + 0, u, v, val);
	upright(2 * k + 1, mid + 1, r, u, v, val);

	update(k);
}

int get(int k, int l, int r, int u, int v) {
	if (l > v || u > r) return -inf;
	if (u <= l && r <= v) return noderes[version[k]^1][k];
	down(k);
	int mid = l + r >> 1;
	return max(get(2*k,l,mid,u,v),get(2*k+1,mid+1,r,u,v));
}


////////////////////////////////////////////////////////////////////////////

void upele(int k, int l, int r, int pos, int valdp, int valmax) {
	int& ver = version[k];

	if (l > pos || pos > r) return;
	if (l == r) {
		nodemax[ver][k] = valmax;
		nodemax[ver^1][k] = n + 2;
		nodedp[k] = valdp;
		noderes[ver][k] = a[nodemax[ver][k]] + valdp;
		noderes[ver^1][k] = a[nodemax[ver^1][k]] + valdp;
		return;
	}
	down(k);
	int mid = l + r >> 1;
	upele(2 * k + 0, l, mid + 0, pos, valdp, valmax);
	upele(2 * k + 1, mid + 1, r, pos, valdp, valmax);

	update(k);
}

/// b[minRR[k]]
int upSame(int k, int l, int r, int upper, int val, bool lft) {
	int& ver = version[k];
	int& ver1 = version[2 * k + 0];
	int& ver2 = version[2 * k + 1];
	
	int x = 2 * k + 0;
	int y = 2 * k + 1;

	if (l >= upper) return n + 1;
	if (l > r) return n + 1;
	if (nodemax[ver^lft][k] == 0) return n + 1;

	if (b[nodemax[ver^lft][k]] <= b[val] && r < upper) {
		// cout << "@ " << b[nodemax[ver^lft][k]] << " " << b[val] << endl;
		// cout << "@ " << ver << " " << k << endl;
		return l;
	}
	// if (l == r) return l;


	down(k);
	if (Lock[k]) return n + 1;

	int mid = l + r >> 1;
	if (b[nodemax[ver2^lft][y]] <= b[val]) {
		// if (Lock[x]) return l;
		return min(upSame(x, l, mid, upper, val, lft), mid + 1);
	}
	return upSame(y, mid + 1, r, upper, val, lft);
}

// int trai, phai, giua, id;
// int binary(int k, int l, int r, int val, bool lft) {
// 	int& ver = version[k];

// 	if (l > pos || pos > r) return;
// 	if (l == r) {
// 		id = nodemax[ver^lft][k];
// 		if (b[id] <= b[val])
// 		return;
// 	}
// }

int id;
void getele(int k, int l, int r, int pos, bool lft) {
	int& ver = version[k];

	if (l > pos || pos > r) return;
	if (l == r) {
		id = nodemax[ver^lft][k];
		return;
	}
	down(k);
	if(Lock[k]) {
		id = nodemax[ver^lft][k];
		return;
	}
	int mid = l + r >> 1;
	getele(2 * k + 0, l, mid + 0, pos, lft);
	getele(2 * k + 1, mid + 1, r, pos, lft);
	update(k);
}
int getpos(int pos, bool lft) {
	id = n + 1;
	getele(1, 1, n, pos, lft);
	return id;
}

///////////////////////////////////////////////////////////////////

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	// n = 100000;
	// for (int i = 1; i <= n; i++) a[i] = i;
	// for (int i = 1; i <= n; i++) b[i] = i;

	b[0] = a[0] = -inf;
	b[n+1] = a[n+1] = inf;
	b[n+2] = a[n+2] = -inf/2;

	build(1, 1, n);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		// cost[i] = {dp[i-1], {0, i}};
		upele(1, 1, n, i, dp[i-1], i);
		
		dp[i] = -inf;
		int l = i, r = i;
		
		// for (int c = 1; c <= n; c++) {
		// 	cout << b[getpos(c, true)] << " " << b[getpos(c, false)] << endl;
		// }
		r = upSame(1, 1, n, i, i, false);
		l = upSame(1, 1, n, r, i, true);
		
	
		// if (i == n)
		// 	for (int j = 1; j < i; j++) {
		// 		getpos(j, true);
		// 		getpos(j, false);
		// 	}

		// cout << l << " " << r << endl;
		if (l < i && l < r)
		upleft(1, 1, n, l, r-1, i);

		if (r < i)
		upright(1, 1, n, r, i-1, i);

		if(i != 1)
		// dp[i] = noderes[version[1]^1][1];
		dp[i] = get(1,1,n,1,i-1);
		
	}

	cout << dp[n] << " ";
}

/*


		int trai, phai, giua;
		
		trai = 1, phai = i - 1;
		while (trai <= phai) {
			giua = trai + phai >> 1;
			if (giua < 1 || giua > i - 1) break;
			if (b[getpos(giua, false)] <= b[i]) {
				phai = giua - 1;
				r = min(r, giua);
			}
			else trai = giua + 1;
		}
		

		trai = 1, phai = i - 1;
		while (trai <= phai) {
			giua = trai + phai >> 1;
			if (giua < 1 || giua > i - 1) break;
			if (b[getpos(giua, true)] <= b[i]) {
				phai = giua - 1;
				l = min(l, giua);
			}
			else trai = giua + 1;
		}

*/
