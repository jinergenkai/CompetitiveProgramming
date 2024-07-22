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

void testcase() {
  int n; cin >> n;

  int pow2 = 0;
  while((1 << pow2)-2 <= n) pow2++;
  pow2--;

  cout << pow2 << endl;

  if (pow2 == 1) {
    cout << 1 << endl;
    return;
  }
  vector<int> ans = {1, 2};
  vector<int> nxt;
  int mul = 4;

  for (int i = 3; i <= pow2; i++, mul *= 2) {
    for (int j = 0; j < ans.size(); j++) {
      nxt.push_back(ans[j] + mul);
    }
    nxt.push_back(mul-1);

    ans = nxt;
    nxt.clear();
  }

  sort(ans.begin(), ans.end());

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;


}

int32_t main() {
    if(fopen("test.txt","r")) freopen("test.txt","r",stdin);
    int t = 1;
    cin >> t;
    while(t--) testcase();
}
