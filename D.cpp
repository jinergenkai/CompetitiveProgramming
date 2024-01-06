#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
// #define int long long
#define all(x) x.begin(),x.end()

const int inf = 1e9 + 7; const int N = 1000111;
typedef pair<int, int> pii; typedef vector<int> vi; typedef long long ll;
struct cc {
	int cnt;
	string value;
	int size;
	int id;
};
int xx[] = {3, 0, -1, -2};

int point(string x) {
	int res = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] >= '0' && x[i] <= '9') {
			res += x[i] - '0';
		}
	}
	if (x.find("0:0") != string::npos) {
		res += 13;
	}
	return res;
}

void testcase() {
   string a,b,c,d;
   getline(cin,a);
   getline(cin,b);
   getline(cin,c);
   getline(cin,d);
   
   vector<cc> p;
   
   if (a.size() == 0) a = "0";
   if (b.size() == 0) b = "0";
   if (c.size() == 0) c = "0";
   if (d.size() == 0) d = "0";

   p.push_back({point(a), a, (int32_t)a.size(), 0});
   p.push_back({point(b), b,(int32_t) b.size(), 1});
   p.push_back({point(c), c,(int32_t) c.size(), 2});
   p.push_back({point(d), d,(int32_t) d.size(), 3});

   sort(all(p), [](cc x, cc y) {
   	if (x.cnt == y.cnt) {
   		return x.size < y.size;
   	}
   	return x.cnt < y.cnt;
   });

   vector<int> res(5,0);
   for (int i = 0; i < 4; i++) {
   	res[p[i].id] = xx[i];
   }
   for (int i = 0; i < 4; i++)
   {
	   if (p[i].value.find("0:0") != string::npos) {
			res[p[i].id] -= 13;
		   res[p[0].id] += 13;
	   }
   }


   for (int i = 0; i < 4; i++) {
   	cout << res[i] << endl;
   }
}

int32_t main(int32_t argc, char *argv[]) { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	testcase();
}