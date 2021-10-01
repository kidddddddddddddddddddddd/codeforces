#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
int n;
long long fac[maxn];

long long poww(long long a, long long b) {
    long long res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        printf("%lld\n", fac[n * 2] * poww(2, mod - 2) % mod);
    }
    return 0;
}

