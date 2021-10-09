#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int k;

long long poww(long long a, long long b, long long mod) {
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
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
#endif
    scanf("%d", &k);
    long long total = poww(2, k, INF) - 2;
    long long ans = 6ll * poww(4, total, mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
