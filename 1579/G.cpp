#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 1e4 + 7;
const int maxm = 2e3 + 7;

int T;
int n;
int a[maxn];
int dp[maxn][maxm];

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 2000; j++) {
            dp[i][j] = 1e9;
        }
    }
}

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
        init();
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int l = 0; l <= 2000; l++) {
                if (dp[i][l] == 1e9) {
                    continue;
                }
                dp[i + 1][max(0, l - a[i + 1])] = min(dp[i + 1][max(0, l - a[i + 1])], dp[i][l] + a[i + 1]);
                if (l + a[i + 1] <= 2000) {
                    dp[i + 1][l + a[i + 1]] = min(dp[i + 1][max(0, l - a[i + 1])], max(0, dp[i][l] - a[i + 1]));
                }
            }
        }
        int ans = 1e9;
        for (int l = 0; l <= 2000; l++) {
            ans = min(ans, dp[n][l] + l);
        }
        printf("%d\n", ans);

    }
    return 0;
}


