#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 10000007;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
void print() {return;}
void println() {cout << endl;return;}
template<typename T, typename... Args>
void print(T a, Args... args) {cout << a << " ";print(args...);}
template<typename T, typename... Args>
void println(T a, Args... args) {cout << a << " ";println(args...);}

bool prime[N];
vi primes;
  vector<bool> save(N, false);

void testcase(int test) {
  int n; cin >> n;
  // n = test;
  int count = 0;

  save.clear();

  for (int i = 0; i < primes.size(); i++) {
    int p = primes[i];
    if (p > n) break;
    // cout << "p: " << p << endl;

    for (int j = 0; j < i; j++) {
      int q = primes[j];
      if (prime[p - q] == false && save[p - q] != true) {
        count++;
        save[p - q] = true;
      }
    }
  }

  cout << count << endl;
  // cout << primes.size() << endl;
}

int32_t main() {
    // if(fopen("test.txt","r")) freopen("test.txt","r",stdin);
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("prime_subtractorization_validation_input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    prime[1] = true;
    prime[0] = true;
    for (int i = 2; i < N; i++) {
      if (!prime[i]) {
        for (int j = i*i; j < N; j += i) {
          prime[j] = true;
        }
      }
    }

    for (int i = 0; i < N; i++) 
      if (!prime[i])
        primes.push_back(i);

    int t = 1;
    cin >> t;
    int i = 1;
    while(t--) testcase(i++);

    // for (int i = 0; i < 100; i++) {
    //   testcase(i);
    // }
}
