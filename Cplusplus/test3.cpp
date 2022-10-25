#include <iostream>
using namespace std;

int cau1(int i) {
    return ((i==0) ? 0 : (cau1(i%10) + 1));
}

int32_t main(int32_t argc, char *argv[]) {
    int n; cin >> n;
    cout << n;
    cout << cau1(n);
}