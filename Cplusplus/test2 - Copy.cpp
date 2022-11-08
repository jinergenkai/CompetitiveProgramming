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

void testcase() {
	string s; cin >> s;
	int n = s.size();
	vi sumall(n, 0);
	vi sum1(n, 0);
	for (int i = 0; i < n; i++) {
		sumall[i] = (i+1) * (n-i);
		// cout << sumall[i] << " ";
		sum1[i] = (s[i] == '1' ? sumall[i]: 0);
	}

	for (int i = 1; i < n; i++) {
		sum1[i] += sum1[i-1];
		sumall[i] += sumall[i-1];
	}

	int mn = 0, res = sum1[n-1];
	for (int i = 0; i < n; i++) {
		res = max(res, sumall[i] - sum1[i] - mn + sum1[n-1]-sum1[i]);
		mn = min(mn, sumall[i] - sum1[i] - sum1[i]);
	}
	cout << res << endl;

	

}

int32_t main() {
int t = 1; 
cin >> t; 
while(t--) testcase();
}