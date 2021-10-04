#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
long long n, H;
long long a[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &H);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a + 1, a + 1 + n);

        long long cnt = H / (a[n] + a[n - 1]);
        long long ans = cnt * 2;
        H -= cnt * (a[n] + a[n - 1]);
        if (H > 0) {
            H -= a[n];
            ans++;
        }
        if (H > 0) {
            H -= a[n - 1];
            ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
