#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 200011;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
void print() {return;}
void println() {cout << endl;return;}
template<typename T, typename... Args>
void print(T a, Args... args) {cout << a << " ";print(args...);}
template<typename T, typename... Args>
void println(T a, Args... args) {cout << a << " ";println(args...);}

int back(vi a, int i, int n, int sum, int two, int one) {
    while(i <= n && a[i] < sum)
        sum += a[i++]/2;
    
    if (i == n+1) return n;
    return max(two == 0 ? i-1: back(a, i, n, sum * 2, two-1, one),
                    one == 0 ? i-1: back(a, i, n, sum * 3, two, one-1));
    nguyen manh hung
        day la ban sao thu 2
}

void testcase() {
    int n, start; cin >> n >> start;
    vi a(n + 1, 0);

    int sum = start, cnt = 0, two = 0, one = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(next(a.begin()), a.end());
    println(back(a, 1, n, start, 2, 1));
}

int32_t main() {
    if(fopen("test.txt","r")) freopen("test.txt","r",stdin);
    int t = 1; 
    cin >> t; 
    while(t--) testcase();
}
