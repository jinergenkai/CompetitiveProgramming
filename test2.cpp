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

int n, m, a[1007][1007];
int d[1007][1007];
int xx[] = {1, -1, 0, 0},
    yy[] = {0, 0, 1, -1};

int cc, ff;

void dfs(int u, int v) {
    
    for (int i = 0; i < 4; i++) {
        int new_x = u + xx[i];
        int new_y = v + yy[i];
        if (new_x < 1 || new_x > n || new_y < 1 || new_y > m) continue;
        if (d[new_x][new_y] == 1) continue;
        d[new_x][new_y] = 1;
        if (a[new_x][new_y] == 1) continue;
        if (a[new_x][new_y] == 2) cc++;
        if (a[new_x][new_y] == 3) ff++;

        dfs(new_x, new_y);
    }
}

void testcase() {
    
}

int32_t main() {
int t = 1; 
//cin >> t; 
while(t--) testcase();
}