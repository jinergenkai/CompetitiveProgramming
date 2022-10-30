#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 1000111;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;

map<pii, bool> m;

bool back(int x, int y) {
	cout << x << " " << y << endl;
	if (m[{x,y}] == true) {return true;}
	m[{x,y}] = true;
	if ((x&1) && (y&1)) return false;

	bool ans = 0;
	if (x%2==0) ans|=back(x/2, y + x/2);
	if (y%2==0) ans|=back(x + y/2, y/2);
	return ans;
}

void testcase() {
	// cout << back(7, 7) << " ";
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if ((i&1) && (j&1==0)) {

			}
		}
	}
	int n; cin >> n;
	// if (n == 1) {
	// 	cout << "0\n0\n1";
	// 	return;
	// }

	int odd = n/2 + (n&1);
	int even = n/2;

	int draw = odd*even * 2;

	cout << even*even << "\n" << draw << "\n" << odd*odd;
}

int32_t main() {
int t = 1; 
//cin >> t; 
while(t--) testcase();
}