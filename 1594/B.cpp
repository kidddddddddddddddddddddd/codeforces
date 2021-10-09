#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
long long n, k;

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

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        long long ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans + (k & 1) * poww(n, i)) % mod;
            k >>= 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
