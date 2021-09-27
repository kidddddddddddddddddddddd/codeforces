#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 4e6 + 7;

int n, m;
long long dp[maxn], suffix[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    dp[n] = 1;
    suffix[n] = 1;
    for (long long i = n - 1; i >= 1; i--) {
        dp[i] = suffix[i + 1];
        for (long long j = 2; i * j <= n; j++) {
            long long sum = (suffix[i * j] - suffix[min(n + 1ll, (i+1)*j)] + m) % m;
            dp[i] = (dp[i] + sum) % m;
        }
        suffix[i] = (suffix[i + 1] + dp[i]) % m;
    }
    printf("%lld\n", dp[1]);
    return 0;
}


