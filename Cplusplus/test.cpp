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
    int n, a, b; 
    cin >> n >> a >> b;
    if (a + b > n - 2) {
        if (a == b && b == n)
            println("Yes");
        else println("No");
        return;
    }
    println("Yes");
}

int32_t main() {
    if(fopen("test.txt","r")) freopen("test.txt","r",stdin);
    int t = 1; 
    cin >> t; 
    while(t--) testcase();
}
