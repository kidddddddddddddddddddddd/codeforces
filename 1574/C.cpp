#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int n, m;
long long a[maxn];
long long pre[maxn];
long long x, y;

long long solve(int pos) {
    if (pos < 1) {
        pos = 1;
    }
    if (pos > n) {
        pos = n;
    }
    return max(x - a[pos], 0ll) + max(y - (pre[n] - pre[pos] + pre[pos - 1]), 0ll);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%lld%lld", &x, &y);
        int pos = lower_bound(a + 1, a + 1 + n, x) - a;
        printf("%lld\n", min(solve(pos), solve(pos - 1)));
    }
    return 0;
}

