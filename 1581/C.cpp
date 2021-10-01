#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 4e2 + 7;
const int mod = 1e9 + 7;
const long long INF = 9223372036854775807;

int T;
int n, m, ans;
int sum[maxn][maxn], f[maxn], a[maxn][maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%1d", &a[i][j]);
            }
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i][j - 1] + a[i][j];
            }
        }
        ans = mod;
        memset(f, 127, sizeof(f));
        for (int i = 1; i <= m; i++) {
            for (int j = i + 3; j <= m; j++) {
                int len = j - i - 1;
                int tot = 0;
                for (int k = 1; k <= n; k++) {
                    int cnt_1 = sum[k][j - 1] - sum[k][i];
                    if (k >= 5) {
                        ans = min(ans, len - cnt_1 + tot + f[k - 4]);
                    }
                    tot += cnt_1 + (a[k][i] == 0) + (a[k][j] == 0);
                    f[k] = min(f[k - 1], -tot + len - cnt_1);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

