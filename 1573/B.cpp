#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 2e5 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n;
int a[maxn], b[maxn];
int pos[maxn];
int suf[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            pos[b[i]] = i;
        }
        if (a[1] < b[1]) {
            printf("0\n");
            continue;
        }
        suf[2 * n + 1] = 1e9;
        for (int i = 2 * n; i >= 1; i--) {
            if (i % 2 == 0) {
                suf[i] = min(suf[i + 1], pos[i]);
            } else {
                suf[i] = suf[i + 1];
            }
        }
        int ans = 1e9;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, i - 1 + suf[a[i] + 1] - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}

