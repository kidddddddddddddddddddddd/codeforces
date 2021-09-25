#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const int maxn = 5e3 + 7;
const int mod = 998244353;
const long long INF = 9223372036854775807;

int T;
int n;
int lcp[maxn][maxn], dp[maxn];
char s[maxn];

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            lcp[i][j] = 0;
        }
        dp[i] = 0;
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
        scanf("%s", s + 1);
        init();
        for (int i = n; i >= 1; i--) {
            for (int j = n; j >= 1; j--) {
                lcp[i][j] = (lcp[i + 1][j + 1] + 1) * (s[i] == s[j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = n - i + 1;
            for (int j = 1; j < i; j++) {
                if (s[i + lcp[i][j]] > s[j + lcp[i][j]]) {
                    dp[i] = max(dp[i], dp[j] + n - (i + lcp[i][j] - 1));
                }
            }
        }
        printf("%d\n", *max_element(dp + 1, dp + 1 + n));
    }
    return 0;
}

