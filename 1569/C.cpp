#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n;
map<int, int> mp;
long long fac[maxn];

void init() {
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}

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
    init();
    scanf("%d", &T);
    while (T--) {
        mp.clear();
        scanf("%d", &n);
        for (int i = 1, x; i <= n; i++) {
            scanf("%d", &x);
            mp[x]++;
        }
        if (mp.rbegin()->second > 1) {
            printf("%lld\n", fac[n]);
        } else if (mp.rbegin()->first - (++mp.rbegin())->first > 1) {
            printf("0\n");
        } else {
            int m = (++mp.rbegin())->second;
            printf("%lld\n", m * poww(m + 1, mod - 2) % mod * fac[n] % mod);
        }
    }
    return 0;
}

